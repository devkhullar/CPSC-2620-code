// client testing program for the CMatrix Class
#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    // testing the 2 constructors
    cout << "Testing the 2 constructors" << endl;
    int n = 4;

    CMatrix B(n);
    cout << "Inputing the elements:" << endl;
    B.readMatrix();
    
    cout << "Printing out the Matrix"<< endl;
    B.printMatrix();

    cout << "let's try out replacing some elements:" << endl;
    int a = 1, b = 2, c = 134;
    cout << "Let's replace Matrix[" << a << ", " << b << "] with" << c << endl;
    B.replaceElementAt(a, b, c);
    cout << "Matrix[" << a << ", " << b << "]" << " is now: ";
    cout << B.getElementAt(1, 2) << endl;
    a = 4, b = 3, c =  89;
    cout << "Let's replace Matrix[" << a << ", " << b << "] with" << c << endl;
    B.replaceElementAt(a, b, c);
    cout << "Matrix[" << a << ", " << b << "]" << " is now: ";
    cout << B.getElementAt(1, 2) << endl;    


    cout << "Let's try swapping some elements: " << endl;
    int e = 1, f = 2, g = 2, h = 1;
    B.swapElementsAt(e, f, g, h);
    cout << "Matrix[" << e << ", " << f << "] is now:" << B.getElementAt(e, f);
    cout << "Matrix[" << g << ", " << h << "] is now:" << B.getElementAt(g, h);

    cout << "How does the matrix look now? " << endl;
    B.printMatrix();

    cout << "Let's try resizing th ematrix into a 6 x 6 matrix" << endl;
    cout << "and see how it looks: " << endl;
    B.resizeMatrix(6);
    B.printMatrix();
    B.deallocateMemory();
    return 0;
}