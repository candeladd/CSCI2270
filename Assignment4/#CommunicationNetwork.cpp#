
#include "CommunicationNetwork.h"
#include <fstream>
#include <iostream>

using namespace std;
CommunicationNetwork::CommunicationNetwork(int qs){
    arrayQueue = new string[qs];
    queueHead = 0;
    queueTail = 0;
    queueSize = qs;
    count2 = 0;

}


void CommunicationNetwork::enqueue(std::string x){
    if (queueIsFull() == false){



            arrayQueue[queueTail] = x;
            queueTail++;
            count2++;


         if(queueTail == queueSize){
           queueTail = 0;
         }





        cout << "E: " << x<< endl;
        cout <<"H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    }
    else{
        cout << "Queue is Full"<< endl;
    }
}

std::string CommunicationNetwork::dequeue(){

    if (queueIsEmpty()==false){








            std::string message = arrayQueue[queueHead];
             arrayQueue[queueHead]= "";
             queueHead++;
                count2--;



            cout <<"H: " << queueHead << endl;
            cout << "T: " << queueTail << endl;
            transmitMsg(message);
            if (queueSize == queueHead){
                queueHead = 0;
            }
            return message;


    }
    else{
         cout<< "Queue is empty." << endl;
    }
}





void CommunicationNetwork::printQueue(){
int headCount= 0;
if(queueIsEmpty() == false){

    while(queueHead != queueTail)
    {
        cout << queueHead << ": " << arrayQueue[queueHead]<< endl;

        if(queueHead == queueTail)
        {
            cout << queueHead << ": " << arrayQueue[queueHead] << endl;
        }

        queueHead++;
        headCount++;
    }
}
else{
    cout << "Empty" << endl;
}

    queueHead = queueHead - headCount;
}

void CommunicationNetwork::buildNetwork(){

    node* LA = new node{"Los Angeles", NULL, NULL};
    node* Pho = new node{"Phoenix", NULL, NULL};
    node* Den = new node{"Denver", NULL, NULL};
    node* Dal = new node{"Dallas", NULL, NULL};
    node* StL = new node{"St. Louis", NULL, NULL};
    node* Chi = new node{"Chicago", NULL, NULL};
    node* Atl = new node{"Atlanta", NULL, NULL};
    node* DC = new node{"Washington, D.C.", NULL, NULL};
    node* NYC = new node{"New York", NULL, NULL};
    node* Bos = new node{"Boston", NULL, NULL};

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

    LA->previous = NULL;
    Pho->previous = LA;
    Den->previous = Pho;
    Dal->previous = Den;
    StL->previous = Dal;
    Chi->previous = StL;
    Atl->previous = Chi;
    DC->previous = Atl;
    NYC->previous = DC;
    Bos->previous = NYC;

    head = LA;
    tail = Bos;
}

void CommunicationNetwork::printPath(){
    node* temp = head;
        cout << "===CURRENT PATH===" << endl;
        while(temp != NULL){

            cout << temp->name<< " -> ";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
        cout << "=================="<< endl;
        delete temp;

}

bool CommunicationNetwork::queueIsFull(){

    if (count2 == queueSize){
        return true;
    }

    return false;

}
bool CommunicationNetwork::queueIsEmpty(){
    if ((queueHead == queueTail) && (arrayQueue[queueTail] == "")){
        return true;
    }
    return false;
}

void CommunicationNetwork::transmitMsg(string message1){

    node* sender = head;
        while (sender!=NULL){
            sender->message=message1;
            cout<<sender->name<<" received "<<sender->message<<endl;
            sender->message = "";
            sender=sender->next;
        }
    sender = tail;
    while(sender!= NULL){
            sender->message = message1;
             cout<<sender->name<<" received "<<sender->message<<endl;
            sender->message = "";
            sender=sender->previous;
        }

}



