#include <iostream>
#include <cassert>
#include <iomanip>
#include "matrix.h"

using namespace std;

// Default Constructor, sets Dimension = 2 by default
CMatrix::CMatrix() {
    Dimension = 2;
    allocateMemory();    
}

// Constructor to declare the size of the matrix
CMatrix::CMatrix(int size){
    Dimension = size;
    allocateMemory();
}

// Helper Functions to allocate/deallocate memory
void CMatrix::allocateMemory() {
    Matrix = new int * [Dimension];
    for (int i = 0; i < Dimension; ++i){
        Matrix[i] = new int[Dimension];
    }
}

void CMatrix::deallocateMemory() {
    for (int i = 0; i < Dimension; ++i) {
        delete [] Matrix[i];
    }
    delete [] Matrix;
}

// method to get input for the matrix elements
void CMatrix::readMatrix(){
    for (int i = 0; i < Dimension; ++i){
        for (int j = 0; j < Dimension; ++j){
            cout << "Input element at [" << i + 1<< ", " << j + 1 << "]: ";
            cin >> Matrix[i][j];
        }
    }
}

// method to get the dimension of the matrix
int CMatrix::getDimension() {
    return Dimension;
}

// method to get an element
int CMatrix::getElementAt(int i, int j){
    assert(i >= 1 && i <= Dimension && j >= 1 && j <= Dimension);
    return Matrix[i-1][j-1];
}

// method to replace an element with a new element
int CMatrix::replaceElementAt(int i, int j, int newint){
    assert(i >=1 && i <= Dimension && j >= 1 && j <= Dimension);
    int temp = Matrix[i-1][j-1];
    Matrix[i-1][j-1] = newint;
    return temp; // the questions asks to return the old element at (i, j)
}
// Method to swap elements 
void CMatrix::swapElementsAt(int i1, int j1, int i2, int j2){
    assert(i1 >= 1 && i1 <= Dimension && j1 >= 1 && j1 <= Dimension);
    assert(i2 >= 1 && i2 <= Dimension && j2 >= 1 && j2 <= Dimension);
    int temp = Matrix[i1 - 1][j1 - 1];
    Matrix[i1 - 1][j1 - 1] = Matrix[i2 - 1][j2 - 1];
    Matrix[i2 - 1][j2 - 1] = temp;
}

// Method to print out the matrix
void CMatrix::printMatrix() {
    for (int i = 0; i < Dimension; ++i) {
        for (int j = 0; j < Dimension; ++j){
            cout << setw(5) <<  Matrix[i][j];
        }
        cout << endl;
    }
cout << "Done Reading" << endl;
}

void CMatrix::resizeMatrix(int newsize){
    assert(newsize > 0);
    int **newMatrix = new int * [newsize];
    for (int i = 0; i < newsize; ++i) {
        newMatrix[i] = new int [newsize];
    }

    for (int i = 0; i < newsize; ++i) {
        for (int j = 0; j < Dimension; ++j) {
            if (i < Dimension && j < Dimension) {
                newMatrix[i][j] = Matrix[i][j];
            }
            else {
                newMatrix[i][j] = 0;
            }
        }
    }
    deallocateMemory();

    Matrix = newMatrix;
    Dimension = newsize;
}