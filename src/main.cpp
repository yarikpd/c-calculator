#include <iostream>
#include <cstdio>

#include "history.h"
#include "rpn.h"

int main() {
    double a, b;
    char op;
    char output[100];
    bool running = true;

    History history;

    while (running) {
        std::cout << "Enter operation (+, -, *, /) or ('e' to exit, 'h' for history, 'c' to clear history): ";
        std::cin >> op;

        switch (op) {
            case 'e':
                running = false;
                break;
            case 'h':
                history.print();
                break;
            case 'c':
                history.clear();
                std::cout << "History cleared." << std::endl;
                break;
            default:
                std::cout << "Enter a, b: ";
                std::cin >> a >> b;

                if (const double result = evaluate_rpn(a, b, op); (op == '/' && b == 0) || (result == 0 && op != '+' && op != '-' && op != '*' && op != '/')) {
                    std::cout << "Calculation error occurred." << std::endl;
                } else {
                    std::sprintf(output, "%.2g %c %.2g = %.2g", a, op, b, result);
                    std::cout << output << std::endl;
                    history.add(output);
                }
        }

        std::cout << "----------" << std::endl;
    }

    return 0;
}