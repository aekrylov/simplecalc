//
// Created by anth on 8/31/16.
//

#include <vector>
#include <stack>
#include <stdexcept>
#include <cmath>
#include "../include/Calculator.h"

double Calculator::calculate(const char *str, const char **end) {
    std::vector<std::string> rpn;
    std::stack<std::string> ops;

    for (const char* c = str; *c != '\0'; c++) {
        if(*c == '(') {
            rpn.push_back(std::to_string(calculate(c+1, &c)));

        }
        else if(*c == ')') {
            if(end == 0) { //end pointer not passed
                throw std::runtime_error("brackets imbalance");
            }
            *end = c;
            break;
        }
        else if(isdigit(*c)) { //beginning of a number
            double number = ::strtod(c, (char **) &c);
            c--;
            rpn.push_back(std::to_string(number));

        }
        else {
            int p = priority(*c);
            while(!ops.empty() && priority(ops.top()[0]) >= p) {
                rpn.push_back(ops.top());
                ops.pop();
            }

            ops.push(std::string(1, *c));

        }

    }
    while (!ops.empty()) {
        rpn.push_back(ops.top());
        ops.pop();
    }

    //the string is processed, now calculate from RPN

    std::stack<double> numbers;
    numbers.push(0); //handling initial minus sign

    for(std::string token: rpn) {
        if(isdigit(token[0]) || token.length() > 1) {
            numbers.push(stod(token));
        } else {
            double op2 = numbers.top();
            numbers.pop();
            double op1 = numbers.top();
            numbers.pop();

            numbers.push(act(op1, token[0], op2));
        }
    }

    return numbers.top();

}

char* Calculator::trim(std::string str) {
    char* str_new = new char[str.length()+1];
    char* p_new = str_new;

    for(std::string::iterator c = str.begin(); c != str.end(); c++) {
        if(isspace(*c)) continue;

        if(*c == ',') *p_new = '.';
        else *p_new = *c;
        p_new++;
    }
    *p_new = '\0';
    return str_new;
}

double Calculator::calculate(std::string str) {
    return calculate(trim(str));
}

int Calculator::priority(const char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;

        default:
            throw std::runtime_error("Symbol " + std::string(1, c) + " is invalid");
    }

}

double Calculator::act(double op1, char op, double op2) {
    switch (op) {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            if(std::fpclassify(op2) == FP_ZERO) {
                throw std::runtime_error("division by zero");
            }
            return op1/op2;
        default:break;
    }

}
