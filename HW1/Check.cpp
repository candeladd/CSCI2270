
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;




struct messageBoard
{
    string type;
    int price;
    bool wanted;
};


int main(int argc, char* argv[])
{
    ifstream myfile;
    myfile.open(argv[1]);

    const int NUM_ROWS = 100;
    messageBoard itemsforSale[NUM_ROWS];

    cout<< "this text is here" << endl;
    while (!myfile.eof())
    {


        cout << "box of shoes" << endl;

        messageBoard object;

        string type;
        string wanted;
        string price;
        getline(myfile, type, ',');
        getline(myfile, wanted, ',');
        getline(myfile, price);


            cout << "type: " << type << endl;

    }
}
