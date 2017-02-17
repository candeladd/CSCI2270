#include <iostream>

using namespace std;

void passingpointer(int* a, int b){
    *a = 99;
    b=99;
}
int main(){

    int length = 1;
    int b = 55;
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &a << endl;
    passingpointer(ptr, b);
    cout << "a:"<< a << endl;
    cout << "b: " << b << endl;
    //new creates memory on the heap instead of stack
    int* prtarray = new int[length];

    delete[] ptrarray;
}

//int*x
//int* x
//int *x all the same
