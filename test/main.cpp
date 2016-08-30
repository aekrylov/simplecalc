//
// Created by anth on 8/30/16.
//
#include <gtest/gtest.h>
#include "../include/calc.h"
#include <string>

TEST(Calculator, CalculatesBasic) {

    std::string eq("1+3-2");
    ASSERT_DOUBLE_EQ(calc_stack(eq.c_str()), 2);
}

TEST(Calculator, Calculator_CalculatesWithSpaces_Test) {
    std::string eq = "1    +3  - 2";
    ASSERT_DOUBLE_EQ(calc_stack(eq.c_str()), 2);
}

TEST(Calculator, RegarsPriorities) {
    std::string eq = "2+2*2";
    ASSERT_DOUBLE_EQ(calc_stack(eq.c_str()), 6);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


