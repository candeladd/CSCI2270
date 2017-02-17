#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    head=NULL;
    tail=NULL;
}


void Queue::enqueue(node *newNode){

    node* temp =head;
    if (head==NULL){

        head=newNode;
        tail=newNode;
        newNode->next=NULL;

    }
    else{
    tail->next=newNode;
    tail=newNode;
    newNode->next=NULL;

    }
}




void Queue::displayQueue(){


    node* temp = head;
    while (temp!=tail->next){
        cout << temp->value << " -> ";
        temp=temp->next;
    }
    cout <<"NULL"<<endl;
}

