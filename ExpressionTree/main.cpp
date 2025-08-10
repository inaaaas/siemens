#include "expression.hpp"

int main() {
    //3 + (5 * 2)
    auto expr = std::make_unique<Addition>(
        std::make_unique<Number>(3),
        std::make_unique<Multiplication>(
            std::make_unique<Number>(5),
            std::make_unique<Number>(2)
        )
    );

     std::cout << "\nExpression: " << std::endl;
    expr->print();
    std::cout << "Result: " << expr->evaluate() << std::endl;
    ;

    //(10 - 4) * 2
    auto expr2 = std::make_unique<Multiplication>(
        std::make_unique<Subtraction>(
            std::make_unique<Number>(10),
            std::make_unique<Number>(4)
        ),
        std::make_unique<Number>(2));

    std::cout << "\nExpression: " << std::endl;
    expr2->print();
    std::cout << "Result: " << expr2->evaluate() << std::endl;
    
    return 0;
}