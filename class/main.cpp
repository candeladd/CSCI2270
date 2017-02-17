#include <iostream>
#include "CNode.h"

using namespace std;

int main()
{
    CNode *cn = new CNode(0, 10);
    CNode *n = new CNode(1, 5);
    cn->setNext(n);
    n->setPrevious(cn);
    for (int i=0; i < 10; i++){
        cn->setArrayData(i, i+2)
    }
    for (int i=0; i <20; i++){
        cout <, cn->getArrayData(i)
    }
    retur 0;

    x=head;
    for (int i=0; i <10; i++){
        x=x->getNext();
        delete x->getPrevious();
    }
    delete x;
}

