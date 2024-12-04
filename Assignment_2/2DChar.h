#ifndef _2DCHAR_H
#define _2DCHAR_H

char **Create2DChar(int m, int n);
void Delete2DChar(char **arr, int m, int n);
int Search(char **arr, int m, int n, char c);
void Print2DChar(char **arr, int m, int n);
int CountUpper(char **arr, int m, int n);
int CountLower(char **arr, int m, int n);
int CountLetters(char **arr, int m, int n);
int CountDecimals(char **arr, int m, int n);
void Input2DChar(char **arr, int m, int n);
char **Transpose(char **arr, int m, int n);

#endif