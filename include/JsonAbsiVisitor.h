#ifndef JSONABSIVISITOR_H
#define JSONABSIVISITOR_H

#include "JsonExpression.h"
#include "JsonParser.h"

class JsonAbsiVisitor {
 public:
    JsonParser *parser;
    std::vector<Expr> allIndex;
    std::map<std::string, int> iterMap;
    std::vector<std::pair<Expr, Expr> > allCondition;
    bool flag = false;
    bool flag2 = false;
    bool flag3 = false;
    int cnt = '0';
    std::vector<Expr> need_grad;
    std::vector<Expr> need_grad_ori;
    std::vector<std::pair<Expr, Expr> > allEqualCondition;

    int maxId = 0;
    int nowId = 0;

    virtual Stmt visit(P* op, Type argu);
    virtual Stmt visit(S* op, Type argu);
    virtual Expr visit(LHS* op, Type argu);
    virtual Expr visit(RHS* op, Type argu);
    virtual Expr visit(Expression* op, Type argu);
    virtual Expr visit(AddExpression* op, Type argu);
    virtual Expr visit(SubExpression* op, Type argu);
    virtual Expr visit(ChuExpression* op, Type argu);
    virtual Expr visit(MulExpression* op, Type argu);
    virtual Expr visit(ModExpression* op, Type argu);
    virtual Expr visit(DivExpression* op, Type argu);
    virtual Expr visit(BracketExpression* op, Type argu);
    virtual Expr visit(TRef* op, Type argu);
    virtual Expr visit(SRef* op, Type argu);
    virtual std::string visit(ValId* op, Type argu);
    virtual std::vector<size_t> visit(CList* op, Type argu);
    virtual std::vector<Expr> visit(AList* op, Type argu, CList* clist);
    virtual Expr visit(IdExpr* op, Type argu, int val);
    virtual Expr visit(IdExpression* op, Type argu, int val);
    virtual Expr visit(IterId* op, Type argu, int val);
    virtual Expr visit(IdAddExpression* op, Type argu, int val);
    virtual Expr visit(IdIntAddExpression* op, Type argu, int val);
    virtual Expr visit(IdIntMulExpression* op, Type argu, int val);
    virtual Expr visit(IdIntDivExpression* op, Type argu, int val);
    virtual Expr visit(IdIntModExpression* op, Type argu, int val);
    virtual Expr visit(Const* op, Type argu);
    virtual Expr visit(FloatV* op, Type argu);
    virtual Expr visit(IntV* op, Type argu);
};
#endif //JSONABSIVISITOR_H