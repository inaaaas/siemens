#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual void print() const = 0;
    virtual ~Expression() = default;
};

class Number : public Expression {
    double value;
public:
    Number(double val);
    double evaluate() const override;
    void print() const override;
};

class Addition : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:    
    Addition(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r);
    double evaluate() const override;
    void print() const override;
};

class Multiplication : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    Multiplication(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r);
    double evaluate() const override;
    void print() const override;
};

class Subtraction : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    Subtraction(std::unique_ptr<Expression> l,  std::unique_ptr<Expression> r);
    double evaluate() const override;
    void print() const override;
};


#endif