
#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode()
{
    root = NULL;
}



 node* TreeNode::searchMovieTree(node * bread, int value){

    node* x = bread;


    if(x==NULL){
        cout << "node not found."<< endl;
        return x;
    }
    else{

        if(x->ranking == value){
                return x;
        }
        else if(x->ranking < value){

            return searchMovieTree(x->right, value);
        }
        else{
            return searchMovieTree(x->left, value);
        }

    }
 }


void TreeNode::printNodes(){
    printNodes(root);
}

void TreeNode::printNodes(node * x){
      cout << x->ranking << ",";

    if(x->left!= NULL){
        printNodes(x->left);

    }


    if (x->right != NULL){
         printNodes(x->right);

    }

}

void TreeNode::addNode(int value){
   node* x = root;
    node* P = NULL;
 while (x != NULL){
       P=x;

       if (value >= x->ranking){// go right since the first being greater than the second means that the first has a hights ascii value as in lower further in the alphabet
            x=x->right;
        }
        else{// got left
            x=x->left;
        }

    }


    x= new node;
    x->ranking = value;


    x->parent = P;
    x->left =NULL;
    x->right =NULL;


    //currentMovie->parent = P;

    if (P==NULL){
        root = x;
    }
    else if (x->ranking >= P->ranking){
        P->right = x;
    }
    else {
        P->left = x;
    }

}
node* TreeNode::minimumNode(node *x){
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}


void TreeNode::deleteNode(int value){
    node* x = searchMovieTree(root, value);
        node* y;
        node* z;
        node* w;
        if (x==NULL){
            return;
        }
        if ((x->right != NULL)&&(x->left == NULL)){
            y = x->right;
            y->parent = x->parent;
            z =x->parent;
            if (z->ranking < x->ranking){
                z->right = y;
            }
            else{
                z->left = y;
            }
            delete x;

        }
        else if (x->right == NULL&&x->left != NULL){
            y=x->left;
             y->parent = x->parent;
            z=x->parent;
            if (z->ranking < x->ranking){
                z->right = y;
            }
            else{
                z->left = y;
            }
            delete x;
        }
        else if (x->left ==NULL&&x->right == NULL){
            z=x->parent;
            if (z->ranking < x->ranking){
                z->right = NULL;
            }
            else{
                z->left = NULL;
            }
            delete x;
        }
        else if (x->left != NULL && x->left!= NULL){
            y = x->right;
            y->parent = x->parent;
            z =x->parent;
            if (z->ranking < x->ranking){
                z->right = y;
            }
            else{
                z->left = y;
            }
            w= minimumNode(y);
            w->left = x->left;
            delete x;
        }
        delete x;

}


