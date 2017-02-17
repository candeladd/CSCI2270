#include <iostream>
#include <fstream>
#include <string>




//Andrew Candelaresi
//HW4
// Double linked list Classes
//February 6 2015
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



void transmitMsg(node *head);
node *deleteEntireNetwork(node *head);
int main(){

    ifstream infile;
    string nuggets;
    infile.open("messageIn.txt");
    int length = 32;
    string* arr = new string[length];
    while (infile >> nuggets){
        int i;
        arr[i] = nuggets;
        i++;
    }
    infile.close();
    for (int i = 0; i<length;i++){
        cout << arr[i] << endl;
    }

    string userinput;
    string userinput2;

    node* head;
    node* tail:

    cout << "======Main Menu====="<< endl;
    cout <<"1. Build Network"<< endl;
    cout <<"2. Print Network Path"<< endl;
    cout <<"3. Enqueue"<< endl;
    cout <<"4. Dequeue"<< endl;
    cout <<"5. Print Queue"<< endl;
    cout <<"6. Send Entire Message"<< endl;
    cout <<"7. Quit"<< endl;

    getline(cin, userinput);
    while (userinput != "7"){
        if(userinput == "1"){

            root = createNet("Los Angeles");
            node* cursor = root;
            printNet(cursor);
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

                node* cursor = root;
                printNet(cursor);
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



            cout << "======Main Menu====="<< endl;
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
        else if(userinput == "6"){


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


void transmitMsg(node *head){
    node* sender = head;
    string message1;
    while(filename >>message1){
        sender=head;
        while (sender!=NULL){
            sender->message=message1;
            cout<<sender->name<<" received "<<sender->message<<endl;
            sender->message = "";
            sender=sender->next;
        }
    }

}




