#include "JsonVisitor.h"
#include "IR.h"
#include "IRPrinter.h"
#include "IRMutator.h"
#include "JsonAbsiVisitor.h"
#include "JsonParser.h"
#include "Generator.h"

std::string generate(char* argv) {
	JsonParser x;
	x.loadJson(argv);
	x.parseKernel();
	Type type;
	if (x.data_type == 0)
	{
		type = Type::int_scalar(32);
	}
	else
	{
		type = Type::float_scalar(32);
	}
	//JsonVisitor* v = new JsonVisitor();
	//x.p.accept(v);
	JsonAbsiVisitor* visitor = new JsonAbsiVisitor(); 
	visitor->parser = &x;
	Stmt t = x.p.accept(visitor, type);
	Group kernel = Kernel::make(x.kernelName, {}, {}, {t}, KernelType::CPU);
	IRMutator mutator;
	kernel = mutator.mutate(kernel);
	IRPrinter printer;
	std::string vars;
	std::string typ = x.data_type?"float ": "int ";
    int tag = 0;
	for (int i = 0; i < x.inputs.size(); i++) {
        if (x.inout[x.inputs[i]] || x.inInput[x.inputs[i]] != 1) continue;
		if (tag) vars = vars + ", "; else tag = 1;
		if (x.valSize[x.inputs[i]].size() == 0)
			vars = vars + typ + "&" + x.inputs[i];
		else {
			vars = vars + typ + "(&" + x.inputs[i] +")";
			for (auto j : x.valSize[x.inputs[i]]) {
				vars =  vars + "[" + std::to_string(j) + "]";
			}
		}
        x.inout[x.inputs[i]] = 1;
	}
	for (int i = 0; i < x.outputs.size(); i++) {
        if (x.inout[x.outputs[i]]) continue;
		if (tag) vars = vars + ", "; else tag = 1;
		if (x.valSize[x.outputs[i]].size() == 0)
			vars = vars + typ + "&" + x.outputs[i];
		else {
			vars = vars + typ + "(&d" + x.outputs[i] +")";
			for (auto j : x.valSize[x.outputs[i]]) {
				vars =  vars + "[" + std::to_string(j) + "]";
			}
		}
        x.inout[x.outputs[i]] = 1;
	}
	for (auto name : x.grads) {
		if (tag) vars = vars + ", "; else tag = 1;
		vars = vars + typ + "(&d" + name + ")";
		for (auto j : x.valSize[name])
			vars = vars + "[" + std::to_string(j) + "]";
	}
	vars = "#include \"../run2.h\"\n\nvoid " + x.kernelName + "(" + vars + ") {\n" +  printer.print(kernel) + "}\n" ;
    //delete &x.p;
	return vars;
	//return 0;
}