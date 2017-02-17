//Andrew Candelaresi
//HW4
// Double linked list Classes
//February 6 2015
#include <iostream>
#include <string>
#include <fstream>
#include "CommunicationNetwork.h"

using namespace std;


int main(){

    ifstream infile;
    string nuggets;
    infile.open("messageIn.txt");
    int length = 32;
    string *arr = new string[length];
    int i = 0;
    while (infile >> nuggets){ // opening my file and storing all the data to an array.
        arr[i] = nuggets;
        i++;
    }
    infile.close();
    for (int i = 0; i<length;i++){
    }

    int index = 0;
    int count1 = 0;

    bool flag = false; //indicates whether or not the net work has been built
    string userinput;
    string userinput2;

    cout << "======Main Menu====="<< endl;
    cout <<"1. Build Network"<< endl;
    cout <<"2. Print Network Path"<< endl;
    cout <<"3. Enqueue"<< endl;
    cout <<"4. Dequeue"<< endl;
    cout <<"5. Print Queue"<< endl;
    cout <<"6. Send Entire Message"<< endl;
    cout <<"7. Quit"<< endl;

    CommunicationNetwork *theseBeans = new CommunicationNetwork(10);

    getline(cin, userinput);
    while (userinput != "7"){
        if(userinput == "1"){

            theseBeans->buildNetwork();
            theseBeans->printPath();
            flag = true; // changes flag to indicate network has been built
            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;
            getline(cin, userinput);

        }
        else if(userinput == "2"){


                theseBeans->printPath();
                cout << "======Main Menu====="<< endl;
                cout <<"1. Build Network"<< endl;
                cout <<"2. Print Network Path"<< endl;
                cout <<"3. Enqueue"<< endl;
                cout <<"4. Dequeue"<< endl;
                cout <<"5. Print Queue"<< endl;
                cout <<"6. Send Entire Message"<< endl;
                cout <<"7. Quit"<< endl;

            getline(cin, userinput);
        }
        else if(userinput == "3"){

            if (index == 32){
                cout << "No	more words to queue."<< endl;
            }
            theseBeans->enqueue(arr[index]);
                index++;
                count1++;

            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if(userinput == "4"){
            if (flag == false){
                cout << "Build a network before attempting to transmit a message." << endl;
            }
            else{
                string foot = theseBeans->dequeue();// calling my dequeue function on my object
            }

            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if(userinput == "5"){

            theseBeans->printQueue();

            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if (userinput == "6"){
            if (flag == true){
                while(count1 != 32){

                        while(theseBeans->queueIsFull()==false && (count1 != 32)){
                            theseBeans->enqueue(arr[count1]);
                            count1++;
                        }
                        while(theseBeans->queueIsEmpty()==false){
                            theseBeans->dequeue();

                        }
                }
            }
            else{
                cout<< "Build a network before attempting to transmit a message." << endl;
            }
            count1 = 0;

            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;
            getline(cin, userinput);

        }
        else{
            cout << "incorrect input" << endl;
             cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Enqueue"<< endl;
            cout <<"4. Dequeue"<< endl;
            cout <<"5. Print Queue"<< endl;
            cout <<"6. Send Entire Message"<< endl;
            cout <<"7. Quit"<< endl;
            getline(cin, userinput);
        }

    }

     cout << "Goodbye!" << endl;
}


