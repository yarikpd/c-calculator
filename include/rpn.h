#ifndef RPN_CALCULATOR_RPN_H
#define RPN_CALCULATOR_RPN_H

class RPN {
    const char operations[5] = {
        '+', '-', '*', '/', '^'
    };
    const int count_operations = sizeof(operations) / sizeof(operations[0]);

public:
    static void print_operations(const char separator[] = " ");

    static bool in_operations(char op);
    static double evaluate_rpn(const char* rpn);
};

#endif