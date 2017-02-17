#include <iostream>

using namespace std;

struct TreeNode{
    parent
    string name
    left
    right
};

int main()
{
   TreeNode *root =new TreeNode;
   root->name= "Denver";
   root->parent =NULL;
   TreeNode *left = new TreeNode;
   left->name = "Las Vegas";
   left->parent = root;


   TreeNode *right = new TreeNode;
    right->name=  "Chicago";
    right->parent = root;



    TreeNode *next = left;
    TreeNode *leftL = new TreeNode;
    left->leftChild = leftL;
    leftL->name = "Los Angeles";
    leftL->leftChild = NULL;
    leftL->rightChild = NULL;
    leftL->parent




}
void printCityNames(TreeNode *root){
    cout << "city: " << root->name<,endl;
    if (root->leftchild!=NULL){
        printCityNames(root->leftChild);
    }
    if (root->rightChild!=NULL){
        printCityNames(root->rightChild)
    }
}
