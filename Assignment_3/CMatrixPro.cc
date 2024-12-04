#include <iostream>
#include <iomanip>
#include <cassert>
#include "CMatrixPro.h"
using namespace std;

// allocateMatrixMemory: helper function to allocate memory to Matrix Object
int ** CMatrixPro::allocateMatrixMemory(int n){
    int ** matrix = new int *[n];
    for (int i = 0; i < n; i++){
            matrix[i] = new int [n];
    }
    return matrix;
}

// deallocateMatrixMemory: helped function to deallocate memory
void CMatrixPro::deallocateMatrixMemory(int **M, int n){
    for (int i = 0; i < n; i++){
        delete [] M[i];
    }
    delete[] M;
    M = nullptr;
}

// Constructors:

// Default Constructor
CMatrixPro::CMatrixPro(int n): Dimension(n){
    Matrix = allocateMatrixMemory(Dimension);  // Allocate memory for the matrix
}

// Copy Constructor
CMatrixPro::CMatrixPro(const CMatrixPro &M){
    Dimension = M.Dimension;
    Matrix = allocateMatrixMemory(Dimension);
    for (int i = 0; i < Dimension; i++){
        for (int j = 0; j < Dimension; j++){
            Matrix[i][j] = M.Matrix[i][j];
        }
    }
}

// Destructor
CMatrixPro::~CMatrixPro(){
    deallocateMatrixMemory(Matrix, Dimension);
}

// Method which returns the dimension of the matrix.
int CMatrixPro::getDimension(void){
    return this->Dimension;
}

// Method to print just one element of a matrix.
int CMatrixPro::getElementAt(int i, int j){
    assert(i >= 1 && i <= Dimension && j >= 1 && j <= Dimension);
    return Matrix[i-1][j-1];    
}

// Method to replace an element at index [i][j].
int CMatrixPro::replaceElementAt(int i, int j, int newint){
    assert(i >=1 && i <= Dimension && j >= 1 && j <= Dimension);
    int temp = Matrix[i-1][j-1];
    Matrix[i-1][j-1] = newint;
    return temp; 
}

// Method to swap an element located at the index [i1 - 1][j1 - 1] with
// the element at the index [i2 - 1][j2 - 1].
void CMatrixPro::swapElementsAt(int i1, int j1, int i2, int j2){
    assert(i1 >= 1 && i1 <= Dimension && j1 >= 1 && j1 <= Dimension);
    assert(i2 >= 1 && i2 <= Dimension && j2 >= 1 && j2 <= Dimension);
    int temp = Matrix[i1 - 1][j1 - 1];
    Matrix[i1 - 1][j1 - 1] = Matrix[i2 - 1][j2 - 1];
    Matrix[i2 - 1][j2 - 1] = temp;
}

// Method to resize the matrix, the new elements will
// be initialised to 0.
void CMatrixPro::resizeMatrix(int newsize){
    assert(newsize > 0);
    int **newMatrix = new int * [newsize];
    for (int i = 0; i < newsize; ++i) {
        newMatrix[i] = new int [newsize];
    }

    for (int i = 0; i < newsize; ++i) {
        for (int j = 0; j < newsize; ++j) {
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
istream& operator >> (istream &in, CMatrixPro &M){
    for (int i = 0; i < M.Dimension; ++i){
        for (int j = 0; j < M.Dimension; ++j){
            cout << "Input element at [" << i + 1 << ", " << j + 1 << "]: ";
            in >> M.Matrix[i][j];
        }
    }  
    return in;  
}

// Method to print out the Matrix.
ostream& operator << (ostream &out, CMatrixPro &M){
    for (int i = 0; i < M.Dimension; ++i) {
        for (int j = 0; j < M.Dimension; ++j){
            out << setw(5) <<  M.Matrix[i][j];
        }
        out << endl;
    }
    cout << "Done Reading" << endl;
    return out;
}

// Method to make the Matrix into an identity matrix.
void CMatrixPro::makeIdentity(){
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
CMatrixPro& CMatrixPro::operator = (const CMatrixPro &M){
    assert(this->Dimension == M.Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            this->Matrix[i][j] = M.Matrix[i][j];
        }
    }
    return *this;
}

// Method to add the current matrix to a new matrix.
CMatrixPro CMatrixPro::operator + (const CMatrixPro &M){
    assert(this->Dimension == M.Dimension);
    CMatrixPro result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] + M.Matrix[i][j];
        }
    }
    return result;
}

// Mehthod to add an integer to every element of the matrix.
CMatrixPro CMatrixPro::operator + (int x){
    CMatrixPro result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] + x;
        }
    }
    return result;
}

// Method to subtract a matrix from another matrix.
CMatrixPro CMatrixPro::operator - (const CMatrixPro &M){
    assert(this->Dimension == M.Dimension);
    CMatrixPro result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] - M.Matrix[i][j]; 
        }
    }
    return result;
}

// Method to subtract a integer from every element of a matrix.
CMatrixPro CMatrixPro::operator - (int x){
    CMatrixPro result(this->Dimension);
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
CMatrixPro CMatrixPro::operator * (const CMatrixPro &M){
    assert(this->Dimension == M.Dimension);
    CMatrixPro result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] * M.Matrix[i][j]; 
        }
    }
    return result;
}

// Mehod to multiply an integer to every element of a matrix.
CMatrixPro CMatrixPro::operator * (int x){
    CMatrixPro result(this->Dimension);
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            result.Matrix[i][j] = this->Matrix[i][j] * x;
        }
    }
    return result;   
}

// Method which returns true if matrix is a diagonal matrix
bool CMatrixPro::isDiagonal(void) {
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
bool CMatrixPro::isIdentity(void){
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
bool CMatrixPro::operator > (const CMatrixPro &M){
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
bool CMatrixPro::operator < (const CMatrixPro &M){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (this->Matrix[i][j] >= M.Matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

// Method to check whether the current matrix is equal to the matrix 
// compared to. 
bool CMatrixPro::operator == (const CMatrixPro &M){
    for (int i = 0; i < this->Dimension; i++){
        for (int j = 0; j < this->Dimension; j++){
            if (this->Matrix[i][j] != M.Matrix[i][j]){
                return false;
            }
        }
    }
    return true;    
}