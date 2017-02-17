//linked lists

#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

};

int main(){

    node* firstNode = new node {5, nullptr};
    node* head_ptr = firstNode;
    node* cursor = head_ptr;

    string userInput;
    cout << "enter the next node value; ";
    cin >> userInput;
    while(userInput != "q"){

        int userNumber = stoi(userInput);

        node* newNode = new node{userNumber, nullptr};

        cursor->next = newNode;

        cursor = cursor->next;

            cout << "enter the next node value; ";
            cin >> userInput;

    }

    cursor = head_ptr;


    cursor = head_ptr;
    if(cursor->next == nullptr){
        node* newNode = new node{1000, nullptr};
        cursor->next = newNode;
        cursor = cursor->next;
    }
    else{
        node* newNode = new node{1000, nullptr};
        newNode->next = cursor->next;
        cursor->next = newNode;

    }

    cursor = head_ptr;
     while(cursor != nullptr){
        cout << cursor->data<< endl;
        node* temp = cursor;
        cursor = cursor->next;
        delete temp;

    }

}
