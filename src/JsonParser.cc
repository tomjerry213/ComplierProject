#include "JsonParser.h"

void JsonParser::loadJson(char * fileName) {
    freopen(fileName, "r", stdin);
    std::string str;
    std::getline(std::cin, str);
    std::getline(std::cin, str);
    int l = str.size(), pos;
    for (int i = 0; i < l; i++) 
        if (str[i] == ':') {
            pos = i + 3;
            break;
        }
    for (; str[pos] != '"'; pos++)
        kernelName = kernelName + str[pos];
    
    std::getline(std::cin, str);
    l = str.size();
    for (int i = 0; i < l; i++)
        if(str[i] == '[') {
            pos = i + 1;
            break;
        }
    int flag = 0;
    std::string valName = "";
    for (; str[pos] != ']'; pos++) {
        if (str[pos] == '"') {
            if (flag == 0) flag = 1;
            else {
                inputs.push_back(valName);
                flag = 0;
                valName = "";
            }
        }
        else if (flag) valName = valName + str[pos];
    }

    std::getline(std::cin, str);
    l = str.size();
    for (int i = 0; i < l; i++)
        if(str[i] == '[') {
            pos = i + 1;
            break;
        }
    flag = 0;
    valName = "";
    for (; str[pos] != ']'; pos++) {
        if (str[pos] == '"') {
            if (flag == 0) flag = 1;
            else {
                outputs.push_back(valName);
                flag = 0;
                valName = "";
            }
        }
        else if (flag) valName = valName + str[pos];
    }

    std::getline(std::cin, str);
    l = str.size();
    for (int i = 0; i < l; i++)
        if(str[i] == ':') {
            pos = i + 3;
            break;
        }
    //std::cout << str[pos] << std::endl;
    if (str[pos] == 'f') data_type = 1;
    else data_type = 0;

    std::getline(std::cin, str);
    l = str.size();
    for (int i = 0; i < l; i++) 
        if (str[i] == ':') {
            pos = i + 3;
            break;
        }
    for (; str[pos] != '"'; pos++)
        kernel = kernel + str[pos];

    freopen("/dev/tty", "r", stdin);
}

void JsonParser::parseKernel() {
    int l = kernel.size();
    int flag = 0, now = 0, nowRef = -1;
    std::string nowStr = "";
    for (int i = 0; i < l; i++) {
        //std::cout << i << ' ' << kernel[i] << ' ' << nowStr << ' ' << now << ' ' << nowRef << ' ' << flag << std::endl;
        if(kernel[i] == ' ') continue;
        if (kernel[i] == '.' || isdigit(kernel[i]) || isupper(kernel[i]) || islower(kernel[i])) {
            if(!flag)
                if ((kernel[i] >= 'A' && kernel[i] <= 'Z') || (kernel[i] >= 'a' && kernel[i] <= 'z'))
                    flag = 1, now = 0, nowStr = "", nowStr = nowStr + kernel[i];
                else if (kernel[i] >= '0' && kernel[i] <= '9' && (!data_type || nowRef == 2))
                    flag = 1, now = 1, nowStr = "", nowStr = nowStr + kernel[i];
                else flag = 1, now = 2, nowStr = "", nowStr = nowStr + kernel[i];
            else
                nowStr = nowStr + kernel[i];
        }
        else if (nowRef != 2) {
            if (kernel[i] == '<') {
                ValId* valid;
                if(vals.find(nowStr) == vals.end()) {
                    valid = new ValId(nowStr);
                    vals[nowStr] =valid;
                }
                else valid = vals[nowStr];
                parseStack.push((void *)valid);
                typeStack.push("ValId");
                flag = 0;
                nowRef = 1;
            }
            else if (kernel[i] == ',') {
                IntV* intv = new IntV(nowStr);
                parseStack.push((void *)intv);
                typeStack.push("IntV");
                flag = 0;
            }
            else if (kernel[i] == '>') {
                IntV* intv = new IntV(nowStr);
                parseStack.push((void *)intv);
                typeStack.push("IntV");

                std::stack<void *> tempStack;
                while(typeStack.top() == "IntV" && !typeStack.empty()) {
                    tempStack.push(parseStack.top());
                    parseStack.pop();
                    typeStack.pop();
                }
                CList* clist = new CList();
                while(!tempStack.empty()) {
                    clist->addElement((IntV*) tempStack.top());
                    tempStack.pop();
                }
                parseStack.push((void *)clist);
                typeStack.push("CList");
                flag = 0;
            }
            else if (kernel[i] == '[') {
                nowRef = 2;
            }
            else if (kernel[i] == '=') {
                AList* alist = (AList *)parseStack.top();
                parseStack.pop();
                typeStack.pop();
                CList* clist = (CList *)parseStack.top();
                parseStack.pop();
                typeStack.pop();
                ValId* valid = (ValId *)parseStack.top();
                parseStack.pop();
                typeStack.pop();
                TRef* tref = new TRef(valid, clist, alist);
                LHS* lhs = new LHS(tref);
                parseStack.push((void *)lhs);
                typeStack.push("LHS");
                flag = 0;
            }
            else if (kernel[i] == '+' || kernel[i] == '-' || kernel[i] == '/' || kernel[i] == '*'
                    || kernel[i] == '%' || kernel[i] == ')' || kernel[i] == ';') {
                if(now == 1 && flag) {
                    IntV* intv = new IntV(nowStr);
                    RHS* rhs = new RHS(intv);
                    parseStack.push((void*)rhs);
                    typeStack.push("RHS");
                    flag = 0;
                }
                else if(now == 2 && flag) {
                    FloatV* floatv = new FloatV(nowStr);
                    RHS* rhs = new RHS(floatv);
                    parseStack.push((void*)rhs);
                    typeStack.push("RHS");
                    flag = 0;
                }
                else if (typeStack.top() == "AList") {
                    AList* alist = (AList *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    CList* clist = (CList *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    ValId* valid = (ValId *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    TRef* tref = new TRef(valid, clist, alist);
                    RHS* rhs = new RHS(tref);
                    parseStack.push((void *)rhs);
                    typeStack.push("RHS");
                }
                else if (typeStack.top() == "CList") {
                    CList* clist = (CList *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    ValId* valid = (ValId *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    SRef* sref = new SRef(valid, clist);
                    RHS* rhs = new RHS(sref);
                    parseStack.push((void *)rhs);
                    typeStack.push("RHS");
                }

                if (kernel[i] == '/' && kernel[i+1] == '/') i++;
                while (!symbolStack.empty() && getPriority(symbolStack.top()) >= getPriority(kernel[i])) {
                    char symbol = symbolStack.top();
                    symbolStack.pop();
                    RHS* p3 = (RHS *)parseStack.top();
                    parseStack.pop();typeStack.pop();
                    RHS* p1 = (RHS *)parseStack.top();
                    parseStack.pop();typeStack.pop();
                    RHS* rhs = getRHS(p1, symbol, p3);
                    parseStack.push((void *)rhs);
                    typeStack.push("RHS");
                }
                if (kernel[i] == ')') {
                    RHS* p1 = (RHS*)parseStack.top();
                    parseStack.pop();
                    symbolStack.pop();
                    BracketExpression* b = new BracketExpression(p1);
                    RHS* rhs = new RHS(b);
                    parseStack.push((void *)rhs);
                }
                else if (kernel[i] == ';') {
                    RHS* rhs = (RHS *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    LHS* lhs = (LHS *)parseStack.top();
                    parseStack.pop();
                    typeStack.pop();
                    S* s = new S(lhs, rhs);
                    p.addElememt(s);
                }
                else
                    symbolStack.push(kernel[i]);
            }
            else if (kernel[i] == '(') 
                symbolStack.push(kernel[i]);
        }
        else {
            if (kernel[i] == '/' && kernel[i+1] == '/') i++;
            if (now == 1 && flag) {
                flag = 0;
                IntV* intv = new IntV(nowStr);
                char p2 = symStack.top(); symStack.pop();
                IdExpr* p1 = (IdExpr *)parseStack.top(); parseStack.pop();
                typeStack.pop();
                IdExpr* idexpr = getIdExpr(p1, p2, intv);
                parseStack.push(idexpr);
                typeStack.push("IdExpr");
            }
            else if (now == 0 && flag) {
                flag = 0;
                if (iters.find(nowStr) == iters.end()) {
                    IterId* iterid = new IterId(nowStr);
                    iters[nowStr] = iterid;
                }
                IdExpr* idexpr = new IdExpr(iters[nowStr]);
                parseStack.push(idexpr);
                typeStack.push("IdExpr");
            }
            if (kernel[i] == ',' || kernel[i] == ']') {
                while (!symStack.empty()) {
                    symStack.pop();
                    IdExpr* p2 = (IdExpr *)parseStack.top(); parseStack.pop(); typeStack.pop();
                    IdExpr* p1 = (IdExpr *)parseStack.top(); parseStack.pop(); typeStack.pop();
                    IdAddExpression* exp = new IdAddExpression(p1, p2);
                    IdExpr* idexpr = new IdExpr(exp);
                    parseStack.push(idexpr);
                    typeStack.push("IdExpr");                    
                }
                if (kernel[i] == ']') {
                    std::stack<IdExpr*> tempStack;
                    while (!typeStack.empty() && typeStack.top() == "IdExpr") {
                        tempStack.push((IdExpr *)parseStack.top());
                        parseStack.pop();
                        typeStack.pop();
                    }
                    AList* alist = new AList();
                    while(!tempStack.empty()) {
                        alist->addElement(tempStack.top());
                        tempStack.pop();
                    }
                    parseStack.push((void *)alist);
                    typeStack.push("AList");
                    nowRef = 0;
                }
            }
            else{ 
                symStack.push(kernel[i]);
            }
        }
    }
}

void JsonParser::printKernel() {
    JsonVisitor visitor;
    std::cout << kernelName << std::endl;
    for (auto &i : inputs) std::cout << i << ' ';
    std::cout <<std::endl;
    for (auto &i : outputs) std::cout << i << ' ';
    std::cout <<std::endl;
    std::cout << data_type << std::endl;
    p.accept(&visitor);
}