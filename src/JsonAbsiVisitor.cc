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
	flag = true;
    Expr l = op->p1->accept(this, t);
	flag = false;
    Expr r = op->p3->accept(this, t);
    std::vector<Stmt> center;
	int i;
	//std::cout << maxId << std::endl;
	for (nowId = 1; nowId <= maxId; nowId++)
	{
		Expr y = op->p3->accept(this, t);
		Expr y1 = Binary::make(t, BinaryOpType::Mul, y, l);
		Stmt x = Move::make(need_grad[nowId - 1], y1, MoveType::MemToMem);

		for (i = 0; i < allCondition.size(); i ++)
			x = IfThenElse::make(Compare::make(Type::int_scalar(32), CompareOpType::LT, allCondition[i].first, allCondition[i].second),x,LoopNest::make({},{}));
		for (i = 0; i < allEqualCondition.size(); i ++)
			x = IfThenElse::make(Compare::make(Type::int_scalar(32), CompareOpType::EQ, allEqualCondition[i].first, allEqualCondition[i].second),x,LoopNest::make({},{}));
		center.push_back(x);
	}
	//std::cout << center.size() << std::endl;
	Stmt x = LoopNest::make(allIndex, center);
	return x;
}

Expr JsonAbsiVisitor::visit(LHS* op, Type t) {
    return op->p1->accept(this, t);
}

Expr JsonAbsiVisitor::visit(RHS* op, Type t) {
	//std::cout << "DDD" << std::endl;
    Expr ret = op->p1->accept(this, t);
	op->id = op->p1->id;
	//std::cout << op->id << std::endl;
	return ret;
}

Expr JsonAbsiVisitor::visit(Expression* op, Type t) {
}

Expr JsonAbsiVisitor::visit(AddExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	//std::cout << nowId << std::endl;
	if (nowId != 0) {
		if (op->p1->id == nowId) { 
			op->id = nowId;
			//std::cout << "a" << std::endl;
			return a;
		}
		if (op->p3->id == nowId) {
			op->id = nowId;
			return b;
		}
		op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Add, a, b);
}

Expr JsonAbsiVisitor::visit(MulExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	//std::cout << nowId << ' ' << flag3 << std::endl; 
	if (nowId != 0 && !flag3) {
		if(op->p1->id == nowId || op->p3->id == nowId)
			op->id = nowId;
		if(op->p1->id != nowId) {
			flag3 = true;
			op->p1->accept(this, t);
			flag3 = false;
		}
		else if(op->p3->id != nowId) {
			flag3 = true;
			op->p3->accept(this, t);
			flag3 = false;
		}
		else op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Mul, a, b);
}

Expr JsonAbsiVisitor::visit(SubExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	if (nowId != 0) {
		if (op->p1->id == nowId) { 
			op->id = nowId;
			return a;
		}
		if (op->p3->id == nowId) {
			Expr x = FloatImm::make(t, -1);
			return Binary::make(t, BinaryOpType::Mul, x, b);
		}
		op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Sub, a, b);
}

Expr JsonAbsiVisitor::visit(ChuExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	if (nowId != 0) {
		if(op->p1->id == nowId || op->p3->id == nowId)
			op->id = nowId;
		else op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(ModExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p3->accept(this, t);
	if (nowId != 0) {
		if(op->p1->id == nowId || op->p3->id == nowId)
			op->id = nowId;
		else op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Mod, a, b);
}

Expr JsonAbsiVisitor::visit(DivExpression* op, Type t) {
    Expr a = op->p1->accept(this, t);
    Expr b = op->p4->accept(this, t);
	if (nowId != 0) {
		if(op->p1->id == nowId || op->p4->id == nowId)
			op->id = nowId;
		else op->id = 0;
	}
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(BracketExpression* op, Type t) {
    Expr ret = op->p2->accept(this, t);
	op->id = op->p2->id;
	return ret;
}

Expr JsonAbsiVisitor::visit(TRef* op, Type t) {
	if (flag3)
		parser->inInput[op->p1->p1] = 1;
	if(op->lazy.size() != 0) { 
		if (op->id == nowId) {
			return FloatImm::make(t, 1.0);
			}
		return op->lazy[0];
	}
    std::vector<size_t> cList = op->p3->accept(this, Type::int_scalar(32));
    std::vector<Expr> aList = op->p6->accept(this, Type::int_scalar(32), op->p3);
  
    for (int i = 0; i < cList.size(); i ++) {
        Expr r = IntImm::make(Type::int_scalar(32), (int)cList[i]);
		allCondition.push_back(std::make_pair(aList[i], r));
    }
    std::string x = op->p1->p1;
	//std::cout << x << std::endl;
    parser->valSize[x] = cList;
	if (flag)
	{
		x = "d" + x;
	}
	else if (parser->grads.find(x) != parser->grads.end())
	{
		std::string y = "d" + x;
		need_grad.push_back(Var::make(t, y, aList, cList));
		need_grad_ori.push_back(Var::make(t, x, aList, cList));
		op->id = ++maxId;
	}
	op->lazy.push_back(Var::make(t, x, aList, cList));
	return op->lazy[0];
}

Expr JsonAbsiVisitor::visit(SRef* op, Type t) {
    parser->valSize[op->p1->p1] = {}; 
	return Var::make(t, op->p1->p1, {}, {});
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
		flag2 = false;
        Expr ans = (op->p1)[i]->accept(this, t, (cList->p1)[i]->val);
		if (flag2) {
			std::string name = "temp0";
			name[4] = cnt++;
			Expr new_index = Index::make(Type::int_scalar(32), name, {Dom::make(Type::int_scalar(32), 0, (cList->p1)[i]->val)}, IndexType::Spatial);
			allIndex.push_back(new_index);
			allEqualCondition.push_back(std::make_pair(new_index, ans));
			x.push_back(new_index);
		}
		else x.push_back(ans);
    }
	return x;
}

Expr JsonAbsiVisitor::visit(IdExpr* op, Type t, int val) {
    Expr ans = op->p1->accept(this, t, val);
	return ans;
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
    flag2 = true;
	Expr a = op->p1->accept(this, t, -1);
    Expr b = op->p3->accept(this, t, -1);
	return Binary::make(t, BinaryOpType::Add, a, b);
}

//-----------------------------------------------------------------

Expr JsonAbsiVisitor::visit(IdIntAddExpression* op, Type t, int y) {
	flag2 = true;
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Add, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntMulExpression* op, Type t, int y) {
	flag2 = true;
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p3->accept(this, t);
	return Binary::make(t, BinaryOpType::Mul, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntDivExpression* op, Type t, int y) {
	flag2 = true;
	//std::cout << "DDD" << std::endl;
    Expr a = op->p1->accept(this, t, y);
    Expr b = op->p4->accept(this, t);
	return Binary::make(t, BinaryOpType::Div, a, b);
}

Expr JsonAbsiVisitor::visit(IdIntModExpression* op, Type t, int y) {
	flag2 = true;
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
