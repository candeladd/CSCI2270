#include <iostream>

using namespace std;

struct tree{
    int value;
    tree* leftChild;
    tree* rightChild;
    tree* parent
};
tree* addToTree(int value, tree* root);
void printTree(tree* root)

int main()
{
    tree* root=NULL;
    string datau;
    string userinput;

    while (userinput !="3"){
        cout <<"press 1 to add an value to the tree" << endl;
        cout << "press 2 print out tree" <<endl;
        cout << "press 3 to quit" <<endl;
        getline(cin, userinput);
        if (userinput == "1"){
            cout "what value do you wan to add" << endl;
            getline(cin, datau);
            int data = stoi(datau);
            addToTree(data)
        }
        else if (userinput=="2"){
            if (root!=NULL){
                printTree(root)
            }
            else{
                cout << "must add atleast one value to tree" <<endl;
            }
        }
    }
    cout << "GoodBye!" <<endl;

}

tree* addToTree(int value, tree* root){
    tree* k;
    k->value = value
    tree*x= root;
    tree* y = NULL;
    while (x!=NULL){
        y=x;
        if(k->value > x->value){
            x=x->rightChild
        }
        else if(k->value < x->value){
            x=x->leftChild;
        }
    }
}



