#include "vector.h"
int main() // Here is a start:
{
        Vector<int> intVec{1,3,5,7,9};
        Vector<double> doubleVec{1.5,2.5,3.5,4.5};
        Vector<int> iv{intVec};
        Vector<double> dv{doubleVec};
        const Vector<int> constVec{1, 3, 5, 7, 9, 10 , 12};
        const Vector<int> constVec2{1, 3, 5, 7, 9, 10 , 12, 19};
        Vector<int> intVec2{9,3,5,7,9};
        Vector<int> newIntVec{1, 2, 3};
        cout << "intVec" << intVec << endl;
// "intVec(1, 3, 5, 7, 9)"
        cout << "iv" << iv << endl;
// "iv(1, 3, 5, 7, 9)"
        cout << "doubleVec" << doubleVec << endl;
// "doubleVec(1.5, 2.5, 3.5, 4.5)"
cout << "dv" << dv << endl;
// "dv(1.5, 2.5, 3.5, 4.5)"
        // add at least one test case for each method defined in Vector
        cout << intVec.size() << "expected 5" << endl;
        intVec[2] = 0;
        cout << intVec[2] << "expected 0" << endl;
        cout << constVec[5] << "expected 10" << endl;
        cout << intVec * iv << "expected 140" << endl;
        cout << intVec + iv << "expected (2, 6, 0, 14, 18)" << endl;
        intVec = intVec2;
        cout << intVec << "expected (9, 3, 5, 7, 9)" << endl;
        cout << (constVec == constVec) << "expected 1" << endl;
        cout << (constVec == constVec2) << "expected 1" << endl;
        cout << 2 * newIntVec << "expected (2, 4, 6)" << endl;
        cout << 2 + newIntVec << "expected (3, 4, 5)" << endl;
return 0;
}