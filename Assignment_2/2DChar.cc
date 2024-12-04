#include "2DChar.h"
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

// Function to create a 2D array
char **Create2DChar(int m, int n){
    // allocating memory for the new pointer
    char **testPtr = new char *[m];
    for (int i = 0; i < m; i++){
        testPtr[i] = new char[n];
    }
    return testPtr;
}

// Function to delete a 2D array
void Delete2DChar(char **arr, int m, int n){
    for (int i = 0; i < m; i++){
        delete [] arr[i];
    }
    delete [] arr;
    // arr = nullptr : I am not sure if I am supposed to do this
}

// Function to search an element in a 2D array
int Search(char **arr, int m, int n, char c){
    int count = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (arr[i][j] == c){
                count++;
            }    
        }
    }
    return count;
}

// Function to print a 2D array
void Print2DChar(char **arr, int m, int n){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

// Function to find the count of 
// upper case letters in the 2D array
int CountUpper(char **arr, int m, int n){
    char ch;
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ch = arr[i][j];
            if (isupper(ch)){
                count++;
            }
        }
    }
    return count;
}

// Function to find the count of 
// lower case letters in the 2D array
int CountLower(char **arr, int m, int n){
    char ch;
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ch = arr[i][j];
            if (islower(ch)){
                count++;
            }
        }
    }
    return count;
}

// Function to find the count of 
// letters in the 2D array
int CountLetters(char **arr, int m, int n){
    char ch;
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ch = arr[i][j];
            if (isalpha(ch)){
                count++;
            }
        }
    }
    return count;
}

// Function to find the count of 
// decimals in the 2D array
int CountDecimals(char **arr, int m, int n){
    char ch;
    int count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ch = arr[i][j];
            if (isdigit(ch)){
                count++;
            }
        }
    }
    return count;
}

// Function to input the elements of a 2D array
void Input2DChar(char **arr, int m, int n){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout << "[" << i << "," << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Function to find the transpose of the 2D array
char **Transpose(char **arr, int m, int n){
    char **temp = Create2DChar(n, m);
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
           temp[j][i] = arr[i][j];  // flips rows and columns
        }
    }
    Delete2DChar(arr, m, n); // Deallocates memory from the old array
    return temp;
}