// This is a test program to check the working of the Assignment 3 of CPSC 2620
// Date: 24 October 2024

#include <iostream>
#include "CMatrixExt.h"

using namespace std;

int main(){

    CMatrixExt A(3), B(3);
    cout << "Let's input some elements into the matrix A" << endl;
    A.readMatrix();
    cout << "Let's input some elements into the matrix B" << endl;
    B.readMatrix();

    cout << "This is how the 2 matrices look like" << endl;
    cout << "Matrix A: " << endl;
    A.printMatrix();
    cout << "And B: " << endl;
    B.printMatrix();

    cout << "Let's perform some operations on the two matrices" << endl;
    cout << "Let's add 5 to each element of matrix A and see how that looks"  << endl;
    CMatrixExt addedResult = A.addMatrix(5); 
    addedResult.printMatrix();

    cout << "Let's see how Matrix A looks like if we subtract B Matrix from A" << endl;
    CMatrixExt subtractedResult = A.subtractMatrix(B);
    subtractedResult.printMatrix();

    cout << "Let's multiply 1000 to each element of matrix A and see how that looks" << endl;
    CMatrixExt multipliedResult = A.multiplyMatrix(1000);
    multipliedResult.printMatrix();

    cout << "Let's turn A into an identity matrix and see how it looks" << endl;
    A.makeIdentity();
    A.printMatrix();

    cout << "I want to see if A is an identity matrix" << endl;
    cout << "Is A an identity matrix? [0: No, 1: Yes]: " << A.isIdentity() << endl;

    cout << "I want to see if B is bigger than A" << endl;
    cout << "Is B bigger than A? [0: No, 1: Yes]: " << B.isBigger(A) << endl;

    cout << "Lastly, I want to multiply Matrix A ";
    cout << "with Matrix B and see the result" << endl;
    CMatrixExt multipliedMatrix2 = A.multiplyMatrix(B);
    multipliedMatrix2.printMatrix();
    return 0;
}