#ifndef CMATRIXPRO2_H
#define CMATRIXPRO2_H

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

class CMatrixPro2{
    // constructors
public:
    CMatrixPro2(int n = 2);                  
    CMatrixPro2(const CMatrixPro2 &M);       
    ~CMatrixPro2();                         

    int **allocateMatrixMemory(int n);     
    int getDimension(void);                
    int getElementAt(int i, int j);         
    int replaceElementAt(int i, int j, int newint); 
    void swapElementsAt(int i1, int j1, int i2, int j2); 
    void resizeMatrix(int newsize);         
    friend istream& operator >> (istream &in, CMatrixPro2 &M);                  
    friend ostream& operator << (ostream &out, CMatrixPro2 &M);                 
    void makeIdentity();                   
    CMatrixPro2& operator = (const CMatrixPro2 &M); 
    CMatrixPro2 operator +(const CMatrixPro2 &M);
    CMatrixPro2 operator + (int x);          
    CMatrixPro2 operator -(const CMatrixPro2 &M);
    CMatrixPro2 operator - (int x);
    CMatrixPro2 operator * (const CMatrixPro2 &M);
    CMatrixPro2 operator * (int x);
    bool isDiagonal(void);
    bool isIdentity(void);
    bool operator > (const CMatrixPro2 &M);
    bool operator < (const CMatrixPro2 &M); 
    bool operator == (const CMatrixPro2 &M);

    // Additional operators for Assignment 4
    CMatrixPro2& operator += (const CMatrixPro2 &M);
    CMatrixPro2& operator += (int x);
    CMatrixPro2& operator -= (const CMatrixPro2 &M);
    CMatrixPro2& operator -= (int x);
    CMatrixPro2& operator *= (const CMatrixPro2 &M);
    CMatrixPro2& operator *= (int x);

private:
    int Dimension;
    int **Matrix;
    void deallocateMatrixMemory(int **M, int n); 
};

#endif