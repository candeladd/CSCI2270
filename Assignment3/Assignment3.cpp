//Andrew Candelaresi
//HW3
// Linked List Cities
//February 6 2015
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node{
    string name;
    node* next;
    string message;
};

node* createNet(string city);
void printNet(node* cursor);
void transmitMsg(node *head);
node *addCity(node *head, string previous, string cityName);
node *deletecity(node *head, string cityName);
node *deleteEntireNetwork(node *head);
int main(){

    string userinput;
    string userinput2;
    node* root;


    cout << "======Main Menu====="<< endl;
    cout <<"1. Build Network"<< endl;
    cout <<"2. Print Network Path"<< endl;
    cout <<"3. Transmit Message Coast-To-Coast"<< endl;
    cout <<"4. Add City"<< endl;
    cout <<"5. Delete City"<< endl;
    cout <<"6. Clear Network"<< endl;
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
            cout <<"3. Transmit Message Coast-To-Coast"<< endl;
            cout <<"4. Add City"<< endl;
            cout <<"5. Delete City"<< endl;
            cout <<"6. Clear Network"<< endl;
            cout <<"7. Quit"<< endl;
            getline(cin, userinput);

        }
        else if(userinput == "2"){

                node* cursor = root;
                printNet(cursor);
                cout << "======Main Menu====="<< endl;
                cout <<"1. Build Network"<< endl;
                cout <<"2. Print Network Path"<< endl;
                cout <<"3. Transmit Message Coast-To-Coast"<< endl;
                cout <<"4. Add City"<< endl;
                cout <<"5. Delete City"<< endl;
                cout <<"6. Clear Network"<< endl;
                cout <<"7. Quit"<< endl;

            getline(cin, userinput);
        }
        else if(userinput == "3"){
            transmitMsg(root);
            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Transmit Message Coast-To-Coast"<< endl;
            cout <<"4. Add City"<< endl;
            cout <<"5. Delete City"<< endl;
            cout <<"6. Clear Network"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if(userinput == "4"){

            cout << "Enter a city name: "<< endl;
            getline(cin, userinput);
            cout << "Enter a previous city name: "<<endl;
            getline(cin, userinput2);
            addCity(root, userinput2, userinput);
            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Transmit Message Coast-To-Coast"<< endl;
            cout <<"4. Add City"<< endl;
            cout <<"5. Delete City"<< endl;
            cout <<"6. Clear Network"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if(userinput == "5"){
            cout << "Enter a city name: " << endl;
            getline(cin, userinput);
            deletecity(root, userinput);
            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Transmit Message Coast-To-Coast"<< endl;
            cout <<"4. Add City"<< endl;
            cout <<"5. Delete City"<< endl;
            cout <<"6. Clear Network"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }
        else if(userinput == "6"){
            deleteEntireNetwork(root);
            cout << "Deleted network" << endl;

            cout << "======Main Menu====="<< endl;
            cout <<"1. Build Network"<< endl;
            cout <<"2. Print Network Path"<< endl;
            cout <<"3. Transmit Message Coast-To-Coast"<< endl;
            cout <<"4. Add City"<< endl;
            cout <<"5. Delete City"<< endl;
            cout <<"6. Clear Network"<< endl;
            cout <<"7. Quit"<< endl;

            getline(cin, userinput);

        }

    }

     cout << "Goodbye!" << endl;
}
node* createNet(string city){
    node* LA = new node{city, nullptr};
    node* Pho = new node{"Phoenix", nullptr};
    node* Den = new node{"Denver", nullptr};
    node* Dal = new node{"Dallas", nullptr};
    node* StL = new node{"St. Louis", nullptr};
    node* Chi = new node{"Chicago", nullptr};
    node* Atl = new node{"Atlanta", nullptr};
    node* DC = new node{"Washington, D.C.", nullptr};
    node* NYC = new node{"New York", nullptr};
    node* Bos = new node{"Boston", nullptr};

    LA->next = Pho;
    Pho->next = Den;
    Den->next = Dal;
    Dal->next = StL;
    StL->next = Chi;
    Chi->next = Atl;
    Atl->next = DC;
    DC->next = NYC;
    NYC->next = Bos;
    Bos->next = NULL;


}

void printNet(node* cursor){
    node* temp = cursor;
    cout << "===CURRENT PATH===" << endl;
    while(temp != NULL){

        cout << temp->name<< " -> ";
        temp = temp->next;
    }
    cout<< " NULL" << endl;
    cout << "================="<< endl;
    delete temp;

}

node *addCity(node *head, string previous, string cityName){
    node* temp = head;
    while (temp->next != NULL){
        temp=temp->next;
        if (temp->name==previous){
            node* newnode = new node;
            newnode->name= cityName;
            newnode->next = temp->next;
            temp->next =  newnode;
            return head;
        }
    }
}

node *deletecity(node *head, string cityName){
    node* temp = head;
    node* temp2;
    temp2 = temp;
    while(temp->next!=NULL){
        if(temp->next->name == cityName){
            temp2 =temp->next;
            temp->next = temp2->next;
            delete temp2;
        return head;
        }
        temp = temp->next;
    }
}

node *deleteEntireNetwork(node *head){
    node* temp = head;
    node* temp2 = temp;
    while (temp->next != NULL){
         temp2 =temp->next;
            temp->next = temp2->next;
            delete temp2;

    }
    delete temp;
    return head;
}

void transmitMsg(node *head){
    ifstream filename;
    filename.open ("messageIn.txt");
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
    filename.close();
}




