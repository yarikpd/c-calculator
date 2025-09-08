#include <rpn.h>

#include <iostream>
#include <cmath>

bool RPN::in_operations(const char op) {
    for (const char operation : RPN().operations) {
        if (operation == op) {
            return true;
        }
    }
    return false;
}

void RPN::print_operations(const char separator[]) {
    for (int i = 0; i < RPN().count_operations; ++i) {
        std::cout << RPN().operations[i];
        if (i < RPN().count_operations - 1) {
            std::cout << separator;
        }
    }
}

double RPN::evaluate_rpn(const double a, const double b, const char op) {
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
        case '^':
            return pow(a, b);
        default:
            std::cerr << "Error: Unknown operator '" << op << "'" << std::endl;
            return 0; // or handle error as appropriate
    }
}