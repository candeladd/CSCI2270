#include <iostream>
#include "Queue.h"
#include <string>

using namespace std;


int main()
{
    Queue* line = new Queue();
    string value1;
    string userinput;
    while(userinput != "3"){

        cout << "===Main Menu==="<<endl;
        cout << "1. enque"<< endl;
        cout << "2. display Queue"<< endl;
        cout << "3. Quit"<< endl;
        getline(cin, userinput);

         if (userinput == "1"){
            cout<< "what value would you like to add to the queue" << endl;
            getline(cin, value1);
            int val = stoi(value1);
            node* newNode= new node();
            newNode->value = val;
            line->enqueue(newNode);

         }
        else if(userinput == "2"){
            line->displayQueue();
        }
    }

}

