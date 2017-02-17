#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
    public:
        Stack(int); // size of the vagine
        ~Stack();
        //what the fuck happens to the stackie
        void push(std::string);
        std::string pop();
        bool isStackEmpty();
        bool isStackFull();

    protected:
    private:
        //one of them is the top of the stack
        int top;
        int maxstack; // this mother fucker is the size of the array right here
        std::string *items; //

};

#endif // STACK_H
