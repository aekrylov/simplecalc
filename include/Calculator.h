//
// Created by anth on 8/31/16.
//

#ifndef SIMPLECALC_CALCULATOR_H
#define SIMPLECALC_CALCULATOR_H

#include <string>

class Calculator {
public:
    static double calculate(std::string str);

private:
    static char* trim(std::string str);
    static double calculate(const char* str, const char** end = 0);
    static int priority(const char);
    static double act(double, char, double);

};


#endif //SIMPLECALC_CALCULATOR_H
