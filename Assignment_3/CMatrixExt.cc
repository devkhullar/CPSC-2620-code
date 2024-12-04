// This file contains the implementation of the class CMatrixExt submitted for
// assignment 3 of the Course CPSC 2620 
// Date: 24 October 2024

#include <iostream>
#include <iomanip>
#include <cassert>
#include "CMatrixExt.h"
using namespace std;

// allocateMatrixMemory: helper function to allocate memory to Matrix Object
int ** CMatrixExt::allocateMatrixMemory(int n){
    int ** matrix = new int *[n];
    for (int i = 0; i < n; i++){
            matrix[i] = new int [n];
    }
    return matrix;
}

// deallocateMatrixMemory: helper function to deallocate memory
void CMatrixExt::deallocateMatrixMemory(int **M, int n){
    for (int i = 0; i < n; i++){
        delete [] M[i];
    }
    delete[] M;
    M = nullptr;
}

// Constructors:

// Default Constructor
CMatrixExt::CMatrixExt(int n): Dimension(n){
    Matrix = allocateMatrixMemory(Dimension);  // Allocate memory for the matrix
}

// Copy Constructor
CMatrixExt::CMatrixExt(const CMatrixExt &M){
    Dimension = M.Dimension;
    Matrix = allocateMatrixMemory(Dimension);
    for (int i = 0; i < Dimension; i++){
        for (int j = 0; j < Dimension; j++){
            Matrix[i][j] = M.Matrix[i][j];
        }
    }
}

// Destructor
CMatrixExt::~CMatrixExt(){
    deallocateMatrixMemory(Matrix, Dimension);
}

// Method which returns the dimension of the matrix.
int CMatrixExt::getDimension(void){
    return this->Dimension;
}

// Method to print just one element of a matrix.
int CMatrixExt::getElementAt(int i, int j){
    assert(i >= 1 && i <= Dimension && j >= 1 && j <= Dimension);
    return Matrix[i-1][j-1];    
}

// Method to replace an element at index [i][j].
int CMatrixExt::replaceElementAt(int i, int j, int newint){
    assert(i >=1 && i <= Dimension && j >= 1 && j <= Dimension);
    int temp = Matrix[i-1][j-1];
    Matrix[i-1][j-1] = newint;
    return temp; 
}

// Method to swap an element located at the index [i1 - 1][j1 - 1] with
// the element at the index [i2 - 1][j2 - 1].
void CMatrixExt::swapElementsAt(int i1, int j1, int i2, int j2){
    assert(i1 >= 1 && i1 <= Dimension && j1 >= 1 && j1 <= Dimension);
    assert(i2 >= 1 && i2 <= Dimension && j2 >= 1 && j2 <= Dimension);
    int temp = Matrix[i1 - 1][j1 - 1];
    Matrix[i1 - 1][j1 - 1] = Matrix[i2 - 1][j2 - 1];
    Matrix[i2 - 1][j2 - 1] = temp;
}

// Method to resize the matrix, the new elements will
// be initialised to 0.
void CMatrixExt::resizeMatrix(int newsize){
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
    deallocateMatrixMemory(Matrix, Dimension);

    Matrix = newMatrix;
    Dimension = newsize;
}

// Method to read the elements of the Matrix.
void CMatrixExt::readMatrix(void){
    for (int i = 0; i < Dimension; ++i){
        for (int j = 0; j < Dimension; ++j){
            cout << "Input element at [" << i + 1<< ", " << j + 1 << "]: ";
            cin >> Matrix[i][j];
        }
    }    
}

// Method to print out the Matrix.
void CMatrixExt::printMatrix(void){
    for (int i = 0; i < Dimension; ++i) {
        for (int j = 0; j < Dimension; ++j){
            cout << setw(5) <<  Matrix[i][j];
        }
        cout << endl;
    }
    cout << "Done Reading" << endl;
}

// Method to make the Matrix into an identity matrix.
void CMatrixExt::makeIdentity(){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (i == j){
                this->Matrix[i][j] = 1;
            }
            else {
                this->Matrix[i][j] = 0;
            }
        }
    }
}

// Method to copy the current matrix to a new matrix.
void CMatrixExt::copyMatrix(const CMatrixExt &M){
    assert(this->Dimension == M.Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            this->Matrix[i][j] = M.Matrix[i][j];
        }
    }
}

// Method to add the current matrix to a new matrix.
CMatrixExt CMatrixExt::addMatrix(const CMatrixExt &M){
    CMatrixExt result(this->Dimension);
    assert(this->Dimension == M.Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] + M.Matrix[i][j];
        }
    }
    return result;
}

// Mehthod to add an integer to every element of the matrix.
CMatrixExt CMatrixExt::addMatrix(int x){
    CMatrixExt result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] + x;
        }
    }
    return result;
}

// Method to subtract a matrix from another matrix.
CMatrixExt CMatrixExt::subtractMatrix(const CMatrixExt &M){
    assert(this->Dimension == M.Dimension);
    CMatrixExt result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] - M.Matrix[i][j]; 
        }
    }
    return result;
}

// Method to subtract a integer from every element of a matrix.
CMatrixExt CMatrixExt::subtractMatrix(int x){
    CMatrixExt result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] - x;
        }
    }
    return result;    
}

// Method to multiply A matrix with another Matrix
// This method assumes that we are just multiplying the element at [i][j] of the 
// original matrix with the element at [i][j] of the matrix given in the parameter.
CMatrixExt CMatrixExt::multiplyMatrix(const CMatrixExt &M){
    assert(this->Dimension == M.Dimension);
    CMatrixExt result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] * M.Matrix[i][j]; 
        }
    }
    return result;
}

// Mehod to multiply an integer to every element of a matrix.
CMatrixExt CMatrixExt::multiplyMatrix(int x){
    CMatrixExt result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] * x;
        }
    }
    return result;   
}

// Method which returns true if matrix is a diagonal matrix
bool CMatrixExt::isDiagonal(void) {
    for (int i = 0; i < this->Dimension; i++) {
        for (int j = 0; j < this->Dimension; j++) {
            if (i != j && this->Matrix[i][j] != 0) {
                return false;  
            }
        }
    }
    return true; 
}

// Method which returns true if Matrix is an identity matrix
bool CMatrixExt::isIdentity(void){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (i == j){
                if (this->Matrix[i][j] != 1){
                    return false;
                }
            }
            else {
                if (this->Matrix[i][j] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

// Method to check whether the current matrix is bigger
// than the matrix compared to.
bool CMatrixExt::isBigger(const CMatrixExt &M){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (this->Matrix[i][j] <= M.Matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

// Method to check whether the current matrix is smaller than 
// the matrix compared to. 
bool CMatrixExt::isSmaller(const CMatrixExt &M){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (this->Matrix[i][j] >= M.Matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

// Mehtod to check whether the current matrix is equal to the matrix 
// compared to. 
bool CMatrixExt::isEqual(const CMatrixExt &M){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (this->Matrix[i][j] != M.Matrix[i][j]){
                return false;
            }
        }
    }
    return true;    
}
