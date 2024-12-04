#ifndef CMATRIXPRO_H
#define CMATRIXPRO_H

# include <iostream>
using namespace std;

class CMatrixPro{
    public:
        // constructors
        CMatrixPro(int n = 2);                  
        CMatrixPro(const CMatrixPro &M);       
        ~CMatrixPro();                         

        int **allocateMatrixMemory(int n);     


        int getDimension(void);                
        int getElementAt(int i, int j);         
        int replaceElementAt(int i, int j, int newint); 
        void swapElementsAt(int i1, int j1, int i2, int j2); 
        void resizeMatrix(int newsize);         
        friend istream& operator >> (istream &in, CMatrixPro &M);                  
        friend ostream& operator << (ostream &out, CMatrixPro &M);                 
        void makeIdentity();                   
        CMatrixPro& operator = (const CMatrixPro &M); 
        CMatrixPro operator +(const CMatrixPro &M);
        CMatrixPro operator + (int x);          
        CMatrixPro operator -(const CMatrixPro &M);
        CMatrixPro operator - (int x);
        CMatrixPro operator * (const CMatrixPro &M);
        CMatrixPro operator * (int x);
        bool isDiagonal(void);
        bool isIdentity(void);
        bool operator > (const CMatrixPro &M);
        bool operator < (const CMatrixPro &M);
        bool operator == (const CMatrixPro &M);
    private:
        int Dimension;
        int **Matrix;
        void deallocateMatrixMemory(int **M, int n); 
};

#endif 