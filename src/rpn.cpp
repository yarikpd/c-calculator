#include <rpn.h>

#include <iostream>
#include <cmath>
#include <cstring>

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

bool has_operation(const char* expr) {
    for (int i = 0; expr[i]; ++i) {
        if (RPN::in_operations(expr[i])) {
            return true;
        }
    }
    return false;
}

bool RPN::evaluate_rpn(const char* expr) {
    double stack[32];
    int top = -1;
    int i = 0;
    while (expr[i]) {
        while (expr[i] == ' ') ++i;
        if (!expr[i]) {
            throw std::invalid_argument("Invalid expression");
        }

        if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
            char numbuf[32];
            int j = 0;
            while ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
                numbuf[j++] = expr[i++];
            }
            numbuf[j] = '\0';
            stack[++top] = std::stod(numbuf);
        } else {
            if (top < 1) {
                throw std::invalid_argument("RPN stack underflow");
            }
            const double b = stack[top--];
            const double a = stack[top--];
            double res = 0;

            switch (expr[i]) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        throw std::invalid_argument("Division by zero");
                    }
                    res = a / b;
                    break;
                case '^':
                    res = pow(a, b);
                    break;
                default:
                    throw std::invalid_argument("Invalid operator");
            }

            stack[++top] = res;
            ++i;
        }
    }
    if (top != 0) {
        throw std::invalid_argument("Invalid RPN expression");
    }

    std::cout << stack[top] << std::endl;
    return true;
}