#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "JsonExpression.h"
#include "JsonVisitor.h"

class JsonParser {
 public:
    P p;
    int data_type; // 0:Int 1:Float
    std::string kernelName;
    std::string kernel;
    std::unordered_map<std::string, ValId*> vals;
    std::unordered_map<std::string, IterId*> iters;    
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::set<std::string> grads;
    std::stack<void *> parseStack;
    std::stack<std::string> typeStack;
    std::stack<char> symbolStack;
    std::stack<char> symStack;

    std::map<std::string, std::vector<size_t> > valSize;
    std::map<std::string, int> inout;
    std::map<std::string, int> inInput;

    RHS* getRHS(RHS* p1, char p2, RHS* p3) {
        Expression* exp;
        if (p2 == '+') 
            exp = new AddExpression(p1, p3);
        else if (p2 == '-')
            exp = new SubExpression(p1, p3);
        else if (p2 == '*')
            exp = new MulExpression(p1, p3);
        else if (p2 == '%')
            exp = new ModExpression(p1, p3);
        else if (p2 == '/' && !data_type)
            exp = new DivExpression(p1, p3);
        else exp = new ChuExpression(p1, p3);
        return new RHS(exp);
    }

    IdExpr* getIdExpr(IdExpr* p1, char p2, IntV* p3) {
        IdExpression* exp;
        if (p2 == '+') exp = new IdIntAddExpression(p1, p3);
        if (p2 == '*') exp = new IdIntMulExpression(p1, p3);
        if (p2 == '/') exp = new IdIntDivExpression(p1, p3);
        if (p2 == '%') exp = new IdIntModExpression(p1, p3);
        return new IdExpr(exp);
    }

    int getPriority(char p1) {
        if (p1 == '+' || p1 == '-') return 1;
        if (p1 == '*' || p1 == '/' || p1 == '%') return 2;
        if (p1 == '(') return -1;
        return 0;
    }

    void loadJson(char* fileName);
    void parseKernel();
    void printKernel();
};

#endif //JSONPARSER_H