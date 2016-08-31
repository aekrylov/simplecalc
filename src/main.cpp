//
// Created by anth on 8/30/16.
//

#include <iostream>
#include "../include/Calculator.h"

using namespace std;

int main() {
    cout << "Enter expression and press <Enter>: " << endl;
    string str;
    getline(cin, str);

    cout.precision(2);
    cout << fixed;

    try {
        cout << "result:" << endl;
        cout << Calculator::calculate(str) << endl;
    } catch (exception &e) {
        cout << "Couldn't calculate: " << e.what() << endl;
        return 1;
    }

    return 0;
}
