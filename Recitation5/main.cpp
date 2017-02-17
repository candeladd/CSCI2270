#include <iostream>
#include <string>

using namespace std;

void isPrime(int number);
int main()
{
    string userinput;
    while (userinput !="q"){
    cout<< "give me a number" << endl;

    getline(cin, userinput);
    int userinput1 = stoi(userinput);
    isPrime(userinput1);
    }
}

void isPrime(int number)
{
    for (int i=2; i<number; i++)
    {

        if (number % i == 0)
            {
            cout << i << ": " << endl;
            cout << "Not Prime" << endl;
            return;
            }

    }
    cout << "Prime" << endl;
    return;
}
