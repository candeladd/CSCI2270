#include <iostream>
#include "Graph.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    char* filename = argv[1];
    Graph *zed = new Graph;
    zed->createVector(filename);
    string userinput;
    string userinput2;
    string userinput3;
    while (userinput!= "6")
    {
        cout << "======Main Menu====="<< endl;
        cout << "1. Print vertices" <<endl;
        cout << "2. Find districts" <<endl;
        cout << "3. Find shortest path" <<endl;
        cout << "4. Find shortest distance" <<endl;
        cout << "5. Extra credit" <<endl;
        cout << "6. Quit" <<endl;
        getline (cin, userinput);
        if (userinput == "1")
        {

            zed->displayEdges();
        }
        else if(userinput == "2")
        {
            zed->getDistrict();

        }
        else if(userinput == "3")
        {

            cout << "Enter a starting city:"<< endl;
            getline(cin, userinput2);
            cout << "Enter an ending city:"<< endl;
            getline(cin, userinput3);
            bool cheese = zed->findVertex(userinput2);
            if (cheese==true)
                {
                    bool cheesie = zed->findVertex(userinput3);
                    if (cheesie == true)
                    {
                          bool path = zed->compareDistrictId(userinput2, userinput3);

                        if (path==true)
                        {
                            zed->shortestPath(userinput2, userinput3);
                        }
                        else
                        {
                            cout << "No safe path between cities"<< endl;
                        }
                    }
                    else
                    {
                        cout << "One or more cities doesn't exist" << endl;
                    }

                }
                else
                {
                    cout << "One or more cities doesn't exist" << endl;
                }
        }
        else if (userinput == "4")
        {

            cout << "Enter a starting city:"<< endl;
            getline(cin, userinput2);
            cout << "Enter an ending city:"<< endl;
            getline(cin, userinput3);
            bool cheese = zed->findVertex(userinput2);

                if (cheese==true)
                {
                    bool cheesie = zed->findVertex(userinput3);
                    if (cheesie == true)
                    {
                          bool path = zed->compareDistrictId(userinput2, userinput3);

                        if (path==true)
                        {
                            zed->shortestDistance(userinput2, userinput3);
                        }
                        else
                        {
                            cout << "No safe path between cities"<< endl;
                        }
                    }
                    else
                    {
                        cout << "One or more cities doesn't exist" << endl;
                    }

                }
                else
                {
                    cout << "One or more cities doesn't exist" << endl;
                }

        }
    }
    cout <<"Goodbye!"<<endl;

}
