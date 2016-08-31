//
// Created by anth on 8/30/16.
//
#include <gtest/gtest.h>

#include <stdexcept>
#include "../include/Calculator.h"

#define CALC_TEST(name) TEST(Group, name) {   }

CALC_TEST(Dummy)

TEST(Group, TestName) {
    std::string eq("1+3-2");
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), 2);
}


TEST(Calculator, CalculatesWithSpaces) {
    std::string eq = "1    +3  - 2";
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), 2);
}

TEST(Calculator, RegarsPriorities) {
    std::string eq = "2+2*2";
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), 6);
}

TEST(Calculator, ProcessBrackets) {
    std::string eq = "(3+(5-2))*7";
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), 42);
}

TEST(Calculator, ProcessMoreBrackets) {
    std::string eq = "(2 - 3*((8+(((4))) )) )";

}

TEST(Calculator, ExitsOnSymbols) {
    std::string eq = "3 + abc";
    ASSERT_THROW(Calculator::calculate(eq), std::runtime_error);
}

TEST(Calculator, DivisionByZero) {
    std::string eq = "5/0";
    ASSERT_THROW(Calculator::calculate(eq), std::runtime_error);
}

TEST(Calculator, InitialMinus) {
    std::string eq = "-5 + 8*(-3-1)";
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), -37);
}

TEST(Calculator, ImbalancedBrackets) {
    std::string eq = "(-3+(2))))";
    ASSERT_THROW(Calculator::calculate(eq), std::runtime_error);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


