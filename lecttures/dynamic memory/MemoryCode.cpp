#include <iostream>

using namespace std;

void arrayTest(int a[], int length)
    {
        for(int i = 0; i <length; i++)
            a[i] = i;
    }

int main()
{
    int myArray[10]
    for (int i =0; i <10; i++)
    {    cout << myArray[i] << endl;
    }
    // all arrays are effectively pointers
    arrayTest(myArray, 10);
    for(int i = 0; i <10; i++)
        cout << myArray[i] << endl;

    //dynamically allocate memory
    // creates array on heap
    // explicitly allocating memory
    int *ptrArray =  newint[10]
    for(int i = 0; i <10; i++)
        cout << ptrArray[i]<< endl;
    //explicitly dealocate
    delete []ptrArray;
    return 0;

}
