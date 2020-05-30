#include "JsonExpression.h"
#include "JsonVisitor.h"
#include "JsonArguVisitor.h"
#include "JsonAbsiVisitor.h"

void P::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void S::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}


void LHS::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void RHS::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void Expression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void AddExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void MulExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void SubExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void ChuExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void ModExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void DivExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void BracketExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void TRef::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void SRef::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void ValId::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void CList::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void AList::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdExpr::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IterId::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdAddExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdIntAddExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdIntMulExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdIntDivExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IdIntModExpression::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void Const::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void FloatV::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void IntV::accept(JsonVisitor* visitor) {
    visitor->visit(this);
}

void* P::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* S::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* LHS::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* RHS::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* Expression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* AddExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* SubExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* ChuExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* MulExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* ModExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* DivExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* BracketExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* TRef::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* SRef::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* ValId::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* CList::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* AList::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdExpr::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IterId::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdAddExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdIntAddExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdIntMulExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdIntDivExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IdIntModExpression::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* Const::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* IntV::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

void* FloatV::accept(JsonArguVisitor* visitor, void* argu) {
    return visitor->visit(this, argu);
}

Stmt P::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Stmt S::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr LHS::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr RHS::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr Expression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr AddExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr SubExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr ChuExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr MulExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr ModExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr DivExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr BracketExpression::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr TRef::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr SRef::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

std::string ValId::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

std::vector<size_t> CList::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

std::vector<Expr> AList::accept(JsonAbsiVisitor* visitor, Type argu, CList* clist) {
    return visitor->visit(this, argu, clist);
}

Expr IdExpr::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IterId::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdAddExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdIntAddExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdIntMulExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdIntDivExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr IdIntModExpression::accept(JsonAbsiVisitor* visitor, Type argu, int val) {
    return visitor->visit(this, argu, val);
}

Expr Const::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr FloatV::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}

Expr IntV::accept(JsonAbsiVisitor* visitor, Type argu) {
    return visitor->visit(this, argu);
}