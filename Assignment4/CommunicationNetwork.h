#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <string>

struct node{

    std::string name;
     //intended to hold one word
    node *next;
    node *previous;
    std::string message;

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork(int sq);
        //virtual ~CommunicationNetwork();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printQueue();
        void buildNetwork();
        void printPath();
        bool queueIsFull(); //send when full
        void transmitMsg(std::string);
        void transmitMsg(node *head, std::string arr[]);
        bool queueIsEmpty();
        void sendTheMessage(std::string);

    protected:
    private:
        node *head;
        node *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        int count2;

        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H
