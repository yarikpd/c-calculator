#include <iostream>
#include <cstdio>

#include "rpn.h"

int main() {
    double a, b;
    char op;
    char output[100];

    while (true) {
        std::cout << "Enter a, b, op (or 'e' as op to exit): ";
        std::cin >> a >> b >> op;

        if (op == 'e') {
            break;
        }

        if (const double result = evaluate_rpn(a, b, op); (op == '/' && b == 0) || (result == 0 && op != '+' && op != '-' && op != '*' && op != '/')) {
            std::cout << "Calculation error occurred." << std::endl;
        } else {
            std::sprintf(output, "%.2g %c %.2g = %.2g", a, op, b, result);
            std::cout << output << std::endl;
        }
    }

    return 0;
}