#ifndef MATRIX_H
#define MATRIX_H

class CMatrix{
public:
    // constructors
    CMatrix();      // default constructor, defaults to n = 2
    CMatrix(int size);           

    // input/output methods
    void readMatrix();
    void printMatrix();
    
    // Accessors    int replaceElementAt(int i, int j, int newint);
    int getDimension();
    int getElementAt(int i, int j);

    // Modifiers
    int replaceElementAt(int i, int j, int newint);
    void swapElementsAt(int i1, int j1, int i2, int j2);
    void resizeMatrix(int newsize);

    // Helper Functions to facilate memory allocation/deallocation
    void allocateMemory();
    void deallocateMemory();

private:
    int Dimension;     // the dimensions of the matrix, ie, m x m
    int **Matrix;      // 2D matrix
};

#endif