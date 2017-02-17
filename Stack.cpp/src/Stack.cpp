#include "Stack.h"


//this is where you eat a cow filled with feces

Stack::Stack(int size)
{
    //ctor
    maxstack=size;
    top = -1;
    items=new std::string[maxstack];
}

void Stack::push(string c){
    top++;
    items[top] = c;

}

std::string pop(){
    string p = items[top];
    top--;
    return p;
}
bool stack::isStackEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}
bood Stack::isStackEmpty(){
    if(top == mazStack-1)
        return false;
    else
        return true;
}


Stack::~Stack()
{
    //dtor
    delete[] items;
}
