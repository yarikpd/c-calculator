#include <gtest/gtest.h>
#include "rpn.h"
#include <stdexcept>

TEST(RPNTest, BasicAddition) {
    EXPECT_DOUBLE_EQ(RPN::evaluate_rpn("2 3 +"), 5.0);
}

TEST(RPNTest, ComplexExpression) {
    EXPECT_NEAR(RPN::evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0, 1e-9);
}

TEST(RPNTest, DivisionByZero) {
    EXPECT_THROW(RPN::evaluate_rpn("1 0 /"), std::invalid_argument);
}

TEST(RPNTest, InvalidExpression) {
    EXPECT_THROW(RPN::evaluate_rpn("2 +"), std::invalid_argument);
}

TEST(RPNTest, Floor) {
    // Basic floor operation
    EXPECT_NEAR(RPN::evaluate_rpn("5.7 f"), 5.0, 1e-9);
    // Floor with negative number
    EXPECT_NEAR(RPN::evaluate_rpn("-3.2 f"), -4.0, 1e-9);
    // Floor in expression
    EXPECT_NEAR(RPN::evaluate_rpn("2.8 3.4 + f"), 6.0, 1e-9);
}

TEST(RPNTest, Ceil) {
    // Basic ceil operation
    EXPECT_NEAR(RPN::evaluate_rpn("5.1 c"), 6.0, 1e-9);
    // Ceil with negative number
    EXPECT_NEAR(RPN::evaluate_rpn("-3.2 c"), -3.0, 1e-9);
    // Ceil in expression
    EXPECT_NEAR(RPN::evaluate_rpn("2.3 1.1 + c"), 4.0, 1e-9);
}

TEST(RPNTest, Round) {
    // Basic round operation
    EXPECT_NEAR(RPN::evaluate_rpn("5.4 r"), 5.0, 1e-9);
    EXPECT_NEAR(RPN::evaluate_rpn("5.5 r"), 6.0, 1e-9);
    // Round with negative number
    EXPECT_NEAR(RPN::evaluate_rpn("-3.4 r"), -3.0, 1e-9);
    EXPECT_NEAR(RPN::evaluate_rpn("-3.5 r"), -4.0, 1e-9);
    // Round in expression
    EXPECT_NEAR(RPN::evaluate_rpn("2.3 1.1 + r"), 3.0, 1e-9);
}
