#include <iostream>
#include "CMatrixPro2.h"

using namespace std;

int main(){
    cout << "Let's create two matrices A and B with dimension 3" << endl;
    CMatrixPro2 A(3), B(3);
    cout << "Let's read elements into A" << endl;
    cin >> A;
    cout << "This is how A looks" << endl;
    cout << A;
    cout << "Let's read elements into B" << endl;
    cin >> B;
    cout << "This is how A looks" << endl;
    cout << B;

    cout << "Let's perform the += operation on the two matrices" << endl;
    cout << (A += B);

    cout << "Let's perform the -= operation on matrix A\n";
    cout << "by subtracting 5 from it";
    cout << (A += 5);

    cout << "Let's perform the *= operation on the two matrices" << endl;
    cout << (A *= B);

    cout << "Let's create another matrix C with dimensions 2" << endl;
    CMatrixPro2 C(2);
    cout << "Let's copy A into the matrix C" << endl;
    cout << (C = A); 

    cout << "That's it for today!" << endl;
    return 0;
}