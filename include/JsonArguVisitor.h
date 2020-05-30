#ifndef JSONARGUVISITOR_H
#define JSONARGUVISITOR_H

#include "JsonExpression.h"

class JsonArguVisitor {
 public:
    virtual void* visit(P* op, void* argu);
    virtual void* visit(S* op, void* argu);
    virtual void* visit(LHS* op, void* argu);
    virtual void* visit(RHS* op, void* argu);
    virtual void* visit(Expression* op, void* argu);
    virtual void* visit(AddExpression* op, void* argu);
    virtual void* visit(SubExpression* op, void* argu);
    virtual void* visit(ChuExpression* op, void* argu);
    virtual void* visit(MulExpression* op, void* argu);
    virtual void* visit(ModExpression* op, void* argu);
    virtual void* visit(DivExpression* op, void* argu);
    virtual void* visit(BracketExpression* op, void* argu);
    virtual void* visit(TRef* op, void* argu);
    virtual void* visit(SRef* op, void* argu);
    virtual void* visit(ValId* op, void* argu);
    virtual void* visit(CList* op, void* argu);
    virtual void* visit(AList* op, void* argu);
    virtual void* visit(IdExpr* op, void* argu);
    virtual void* visit(IdExpression* op, void* argu);
    virtual void* visit(IterId* op, void* argu);
    virtual void* visit(IdAddExpression* op, void* argu);
    virtual void* visit(IdIntAddExpression* op, void* argu);
    virtual void* visit(IdIntMulExpression* op, void* argu);
    virtual void* visit(IdIntDivExpression* op, void* argu);
    virtual void* visit(IdIntModExpression* op, void* argu);
    virtual void* visit(Const* op, void* argu);
    virtual void* visit(FloatV* op, void* argu);
    virtual void* visit(IntV* op, void* argu);
};
#endif //JSONARGUVISITOR_H