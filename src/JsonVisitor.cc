#include "JsonVisitor.h"
#include "JsonExpression.h"
void JsonVisitor::visit(P* op) {
    for (int i = 0; i < (op->p1).size(); i++)
        (op->p1)[i]->accept(this);
} 

void JsonVisitor::visit(S* op) {
    op->p1->accept(this);
    std::cout << '=';
    op->p3->accept(this);
    std::cout << ";" << std::endl;
}

void JsonVisitor::visit(LHS* op) {
    op->p1->accept(this);
}

void JsonVisitor::visit(RHS* op) {
    op->p1->accept(this);
}

void JsonVisitor::visit(Expression* op) {
}

void JsonVisitor::visit(AddExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(MulExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(SubExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(ChuExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(ModExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(DivExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    std::cout << op->p3;
    op->p4->accept(this);
}

void JsonVisitor::visit(BracketExpression* op) {
    std::cout << op->p1;
    op->p2->accept(this);
    std::cout << op->p3;
}

void JsonVisitor::visit(TRef* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
    std::cout << op->p4 << op->p5;
    op->p6->accept(this);
    std::cout << op->p7;
}

void JsonVisitor::visit(SRef* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
    std::cout << op->p4;
}

void JsonVisitor::visit(ValId* op) {
    std::cout << op->p1;
}

void JsonVisitor::visit(CList* op) {
    for (int i = 0; i < (op->p1).size(); i++) {
        if(i) std::cout << ',';
        (op->p1)[i]->accept(this);
    }
}

void JsonVisitor::visit(AList* op) {
    for (int i = 0; i < (op->p1).size(); i++) {
        if(i) std::cout << ',';
        (op->p1)[i]->accept(this);
    }
}

void JsonVisitor::visit(IdExpr* op) {
    op->p1->accept(this);
}

void JsonVisitor::visit(IdExpression* op) {
}

void JsonVisitor::visit(IterId* op) {
    std::cout << op->p1;
}

void JsonVisitor::visit(IdAddExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(IdIntAddExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(IdIntMulExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(IdIntDivExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    std::cout << op->p3;
    op->p4->accept(this);
}

void JsonVisitor::visit(IdIntModExpression* op) {
    op->p1->accept(this);
    std::cout << op->p2;
    op->p3->accept(this);
}

void JsonVisitor::visit(Const* op) {
}

void JsonVisitor::visit(FloatV* op) {
    std::cout << op->val << 'f';
}

void JsonVisitor::visit(IntV* op) {
    std::cout << op->val;
}
