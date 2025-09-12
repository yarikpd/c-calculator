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

bool has_operation(const char* expr) {
    for (int i = 0; expr[i]; ++i) {
        if (RPN::in_operations(expr[i])) {
            return true;
        }
    }
    return false;
}

bool decode(char* infix_buf, const std::size_t infix_buf_size, const double a, const double b, const char op) {
    char i_buf [64];

    if (!has_operation(infix_buf)) {
        std::snprintf(i_buf, 64, "(%.2g %c %.2g)", a, op, b);
    }
    else {
        std::snprintf(i_buf, 64, "%c %.2g)", op, b);
        std::snprintf(infix_buf, infix_buf_size, "(%s", infix_buf);
    }

    if (infix_buf && infix_buf_size > 0) {
        if (std::strlen(infix_buf) + std::strlen(i_buf) + 1 < infix_buf_size) {
            if (has_operation(infix_buf)) {
                std::strcat(infix_buf, " ");
            }
            std::strcat(infix_buf, i_buf);
        } else {
            return false;
        }
    }

    return true;
}

bool RPN::evaluate_rpn_expr(const char* expr, double& result, char* infix_buf, std::size_t infix_buf_size) {
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
            stack[++top] = std::stod(numbuf);
        } else {
            if (top < 1) return false;
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
                    if (b == 0) return false;
                    res = a / b;
                    break;
                case '^':
                    res = pow(a, b);
                    break;
                default: return false;
            }

            if (const bool done = decode(infix_buf, infix_buf_size, a, b, expr[i]); !done) return false;

            stack[++top] = res;
            ++i;
        }
    }
    if (top != 0) return false;
    result = stack[top];
    return true;
}