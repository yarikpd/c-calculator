#include <iostream>

#include "rpn.h"

int main() {
    while (true) {
        char expr[256];
        std::cin.getline(expr, 256);

        RPN::evaluate_rpn(expr);
    }

    return 0;
}
