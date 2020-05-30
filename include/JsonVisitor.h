#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "JsonExpression.h"

class JsonVisitor {
public:
    virtual void visit(P* op);
    virtual void visit(S* op);
    virtual void visit(LHS* op);
    virtual void visit(RHS* op);
    virtual void visit(Expression* op);
    virtual void visit(AddExpression* op);
    virtual void visit(MulExpression* op);
    virtual void visit(SubExpression* op);
    virtual void visit(ChuExpression* op);
    virtual void visit(ModExpression* op);
    virtual void visit(DivExpression* op);
    virtual void visit(BracketExpression* op);
    virtual void visit(TRef* op);
    virtual void visit(SRef* op);
    virtual void visit(ValId* op);
    virtual void visit(CList* op);
    virtual void visit(AList* op);
    virtual void visit(IdExpr* op);
    virtual void visit(IdExpression* op);
    virtual void visit(IterId* op);
    virtual void visit(IdAddExpression* op);
    virtual void visit(IdIntAddExpression* op);
    virtual void visit(IdIntMulExpression* op);
    virtual void visit(IdIntDivExpression* op);
    virtual void visit(IdIntModExpression* op);
    virtual void visit(Const* op);
    virtual void visit(FloatV* op);
    virtual void visit(IntV* op);
};

#endif