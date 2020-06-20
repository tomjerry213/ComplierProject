#ifndef JSON_EXPRESSION_H
#define JSON_EXPRESSION_H

#include <bits/stdc++.h>
#include "IR.h"
using namespace Boost::Internal;

class P;
class S;
class LHS;
class RHS;
class Expression;
class AddExpression;
class SubExpression;
class ChuExpression;
class ModExpression;
class DivExpreesion;
class BracketExpression;
class TRef;
class SRef;
class ValId;
class CList;
class AList;
class IdExpr;
class IdExpression;
class IterId;
class IdAddExpression;
class IdIntAddExpression;
class IdIntMulExpression;
class IdIntDivExpression;
class IdIntModExpression;
class Const;
class FloatV;
class IntV;

class JsonVisitor;
class JsonArguVisitor;
class JsonAbsiVisitor;

class P {
 public:
    std::vector<S*> p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Stmt accept(JsonAbsiVisitor* visitor, Type argu);

    P(){}
    ~P() {
        for (auto i : p1) delete i;
    }
    void addElememt(S* _p1) {
        p1.push_back(_p1);
    }
};

class S { 
 public:
    LHS* p1;
    char p2;
    RHS* p3;
    char p4;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Stmt accept(JsonAbsiVisitor* viditor, Type argu);
    S(){}
    ~S() {
        delete p1;
        delete p3;
    }
    S(LHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '=';
        p3 = _p3;
        p4 = ';';
    }
};

class LHS {
 public:
    TRef* p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    LHS(){}
    ~LHS() {
        delete p1;
    }
    LHS(TRef* _p1) {
        p1 = _p1;
    }
};

class RHS {
 public:
    Expression* p1;
    int id = 0;
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    RHS(){}
    ~RHS() {
        delete p1;
    }
    RHS(Expression* _p1) {
        p1 = _p1;
    }
};

class Expression {
 public:
    int id = 0;
    virtual void accept(JsonVisitor* visitor);
    virtual void* accept(JsonArguVisitor* visitor, void* argu);
    virtual Expr accept(JsonAbsiVisitor* visitor, Type argu);
    Expression(){};
    ~Expression() {
    }
};

class AddExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    RHS* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    AddExpression(){}
    AddExpression(RHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '+';
        p3 = _p3;
    }
    ~AddExpression() {
        delete p1;
        delete p3;
    }
}; 

class MulExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    RHS* p3;

    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    MulExpression(){}
    MulExpression(RHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '*';
        p3 = _p3;
    }
    ~MulExpression() {
        delete p1;
        delete p3;
    }
};

class SubExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    RHS* p3;

    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    SubExpression(){}
    SubExpression(RHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '-';
        p3 = _p3;
    }
    ~SubExpression() {
        delete p1;
        delete p3;
    }
};

class ChuExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    RHS* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    ChuExpression(){}
    ChuExpression(RHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '/';
        p3 = _p3;
    }
    ~ChuExpression() {
        delete p1;
        delete p3;
    }
};

class ModExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    RHS* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    ModExpression(){}
    ModExpression(RHS* _p1, RHS* _p3) {
        p1 = _p1;
        p2 = '%';
        p3 = _p3;
    }
    ~ModExpression() {
        delete p1;
        delete p3;
    }
};

class DivExpression : public Expression {
 public:
    RHS* p1;
    char p2;
    char p3;
    RHS* p4;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    DivExpression(){};
    DivExpression(RHS* _p1, RHS* _p4) {
        p1 = _p1;
        p2 = '/';
        p3 = '/';
        p4 = _p4;
    }
    ~DivExpression() {
        delete p1;
        delete p4;
    }
};

class BracketExpression : public Expression {
 public:
    char p1;
    RHS* p2;
    char p3;

    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    BracketExpression(){}
    BracketExpression(RHS* _p2) {
        p1 = '(';
        p2 = _p2;
        p3 = ')';
    }
    ~BracketExpression() {
        delete p2;
    }
};

class TRef : public Expression {
 public:
    ValId* p1;
    char p2;
    CList* p3;
    char p4;
    char p5;
    AList* p6;
    char p7;

    std::vector<Expr> lazy;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    TRef(){}
    TRef(ValId* _p1, CList* _p3, AList* _p6) {
        p1 = _p1;
        p2 = '<';
        p3 = _p3;
        p4 = '>';
        p5 = '[';
        p6 = _p6;
        p7 = ']';
    }
    ~TRef() {
        delete p3;
        delete p6;
    }
};

class SRef : public Expression {
 public:
    ValId* p1;
    char p2;
    CList* p3;
    char p4;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    SRef(){}
    SRef(ValId* _p1, CList* _p3) {
        p1 = _p1;
        p2 = '<';
        p3 = _p3;
        p4 = '>';
    }
    ~SRef() {
        delete p1;
        delete p3;
    }
};

class ValId {
 public:
    std::string p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    std::string accept(JsonAbsiVisitor* visitor, Type argu);
    ValId(){}
    ValId(std::string _p1) {
        p1 = _p1;
    }
    ~ValId(){}
};

class CList {
 public:
    std::vector<IntV*> p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    std::vector<size_t> accept(JsonAbsiVisitor* visitor, Type argu);
    CList(){}
    void addElement(IntV* _p1) {
        p1.push_back(_p1);
    }
    ~CList() {
        for (auto i : p1) delete i;
    }
};

class AList {
 public:
    std::vector<IdExpr*> p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    std::vector<Expr> accept(JsonAbsiVisitor* visitor, Type argu, CList* clist);
    AList(){}
    void addElement(IdExpr* _p1) {
        p1.push_back(_p1);
    }
    ~AList() {
        for (auto i : p1) delete i;
    }
};

class IdExpr {
 public:
    IdExpression* p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdExpr(){}
    IdExpr(IdExpression* _p1) {
        p1 = _p1;
    }
};

class IdExpression {
 public:
    virtual void accept(JsonVisitor* visitor);
    virtual void* accept(JsonArguVisitor* visitor, void* argu);
    virtual Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdExpression(){}
    ~IdExpression(){}
};

class IterId : public IdExpression {
 public:
    std::string p1;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IterId(){};
    IterId(std::string _p1) {
        p1 = _p1;
    }
    ~IterId() {}
};

class IdAddExpression : public IdExpression {
 public:
    IdExpr* p1;
    char p2;
    IdExpr* p3;

    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type arg, int val);
    IdAddExpression(){}
    IdAddExpression(IdExpr* _p1, IdExpr* _p3) {
        p1 = _p1;
        p2 = '+';
        p3 = _p3;
    }
};

class IdIntAddExpression : public IdExpression {
 public:
    IdExpr* p1;
    char p2;
    IntV* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdIntAddExpression(){}
    IdIntAddExpression(IdExpr* _p1, IntV* _p3) {
        p1 = _p1;
        p2 = '+';
        p3 = _p3;
    }
};

class IdIntMulExpression : public IdExpression {
 public:
    IdExpr* p1;
    char p2;
    IntV* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdIntMulExpression(){}
    IdIntMulExpression(IdExpr* _p1, IntV* _p3) {
        p1 = _p1;
        p2 = '*';
        p3 = _p3;
    }
};

class IdIntDivExpression : public IdExpression {
 public:
    IdExpr* p1;
    char p2;
    char p3;
    IntV* p4;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdIntDivExpression(){}
    IdIntDivExpression(IdExpr* _p1, IntV* _p4) {
        p1 = _p1;
        p2 = '/';
        p3 = '/';
        p4 = _p4;
    }
};

class IdIntModExpression : public IdExpression {
 public:
    IdExpr* p1;
    char p2;
    IntV* p3;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu, int val);
    IdIntModExpression(){}
    IdIntModExpression(IdExpr* _p1, IntV* _p3) {
        p1 = _p1;
        p2 = '%';
        p3 = _p3;
    }
};

class Const : public Expression {
 public:
    virtual void accept(JsonVisitor* visitor);
    virtual void* accept(JsonArguVisitor* visitor, void* argu);
    virtual Expr accept(JsonAbsiVisitor* visitor, Type argu);
    Const(){}
};

class FloatV : public Const {
 public:
    std::string p1; //digit repression of float;
    float val;

    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    FloatV(){}
    FloatV(std::string _p1) {
        p1 = _p1;
        val = 0;
        int l = p1.size();
        int i;
        for (i = 0; i < l && p1[i]!= '.'; i++)
            val = val * 10.0 + (p1[i] - '0');
        if(p1[i] == '.') i++;
        float now = 0.1;
        for (i; i < l; i++) {
            val = val + (p1[i] - '0') * now;
            now /= 10.0;
        }
    }
};

class IntV : public Const {
 public:
    std::string p1;
    int val;
    
    void accept(JsonVisitor* visitor);
    void* accept(JsonArguVisitor* visitor, void* argu);
    Expr accept(JsonAbsiVisitor* visitor, Type argu);
    IntV(){};
    IntV(std::string _p1) {
        p1 = _p1;
        int l = p1.size();
        val = 0;
        for (int i = 0; i < l; i++)
            val = val * 10 + (p1[i] - '0');
        //std::cout << _p1 << ' ' << val << std::endl;
    }
};



#endif //JSON_EXPRESSION_H