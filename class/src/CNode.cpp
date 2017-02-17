#include "CNode.h"
#include <iostream>

//implementation of cNode.h

CNode::CNode(int value, int arraySize)
{
    x=value;
    dataArray =new int[arraySize];
    next = NULL;
    previous =NULL;
    maxSize = arraySize;
    //ctor
}

CNode::~CNode()
{
    delete[] dataArray;

    //dtor
}

CNode* CNode::getNext(){
    return next;
}

CNode* CNode::getPrevious(){
    return previous;
}

int CNode::getX(){
    return x;
}

int CNode::getArrayData(int index){
    return dataArray[index];
}
void CNode::setNext(CNode* n){
    next = n;
}
void CNode::setPrevious(CNode* n){
    previous= n;
}
void CNode::setArrayData(int index, int d){
    if(index < maxsize){
        dataArray[index] = d;
    }
    else{
        std::cout<<"index out of bounds\n";
    }
}
void CNode::setX(int setX){
    x=setX;
}
