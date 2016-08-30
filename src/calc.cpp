#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <stdexcept>

#include <vector>
#include <stack>
#include <queue>

#include "../include/calc.h"

using namespace std;


//removes spacing and changes ',' to '.'
char* trim(string str) {
    char* str_new = new char[str.length()+1];
    char* p_new = str_new;

    for(string::iterator c = str.begin(); c != str.end(); c++) {
        if(*c == ' ') continue;

        if(*c == ',') *p_new = '.';
        else *p_new = *c;
        p_new++;
    }
    *p_new = '\0';
    return str_new;
}


double act(double op1, char op, double op2) {
    switch (op) {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1*op2;

        default:
            throw runtime_error("invalid format");
    }
}


int priority(const char c) {
    switch(c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;

    default:
        throw runtime_error("Symbol " + string(1, c) + " is invalid");
    }
}

double calc_stack(const char* str, const char** end) {
    vector<string> rpn;
    stack<string> ops;

    for (const char* c = str; *c != '\0'; c++) {
        if(*c == '(') {
            rpn.push_back(std::to_string(calc_stack(c+1, &c)));

        }
        else if(*c == ')') {
            *end = c;
            //todo check if braces are balanced
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

            ops.push(string(1, *c));

        }

    }
    while (!ops.empty()) {
        rpn.push_back(ops.top());
        ops.pop();
    }

    //the string is processed, now calculate from RPN

    stack<double> numbers;
    numbers.push(0); //handling initial minus sign

    for(string token: rpn) {
        cout << token << " ";
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
    cout << endl;

    return numbers.top();
}

int main()
{
    cout << "Enter expression and press <Enter>: " << endl;
    string str;
    getline(cin, str);
    cout << setprecision(2);

    try {
        cout << "result:" <<endl;
        cout << calc_stack(trim(str)) << endl;
    } catch(exception &e) {
        cout << "Couldn't calculate: " << e.what() << endl;
        return 1;
    }

    return 0;
}
