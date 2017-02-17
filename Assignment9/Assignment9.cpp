#include <iostream>
#include <fstream>
#include "HashTable.h"

using namespace std;

int main(){
    HashTable *smoke= new HashTable(10);
    /*char* filename = argv[1];

    ifstream infile;            //ifstream reads in a file

    infile.open(filename);
         while(!infile.eof())
        {
            string title;
            string tempyear;

            getline(infile, title,',');
            getline(infile, tempyear, ',');

            int year1 = atoi(tempyear.c_str());
            Movie *temp = new Movie(title,year1);
            smoke->insertMovie(temp);
         }*/


    string userinput;
    while(userinput != "5")
    {


        cout << "======Main Menu======" <<endl;
        cout << "1. Insert movie"<< endl;
        cout << "2. Delete movie"<<endl;
        cout << "3. Find movie" << endl;
        cout << "4. Print table contents" << endl;
        cout << "5. Quit" << endl;
        getline(cin, userinput);
        if (userinput == "1")
        {
            string userinput2;
            string userinput3;
            cout << "Enter title:" << endl;
            getline(cin, userinput2);
            cout << "Enter year:" << endl;
            getline(cin, userinput3);
            int year = stoi(userinput3);
            Movie *temp = new Movie(userinput2,year);
            temp->next = NULL;

            smoke->insertMovie(temp);

        }
        if (userinput == "2")
        {
            string userinput2;


            cout << "Enter title:" << endl;
            getline(cin, userinput2);
            smoke->deleteMovie(userinput2);

        }
        if (userinput == "3")
        {
            string userinput2;
            int table = 10;

            cout << "Enter title:" << endl;
            getline(cin, userinput2);
            int sum = smoke->hashSum(userinput2, table);
            Movie *movieFound =smoke->findMovie(userinput2, sum);
            cout << sum <<":"<< movieFound->title << ":" <<movieFound->year<< endl;
            if (movieFound == NULL)
            {
                cout << "not found" << endl;
            }
        }
        if (userinput == "4")
        {
            smoke->printInventory();
        }

    }
    cout << "Goodbye!" << endl;
}
