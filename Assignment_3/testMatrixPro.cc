#include <iostream>
#include "CMatrixPro.h"
using namespace std;

int main(){
    cout << "Let's create two Matrices A and B" << endl;
    CMatrixPro A(3), B(3);
    cout << "This is A: " << endl;
    cin >> A;
    cout << "This is B: " << endl;
    cin >> B;

    cout << "Let's see how A and B look like" << endl;
    cout << "This is A: " << endl;
    cout << A;
    cout << "This is B" << endl;
    cout << B;

    cout << "Let's add 4 to A and call that matrix C" << endl;
    CMatrixPro C = A + 4;
    cout << "This is how C looks like:" << endl << C << endl;

    cout << "Let's add B and C and store that in matrix D" << endl;
    CMatrixPro D = B + C;
    cout << "This is D" << endl << D << endl;

    cout << "I want to subtract 89 from matrix B. Let's call it E" << endl;
    CMatrixPro E = B - 89;
    cout << E << endl;

    cout << "Is E smaller than D? [0: No, 1: Yes]: ";
    cout << (E < D) << endl;

    cout << "Let's make A and C an identity matrix" << endl;
    A.makeIdentity();
    C.makeIdentity();
    cout << "This is how they look now!:" << endl;
    cout << "This is A" << endl << A << endl;
    cout << "This is C" << endl << C << endl;

    cout << "Hopefully, the two matrices should be equal, then, right?" << endl;
    cout << "Is A == C? [0: No, 1: Yes]: " << (A==C) << endl;

    return 0;
}