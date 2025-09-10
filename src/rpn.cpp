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

bool RPN::evaluate_rpn_expr(const char* expr, double& result) {
    double stack[32];
    int top = -1;
    int i = 0;
    while (expr[i]) {
        while (expr[i] == ' ') ++i;
        if (!expr[i]) break;

        if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
            char numbuf[32];
            int j = 0;
            while ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
                numbuf[j++] = expr[i++];
            }
            numbuf[j] = '\0';
            stack[++top] = std::atof(numbuf);
        } else {
            if (top < 1) return false;
            double b = stack[top--];
            double a = stack[top--];
            double res = 0;
            switch (expr[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': if (b == 0) return false; res = a / b; break;
                case '^': res = std::pow(a, b); break;
                default: return false;
            }
            stack[++top] = res;
            ++i;
        }
    }
    if (top != 0) return false;
    result = stack[top];
    return true;
}