#include <iostream>

#include "history.h"
#include "rpn.h"

int main() {
    char op;
    bool running = true;

    History history;

    while (running) {
        std::cout << "Enter operation ('e' to exit, 'h' for history, 'c' to clear history, 'r' to do RPN operation): ";
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
            case 'r': {
                std::cout << "Enter RPN expression: ";
                char expr[256];
                std::cin.ignore();
                std::cin.getline(expr, 256);

                const double result = RPN::evaluate_rpn(expr);
                char output[300];

                std::sprintf(output, "%s = %.3g", expr, result);
                std::cout << output << std::endl;
                history.add(output);

                break;
            }
            default:
                std::cerr << "Error: Unknown operator '" << op << "'" << std::endl;
                std::cout << "Invalid operation." << std::endl;
                break;
        }

        std::cout << "----------" << std::endl;
    }

    return 0;
}
