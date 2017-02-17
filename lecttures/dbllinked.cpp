// double linked list
// with double we have next and previous
#include <iostream>
using namespace std;
struct node{
    int key;
    node* next;
    node* previous;

};
class CNode{
private:
    int x;
    CNode *next;
    CNode *previous;
public:
    CNode(int value){
        x=value;
        next = NULL;
        previous = NULL;
    }
};

int main (){
    node *x1 = new node;
    node* headNode =x1;
    x1->next = NULL;
    x1->previous = NULL;
    x1->key = 0;
    int i;
    while(i<5){
        node*n = new node;
        n->next = NULL;
        n->previous = x1;
        n->key = i;
        x1->next=n;
        x1 = n;
        i++;
    }
    cout << headNode->next->next<< endl;
    cout << headNode->next->next->key<<endl;
    cout << x1->previous << endl;
    cout << x1->key<<endl;
    while(x1 != NULL){
        cout << x1->key << endl;
        x1= x1->previous;
    }

}
