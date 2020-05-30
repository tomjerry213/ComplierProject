#include "JsonArguVisitor.h"

void* JsonArguVisitor::visit(P* op, void* argu) {
    for (int i = 0; i < (op->p1).size(); i++)
        (op->p1)[i]->accept(this, argu);
    return NULL;
} 

void* JsonArguVisitor::visit(S* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << '=';
    op->p3->accept(this, argu);
    std::cout << ";" << std::endl;
    return NULL;
}

void* JsonArguVisitor::visit(LHS* op, void* argu) {
    op->p1->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(RHS* op, void* argu) {
    op->p1->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(Expression* op, void* argu) {
    return NULL;
}

void* JsonArguVisitor::visit(AddExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(MulExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(SubExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(ChuExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(ModExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(DivExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    std::cout << op->p3;
    op->p4->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(BracketExpression* op, void* argu) {
    std::cout << op->p1;
    op->p2->accept(this, argu);
    std::cout << op->p3;
    return NULL;
}

void* JsonArguVisitor::visit(TRef* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    std::cout << op->p4 << op->p5;
    op->p6->accept(this, argu);
    std::cout << op->p7;
    return NULL;
}

void* JsonArguVisitor::visit(SRef* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    std::cout << op->p4;
    return NULL;
}

void* JsonArguVisitor::visit(ValId* op, void* argu) {
    std::cout << op->p1;
    return NULL;
}

void* JsonArguVisitor::visit(CList* op, void* argu) {
    for (int i = 0; i < (op->p1).size(); i++) {
        if(i) std::cout << ',';
        (op->p1)[i]->accept(this, argu);
    }
    return NULL;
}

void* JsonArguVisitor::visit(AList* op, void* argu) {
    for (int i = 0; i < (op->p1).size(); i++) {
        if(i) std::cout << ',';
        (op->p1)[i]->accept(this, argu);
    }
    return NULL;
}

void* JsonArguVisitor::visit(IdExpr* op, void* argu) {
    op->p1->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(IdExpression* op, void* argu) {
    return NULL;
}

void* JsonArguVisitor::visit(IterId* op, void* argu) {
    std::cout << op->p1;
    return NULL;
}

void* JsonArguVisitor::visit(IdAddExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(IdIntAddExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(IdIntMulExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(IdIntDivExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    std::cout << op->p3;
    op->p4->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(IdIntModExpression* op, void* argu) {
    op->p1->accept(this, argu);
    std::cout << op->p2;
    op->p3->accept(this, argu);
    return NULL;
}

void* JsonArguVisitor::visit(Const* op, void* argu) {
    return NULL;
}

void* JsonArguVisitor::visit(FloatV* op, void* argu) {
    std::cout << op->p1 << 'f';
    return NULL;
}

void* JsonArguVisitor::visit(IntV* op, void* argu) {
    std::cout << op->p1;
    return NULL;
}
