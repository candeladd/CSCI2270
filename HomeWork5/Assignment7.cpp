//Andrew candelaresi
//Movie Tree Assignment 7
// worked with James Draper
// help from Hana sunny
// February 3 2015
// started from the bottom now I'm here, started from the bottom now my whole tree here


#include <iostream>
#include <fstream>
#include <string>
#include "MovieTree.h"

using namespace std;



int main (int argc, char* argv[]){
    char* filename = argv[1];
    ifstream infile;            //ifstream reads in a file

    infile.open(filename);
    string userinput;

    MovieTree* chicken = new MovieTree(); // creating an instance of my class
    chicken->initJson();
    while(!infile.eof()){


        string temprating;
        string title;
        string tempyear;
        string tempquantity;

        getline(infile, temprating,',');//getline says to read from infile, look for type, and go until ','

        getline(infile, title,',');
        getline(infile, tempyear, ',');

        getline(infile, tempquantity);

        int rating1 = atoi(temprating.c_str());
        int year1 = atoi(tempyear.c_str());
        int quantity1 = atoi(tempquantity.c_str());


        chicken->addMovieNode(rating1, title, year1, quantity1); // calling the node addmovie on my class object


    }
    while (userinput != "6"){
        cout	<<	"======Main Menu====="	<<	endl;
        //cout	<<	"1. Find a movie"	<<	endl;
        cout	<<	"1. Rent a movie"	<<	endl;
        cout	<<	"2. Print the inventory"	<<	endl;
        cout	<<	"3. Delete a movie"	<<	endl;
        cout   << "4. Count the movies"<< endl;
        cout   << "5. count longest path"<< endl;
        cout   << "6. Quit"<< endl;

        getline(cin, userinput);

        /*if (userinput == "1"){
            cout	<<	"Enter title:"	<<	endl;
            string userinput2;
            getline(cin, userinput2);
            chicken->findMovie(userinput2);


        }*/
        if(userinput == "1"){
            cout	<<	"Enter title:"	<<	endl;
            string userinput2;
            getline(cin, userinput2);
            chicken->rentMovie(userinput2);

        }
        else if(userinput == "2"){
            chicken->printMovieInventory();

        }
        else if(userinput == "3"){
            cout << "Enter title:" << endl;
            string userinput2;
            getline(cin, userinput2);
            chicken->deleteMovieNode(userinput2);
        }
        else if(userinput == "4"){
            int count_f = chicken->countMovieNodes();
            cout <<"count: "<< count_f<< endl;
        }
        else if(userinput == "5"){
          chicken->countLongestPath();
        }





    }
    ofstream fileout;
    fileout.open("Assignment7Output.txt");
    if (fileout.is_open()){
        json_object *object = chicken->getJsonObject();
        fileout << json_object_to_json_string_ext(object, JSON_C_TO_STRING_PRETTY)<< endl;
    }
    else{
        cout<< "File not open"<< endl;
    }
    cout << "Goodbye!" << endl;




}
