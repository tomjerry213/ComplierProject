/*
 * MIT License
 * 
 * Copyright (c) 2020 Size Zheng

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include "IRPrinter.h"

namespace Boost {

namespace Internal {


std::string IRPrinter::print(const Expr &expr) { // YZW Done
    oss.clear();
    expr.visit_expr(this);
    return oss.str();
}


std::string IRPrinter::print(const Stmt &stmt) { // YZW Done
    oss.clear();
    stmt.visit_stmt(this);
    return oss.str();
}


std::string IRPrinter::print(const Group &group) { // YZW Done
    oss.clear();
    group.visit_group(this);
    return oss.str();
}


void IRPrinter::visit(Ref<const IntImm> op) { // YZW Done
    CHECK(op->type().is_int(), "Argument is not an integer.");
    if(op->type().bits == 8)
        oss << "(char)"  << op->value();
    else if(op->type().bits == 16)
        oss << "(short)" << op->value();
    else if(op->type().bits == 32)
        oss << op->value();
    else if(op->type().bits == 64)
        oss << op->value() << "LL";
    else
        CHECK(0, "Integer with %d bits is not supported.", op->type().bits);
}


void IRPrinter::visit(Ref<const UIntImm> op) { // YZW Done
    CHECK(op->type().is_uint(), "Argument is not an usigned integer.");
    if(op->type().bits == 8)
        oss << "(unsigned char)"  << op->value();
    else if(op->type().bits == 16)
        oss << "(unsigned short)" << op->value();
    else if(op->type().bits == 32)
        oss << op->value() << "U";
    else if(op->type().bits == 64)
        oss << op->value() << "ULL";
    else
        CHECK(0, "Integer with %d bits is not supported.", op->type().bits);
}


void IRPrinter::visit(Ref<const FloatImm> op) { // YZW Done
    CHECK(op->type().is_float(), "Argument is not a float.");

    auto float64toStr = [](double value){
        char* s = new char[51];
        snprintf(s, 50, "%.20lf", value);

        // remove extra 0 behind float dot.
        int i;
        for(i = 0; s[i] != '\0'; i++);
        for(i--; i >= 0 && s[i] == '0'; i--)
            s[i] = '\0';

        return s;
    };

    if(op->type().bits == 32)
        oss << "(float)" << float64toStr(op->value());
    else if(op->type().bits == 64)
        oss << float64toStr(op->value());
    else
        CHECK(0, "float with %d bits is not supported.", op->type().bits);
}


void IRPrinter::visit(Ref<const StringImm> op) { // YZW Done
    oss << '"' << op->value() << '"';
}


void IRPrinter::visit(Ref<const Unary> op) { // YZW Done
    if (op->op_type == UnaryOpType::Neg) {
        oss << "-";
    } else if (op->op_type == UnaryOpType::Not) {
        oss << "!";
    }
    (op->a).visit_expr(this);
}


void IRPrinter::visit(Ref<const Binary> op) { // YZW Done
    oss << "(";
    (op->a).visit_expr(this);
    oss << ")";
    if (op->op_type == BinaryOpType::Add) {
        oss << " + ";
    } else if (op->op_type == BinaryOpType::Sub) {
        oss << " - ";
    } else if (op->op_type == BinaryOpType::Mul) {
        oss << " * ";
    } else if (op->op_type == BinaryOpType::Div) {
        oss << " / ";
    } else if (op->op_type == BinaryOpType::Mod) {
        oss << " % ";
    } else if (op->op_type == BinaryOpType::And) {
        oss << " && ";
    } else if (op->op_type == BinaryOpType::Or) {
        oss << " || ";
    }
    oss << "(";
    (op->b).visit_expr(this);
    oss << ")";
}


void IRPrinter::visit(Ref<const Compare> op) { // YZW Done
    (op->a).visit_expr(this);
    if (op->op_type == CompareOpType::LT) {
        oss << " < ";
    } else if (op->op_type == CompareOpType::LE) {
        oss << " <= ";
    } else if (op->op_type == CompareOpType::EQ) {
        oss << " == ";
    } else if (op->op_type == CompareOpType::GE) {
        oss << " >= ";
    } else if (op->op_type == CompareOpType::GT) {
        oss << " > ";
    } else if (op->op_type == CompareOpType::NE) {
        oss << " != ";
    }
    (op->b).visit_expr(this);
}


void IRPrinter::visit(Ref<const Select> op) { // YZW Done
    (op->cond).visit_expr(this);
    oss << " ? ";
    (op->true_value).visit_expr(this);
    oss << " : ";
    (op->false_value).visit_expr(this);
}


void IRPrinter::visit(Ref<const Call> op) { // YZW Done
    oss << op->func_name << "(";
    for (size_t i = 0; i < op->args.size(); ++i) {
        if(i > 0)oss << ", ";
        op->args[i].visit_expr(this);
    }
    oss << ")";
}


void IRPrinter::visit(Ref<const Cast> op) { // YZW Done
    oss << op->new_type << "(";
    (op->val).visit_expr(this);
    oss << ")";
}


void IRPrinter::visit(Ref<const Ramp> op) { // YZW Doing
    CHECK(0, "Node Ramp is not implemented");
    /*
    oss << "ramp(";
    (op->base).visit_expr(this);
    oss << ", " << op->stride << ", " << op->lanes << ")";
    */
}


void IRPrinter::visit(Ref<const Var> op) { // YZW Done
    oss << op->name;
    for (size_t i = 0; i < op->args.size(); ++i) {
        oss << "[";
        op->args[i].visit_expr(this);
        oss << ']';
    }
}


void IRPrinter::visit(Ref<const Dom> op) { // YZW Done
    CHECK(0, "Node Dom is not printable");
    /*
    oss << "dom[";
    (op->begin).visit_expr(this);
    oss << ", ";
    (op->extent).visit_expr(this);
    oss << ")";
    */
}


void IRPrinter::visit(Ref<const Index> op) { // YZW Done
    CHECK(op->type().is_int(), "Node Index must be integer");
    auto dom = dynamic_cast<const Dom *>(op->dom.get());
    if (print_range) {
        if (op->index_type == IndexType::Spatial) {
            oss << "(int " << op->name << " = ";
            dom->begin.visit_expr(this);
            oss << "; " << op->name << " < ";
            dom->extent.visit_expr(this);
            oss << "; ++" << op->name << ")"; 
        } else if (op->index_type == IndexType::Reduce) {
            oss << "(int " << op->name << " = ";
            dom->begin.visit_expr(this);
            oss << "; " << op->name << " < ";
            dom->extent.visit_expr(this);
            oss << "; ++" << op->name << ")"; 
        } else if (op->index_type == IndexType::Unrolled) {
            CHECK(0, "index type Unrolled is not supported.");
        } else if (op->index_type == IndexType::Vectorized) {
            CHECK(0, "index type Vectorized is not supported.");
        } else if (op->index_type == IndexType::Block) {
            CHECK(0, "index type Block is not supported.");
        } else if (op->index_type == IndexType::Thread) {
            CHECK(0, "index type Thread is not supported.");
        }
    }
    else oss << op->name;
}


void IRPrinter::visit(Ref<const LoopNest> op) { // YZW Done
    print_range = true;
    for (auto index : op->index_list) {
        print_indent();
        oss << "for";
        index.visit_expr(this);
        oss << "{\n";
        enter();
    }
    print_range = false;
    for (auto body : op->body_list) {
        body.visit_stmt(this);
    }
    for (auto index : op->index_list) {
        exit();
        print_indent();
        oss << "}\n";
    }
}


void IRPrinter::visit(Ref<const IfThenElse> op) { // YZW Done
    print_indent();
    oss << "if (";
    (op->cond).visit_expr(this);
    oss << ") {\n";
    enter();
    (op->true_case).visit_stmt(this);
    exit();
    print_indent();
    oss << "} else {\n";
    enter();
    (op->false_case).visit_stmt(this);
    exit();
    print_indent();
    oss << "}\n";
}


void IRPrinter::visit(Ref<const Move> op) { //YZW Done
    print_indent();
    (op->dst).visit_expr(this);
    if (op->move_type == MoveType::HostToDevice) {
        CHECK(0, "move type host_to_device is not supported.");
    } else if (op->move_type == MoveType::MemToShared) {
        CHECK(0, "move type mem_to_shared is not supported.");
    } else if (op->move_type == MoveType::SharedToMem) {
        CHECK(0, "move type shared_to_mem is not supported.");
    } else if (op->move_type == MoveType::MemToLocal) {
        CHECK(0, "move type mem_to_local is not supported.");
    } else if (op->move_type == MoveType::LocalToMem) {
        CHECK(0, "move type local_to_mem is not supported.");
    } else if (op->move_type == MoveType::SharedToLocal) {
        CHECK(0, "move type shared_to_local is not supported.");
    } else if (op->move_type == MoveType::LocalToShared) {
        CHECK(0, "move type local_to_shared is not supported.");
    } else if (op->move_type == MoveType::SharedToShared) {
        CHECK(0, "move type shared_to_shared is not supported.");
    } else if (op->move_type == MoveType::MemToMem) {
        oss << " += ";
    } else if (op->move_type == MoveType::LocalToLocal) {
        CHECK(0, "move type local_to_local is not supported.");
    }
    (op->src).visit_expr(this);
    oss << ";\n";
}


void IRPrinter::visit(Ref<const Kernel> op) { // YZW Done
    /**
     * because the function label is already given in kernel_casex.cc, We are
     * not going to generate that. Only the body will be generated.
     */

    for (auto stmt : op->stmt_list) {
        stmt.visit_stmt(this);
    }

}


}  // namespace Internal

}  // namespace Boost
