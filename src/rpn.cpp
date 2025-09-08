#include <rpn.h>

#include <iostream>

double evaluate_rpn(const double a, const double b, const char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Error: Division by zero" << std::endl;
                return 0; // or handle error as appropriate
            }
            return a / b;
        default:
            std::cerr << "Error: Unknown operator '" << op << "'" << std::endl;
            return 0; // or handle error as appropriate
    }
}