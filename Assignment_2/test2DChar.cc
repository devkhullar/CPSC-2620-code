#include "2DChar.h"
#include <iostream>
#include <cctype>
using namespace std;

int main(){
    int m = 2, n = 3; 
    char **arr = Create2DChar(m, n);
    Input2DChar(arr, m, n);
    Print2DChar(arr, m, n);
    cout << "Let's see how many 1's there are in this matrix: " << Search(arr, m, n, '1') << endl;
    cout << "Let's see how many capital letters there are in this matrix: " << 
    CountUpper(arr, m, n) << endl;
    cout << "Let's see how many digits there are in this matrix: " << 
    CountDecimals(arr, m, n) << endl;
    cout << "Now, Letters: " << CountLetters(arr, m, n) << endl;
    cout << "Now, lowercase letters: " << CountLower(arr, m, n) << endl;
    
    char **new_arr = Transpose(arr, m, n);
    cout << "Let's see how the transpose looks!:" << endl;
    Print2DChar(new_arr, n, m);
    Delete2DChar(new_arr, n, m);
    return 0;

}

