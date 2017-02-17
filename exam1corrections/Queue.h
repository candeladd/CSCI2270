#ifndef QUEUE_H
#define QUEUE_H

struct node
{
    int value;
    node *next;
};

class Queue
{
    public:
        Queue();
        void enqueue(node *newNode);
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;

};

#endif // QUEUE_H
