#ifndef RPN_CALCULATOR_RPN_H
#define RPN_CALCULATOR_RPN_H

/**
 * @class RPN
 * @brief Provides functionality for evaluating mathematical expressions in Reverse Polish Notation (RPN).
 *
 * This class includes methods to print supported operations, check if a character is a valid operation,
 * and evaluate RPN expressions. It is designed for use in an RPN calculator.
 */
class RPN {
    const char operations[8] = {
        '+', '-', '*', '/', '^', 'f', 'c', 'r'
    };
    const int count_operations = sizeof(operations) / sizeof(operations[0]);

public:
    /**
     * @brief Prints all supported operations.
     *
     * @param separator A string to use as separator between operations when printing.
     */
    static void print_operations(const char separator[] = " ");

    /**
     * @brief Checks if a character is a supported operation.
     *
     * @param op The character to check.
     * @return bool True if the character is in the supported operations list, false otherwise.
     */
    static bool in_operations(char op);

/**
* @brief Evaluates a mathematical expression in Reverse Polish Notation (RPN).
*
* @param expression A string containing the RPN expression (e.g., "2 3 +").
* Tokens must be separated by spaces.
* @return double The result of the evaluated expression.
* @exception std::invalid_argument Thrown if the expression is invalid,
* contains an unknown operator, or attempts division by zero.
*/
    static double evaluate_rpn(const char* rpn);
};

#endif