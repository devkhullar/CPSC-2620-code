// This file contains the definition of the class CMatrix submitted for the assignment 3
// of the course CPSC 2620
// Date: 24 October 2024

#ifndef CMATRIXEXT_H
#define CMATRIXEXT_H

class CMatrixExt{
    public:
        // constructors
        CMatrixExt(int n = 2);                  
        CMatrixExt(const CMatrixExt &M);       
        ~CMatrixExt();                         

        int **allocateMatrixMemory(int n);     


        int getDimension(void);                
        int getElementAt(int i, int j);         
        int replaceElementAt(int i, int j, int newint); 
        void swapElementsAt(int i1, int j1, int i2, int j2); 
        void resizeMatrix(int newsize);         
        void readMatrix(void);                  
        void printMatrix(void);                 
        void makeIdentity();                   
        void copyMatrix(const CMatrixExt &M); 
        CMatrixExt addMatrix(const CMatrixExt &M);
        CMatrixExt addMatrix(int x);          
        CMatrixExt subtractMatrix(const CMatrixExt &M);
        CMatrixExt subtractMatrix(int x);
        CMatrixExt multiplyMatrix(const CMatrixExt &M);
        CMatrixExt multiplyMatrix(int x);
        bool isDiagonal(void);
        bool isIdentity(void);
        bool isBigger(const CMatrixExt &M);
        bool isSmaller(const CMatrixExt &M);
        bool isEqual(const CMatrixExt &M);
    private:
        int Dimension;
        int **Matrix;
        void deallocateMatrixMemory(int **M, int n); 
};

#endif