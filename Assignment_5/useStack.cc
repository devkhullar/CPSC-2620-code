// 2 December 2024
// CPSC 2620, Assignment 5, Question 2

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "CStack.h"
using namespace std;


bool evalRPN(const string& str, int& res){
    CStack<int>* first = nullptr;
    istringstream iss(str);
    string token;

    while (iss >> token){
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)){  // if the token is a number
            int num = stoi(token);
            first->push(first, num);
        }
        else if (token == "+" || token == "-" || token == "*"){
            if (first->size(first) < 2 || first == nullptr){  // to make sure that there are only 2 operatnds
                // cout << "Invalid RPN expression!" << endl;
                first->empty(first);
                return false;
            }

            // to pop the 2 operands on which we perform the operation
            int b = first->top(first); // the second number
            first->pop(first);
            int a = first->top(first); // the first number
            first->pop(first);

            int result = 0;  //
            if (token == "+") result = a + b;
            if (token == "-") result = a - b;
            if (token == "*") result = a * b;

            first->push(first,result);
        }
        else {
        first->empty(first);
        return false;
        }
    }
    
    if (first->size(first) != 1){ // invalid because we need only 1 number at the end
        first->empty(first);
        return false;
    }

    res = first->top(first);
    first->empty(first);
    return true;
    
}

int main() {
    ifstream infile("A5test.txt");
    if (!infile.is_open()) {
        cerr << "Error: Could not open A5test.txt" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        cout << "Expression: " << line << endl;
        int result = 0;

        if (evalRPN(line, result)) {
            cout << "Valid RPN expression. Result is " << result << "." << endl;
        } else {
            cout << "Invalid RPN expression!" << endl;
        }
    }

    infile.close(); // Close the file
    return 0;
}
