#include "JsonAbsiVisitor.h"
#include "IR.h"
#include "JsonExpression.h"
using namespace Boost::Internal;
Stmt JsonAbsiVisitor::visit(P* op, Type t) {
	std::vector<Stmt> a;
    for (int i = 0; i < (op->p1).size(); i++)
	{
		Stmt x;
        x = (op->p1)[i]->accept(this, t);
		a.push_back(x);
	}
	return LoopNest::make(std::vector<Expr>(), a);
} 

Stmt JsonAbsiVisitor::visit(S* op, Type t) {
	allIndex.clear();
    iterMap.clear();
    allCondition.clear();
    Expr l = op->p1->accept(this, t);
    Expr r = op->p3->accept(this, t);
    Stmt center = Move::make(l,r, MoveType::MemToMem);
	int i;
	for (i = 0; i < allCondition.size(); i ++)
		center = IfThenElse::make(Compare::make(Type::int_scalar(32), CompareOpType::LT, allCondition[i].first, allCondition[i].second),center,LoopNest::make({},{}));
	Stmt x = LoopNest::make(allIndex, {center});
	return x;
}

Expr JsonAbsiVisitor::visit(LHS* op, Type t) {
    return op->p1->accept(this, t);
}

Expr JsonAbsiVisitor::visit(RHS* op, Type t) {
    return op->p1->accept(this, t);
}

Expr JsonAbsiVisitor::visit(Expression* op, Type t) {
}

Expr JsonAbsiVisitor::visit(AddExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Add, a, b);
}

Expr JsonAbsiVisitor::visit(MulExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Mul, a, b);
}

Expr JsonAbsiVisitor::visit(SubExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Sub, a, b);
}

Expr JsonAbsiVisitor::visit(ChuExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(ModExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Mod, a, b);
}

Expr JsonAbsiVisitor::visit(DivExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p4->accept(this, t);
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(BracketExpression* op, Type t) {
    return op->p2->accept(this, t);
}

Expr JsonAbsiVisitor::visit(TRef* op, Type t) {
    std::vector<size_t> cList = op->p3->accept(this, Type::int_scalar(32));
    std::vector<Expr> aList = op->p6->accept(this, Type::int_scalar(32), op->p3);
  
    for (int i = 0; i < cList.size(); i ++) {
        Expr r = IntImm::make(Type::int_scalar(32), (int)cList[i]);
		allCondition.push_back(std::make_pair(aList[i], r));
    }
    std::string x = op->p1->p1;
    parser->valSize[x] = cList;
	return Var::make(t, x, aList, cList);
}

Expr JsonAbsiVisitor::visit(SRef* op, Type t) {
	return Var::make(t, op->p1->p1, {}, {});
    parser->valSize[op->p1->p1] = {}; 
}

std::string JsonAbsiVisitor::visit(ValId* op, Type t) {
	return op->p1;
}

std::vector<size_t> JsonAbsiVisitor::visit(CList* op, Type t) {
	std::vector<size_t> x;
    for (int i = 0; i < (op->p1).size(); i++) {
        x.push_back((size_t)op->p1[i]->val);
    }
	return x;
}

std::vector<Expr> JsonAbsiVisitor::visit(AList* op, Type t, CList * cList) {
	std::vector<Expr> x;
    for (int i = 0; i < (op->p1).size(); i++) {
        x.push_back((op->p1)[i]->accept(this, t, (cList->p1)[i]->val));
    }
	return x;
}

Expr JsonAbsiVisitor::visit(IdExpr* op, Type t, int val) {
    return op->p1->accept(this, t, val);
}

Expr JsonAbsiVisitor::visit(IdExpression* op, Type t, int y) {
}

Expr JsonAbsiVisitor::visit(IterId* op, Type t, int y) {
	if (y != -1 && !iterMap[op->p1]) {
        iterMap[op->p1] = 1;
		Expr _ret = Index::make(t, op->p1, {Dom::make(t, 0, y)}, IndexType::Spatial);
		allIndex.push_back(_ret);
        return _ret;
	}
	else {
		Expr _ret = Index::make(t, op->p1, {Dom::make(t, 0, 10000)}, IndexType::Spatial);
        return _ret;
    }
}

Expr JsonAbsiVisitor::visit(IdAddExpression* op, Type t, int y) {
    Expr a = op->p1->accept(this, t, -1);
    Expr b = op->p3->accept(this, t, -1);
	return Binary::make(t, BinaryOpType::Add, a, b);
}

//-----------------------------------------------------------------

Expr JsonAbsiVisitor::visit(IdIntAddExpression* op, Type t, int y) {
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Add, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntMulExpression* op, Type t, int y) {
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Mul, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntDivExpression* op, Type t, int y) {
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p4->accept(this, t);
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntModExpression* op, Type t, int y) {
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Mod, a, b);
}

Expr JsonAbsiVisitor::visit(Const* op, Type t) {
}

Expr JsonAbsiVisitor::visit(FloatV* op, Type t) {
	return FloatImm::make(t, op -> val);
}

Expr JsonAbsiVisitor::visit(IntV* op, Type t) {
	return IntImm::make(t, op -> val);
}
