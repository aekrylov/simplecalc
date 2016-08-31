//
// Created by anth on 8/30/16.
//
#include <gtest/gtest.h>
#include "../include/Calculator.h"


TEST(Calculator, Basics) {
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
    ASSERT_DOUBLE_EQ(Calculator::calculate(eq), -34);
}

TEST(Calculator, HandlesDecimalPoints) {
    ASSERT_DOUBLE_EQ(Calculator::calculate(std::string("2.7")), 2.7);
    ASSERT_DOUBLE_EQ(Calculator::calculate(std::string("2,7")), 2.7);
}

TEST(Calculator, ExitsOnWrongSymbols) {
    std::string eq = "3 + abc";
    ASSERT_THROW(Calculator::calculate(eq), std::runtime_error);
}

TEST(Calculator, TellsWrongSymbol) {
    std::string ex1 = "5.8 + lorem";
    std::string ex2 = "3,7 ^ 2";

    try {
        Calculator::calculate(ex1);
        ASSERT_TRUE(false); //make sure that exception is thrown
    } catch (std::runtime_error &e) {
        ASSERT_STRCASEEQ(e.what(), "Symbol l is invalid");
    }

    try {
        Calculator::calculate(ex2);
        ASSERT_TRUE(false);
    } catch (std::runtime_error &e) {
        ASSERT_STRCASEEQ(e.what(), "Symbol ^ is invalid");
    }
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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


