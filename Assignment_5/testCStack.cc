#include <iostream>
#include "CStack.h"

using namespace std;

bool isBalanced(const string& str){
    CStack<char>* stack = nullptr;

    // to read the string, loop through the characters
    for (char ch : str){
        if (ch == ' '){
            continue;
        }

        // for the opening parenthesis case
        if (ch == '('){
            // push '(' on the stack 
            stack->push(stack, ch);
        }

        // for the closing parenthesis case
        else if (ch == ')'){
            // if empty stack points to nullptr or stack is empty, push it on to the stack 
            if (stack == nullptr || stack->isEmpty(stack)){
                return 0;
            }
            stack->pop(stack);
        }
    }
    // to check if the stack is empty at the end
    bool result = (stack == nullptr || stack->isEmpty(stack));

    return result;
}

int main(){

    cout << "To check if the stack using parenthesis works" << endl;

    string str = "(  )()";
    cout << "for case: " << str << ": ";
    CStack<string>* first = nullptr;
    if (isBalanced(str)){
        cout << "The parenthesis are balanced" << endl;
    } else {
        cout << "They are not balanced" << endl;
    }

    string str2 = ")()()";
     cout << "for case: " << str2 << ": ";
    if (isBalanced(str2)){
        cout << "The parenthesis are balanced" << endl;
    } else {
        cout << "They are not balanced" << endl;
    }

    string str3 = "())()())()()";
     cout << "for case: " << str3 << ": ";
    if (isBalanced(str3)){
        cout << "The parenthesis are balanced" << endl;
    } else {
        cout << "They are not balanced" << endl;
    }

    string str4 = ")   ";
     cout << "for case: " << str4 << ": ";
    if (isBalanced(str4)){
        cout << "The parenthesis are balanced" << endl;
    } else {
        cout << "They are not balanced" << endl;
    }

    cout << endl << endl;

    cout << "Let's push some strings" << endl;
    string s1 = "hello world";
    string s2 = "I have a dog";
    string s3 = "I am taking cpsc 2620";
    string s4 = "I like coding";
    cout << "The strings are" << endl;
    cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
    first->push(first, s1);
    first->push(first, s2);
    first->push(first, s3);
    first->push(first, s4);

    cout << "Size: " << first->size(first) << endl;
    cout << "Top: " << first->top(first) << endl;    
    cout << "popping now." << endl;
    first->pop(first);
    cout << "Size: " << first->size(first) << endl;

    cout << "Is the stack empty?: " << first->isEmpty(first) << endl;

    cout << endl << endl;

    cout << "Let's see if the stack works for integers" << endl;
    CStack<int>* intStack = nullptr;
    int d1 = 289, d2 = 829, d3 = 242, d4 = 5346;
    cout << "Pushing " << d1 << ", " << d2 << ", " << d3 << ", " << d4
        << " onto the stack." << endl;
    intStack->push(intStack, d1);
    intStack->push(intStack, d2);
    intStack->push(intStack, d3);
    intStack->push(intStack, d4);
    cout << "Is the intStack empty?: " << intStack->isEmpty(intStack) << endl;
    cout << "Top element?: " << intStack->top(intStack) << endl;
    cout << "Size of intStack: " << intStack->size(intStack) << endl;
    cout << "popping " << d4 << " and " << d3 << endl;
    intStack->pop(intStack);
    intStack->pop(intStack);
    cout << "Size now?: " << intStack->size(intStack) << endl;
    cout << "Top element: " << intStack->top(intStack) << endl;
    cout << "Let's empty the stack now" << endl;
    intStack->empty(intStack);
    cout << "Size now?: " << intStack->size(intStack) << endl;
    cout << "That's all for today :)" << endl;
    return 0;
}