#include "JsonVisitor.h"
#include "IR.h"
#include "IRPrinter.h"
#include "IRMutator.h"
#include "JsonAbsiVisitor.h"
#include "JsonParser.h"
#include "Generator.h"

int main(int argc, char** argv)
{
	generate(argv[1]);
	return 0;
}