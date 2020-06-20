#include "JsonVisitor.h"
#include "IR.h"
#include "IRPrinter.h"
#include "IRMutator.h"
#include "JsonAbsiVisitor.h"
#include "JsonParser.h"
#include "Generator.h"

int main(int argc, char** argv)
{
	std::cout << generate(argv[1]) << std::endl;
	return 0;
}