#include<iostream>
#include<cmath>
using namespace std;


int main(void){
    int a = 0;
    cout << "a: " << a << endl;
    cout << "a position: " << &a << endl;
    int b[10];
    b[0] = 1;
    b[2] = 10;
    int* c = b;
    (*c) = 5;

    cout << "b[0]: " << b[0] << endl;
    cout << "b   : " << b << endl;
    cout << "b+1 : " << b+1 << endl;
    cout << "b+2 : " << b+2 << endl;
    cout << "b+3 : " << b+3 << endl;
    
    cout << "b[0]: " << (*(b)) << endl;
    cout << "b[2]: " << (*(b+2)) << endl;

    cout << "c: " << *c << endl;
    
    return 0;
}