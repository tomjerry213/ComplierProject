#include "JsonParser.h"

JsonParser js;

int main(int argc, char** argv) {
    if (argc == 1)
        js.loadJson("../project1/cases/case1.json");
    else 
        js.loadJson(argv[1]);
    std::cout << js.kernel << std::endl;
    js.parseKernel();
    js.printKernel();
}