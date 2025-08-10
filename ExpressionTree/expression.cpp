#include "expression.hpp"

Number::Number(double val) : value(val) {}

double Number::evaluate() const {
    return value;
}
    
void Number::print() const {
    std::cout << std::to_string(value);
    return;
}

Addition::Addition(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r)) {}
    
double Addition::evaluate() const {
    return left->evaluate() + right->evaluate();
}
    
void Addition::print() const {
    std::cout << "( ";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << " )";
    return;
}

 Multiplication::Multiplication(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r)) {}
    
double Multiplication::evaluate() const {
    return left->evaluate() * right->evaluate();
}
    
void Multiplication::print() const {
    std::cout << "( ";
    left->print();
    std::cout << " * ";
    right->print();
    std::cout << " )";
    return;
}

Subtraction::Subtraction(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r)) {}
    
double Subtraction::evaluate() const {
    return left->evaluate() - right->evaluate();
}
    
void Subtraction::print() const {
    std::cout << "( ";
    left->print();
    std::cout << " - ";
    right->print();
    std::cout << " )";
    return;
}
