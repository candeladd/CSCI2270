#include <iostream>

using namespace std;

int main()
{


}

bool hasPathSum(TreeNode *node, int sum){

    TreeNode *x = node;
    bool value = false;
    if ((x->key == sum)&& (x->right == NULL) && (x->left == NULL)){
        return true;
    }
    if (x->left != NULL){

        //sum = sum - x->key;
        //cout << "left " << sum << endl;
        value=hasPathSum(x->left, sum-x->key);


    }
    if ((x->right != NULL)&&(value ==false)){
        //sum = sum - x->key;
        //cout << "sum right" << sum << endl;
        value =hasPathSum(x->right, sum-x->key);
    }
    return value;
}

void doubleTree(TreeNode *node){
    TreeNode *x = node;

    if (x->left !=NULL){
        doubleTree(x->left);
    }
    if (x->right !=NULL){
        doubleTree(x->right);
    }
    TreeNode *y =new TreeNode;
    TreeNode *oldL = x->left;
    y->key = x->key;
    x->left = y;
    y->left=oldL;
}


bool sameTree(TreeNode *node1, TreeNode *node2){
    TreeNode *x= node1;
    bool same = true;
    TreeNode *y = node2;
     if (x->key!=y->key){
        same = false;
    }

    if ((x->left ==NULL&&y->left != NULL) || (x->left !=NULL&&y->left == NULL)){
        same = false;
    }

    else if(x->left != NULL && y->left != NULL){
        same = sameTree(x->left, y->left);
    }

    if ((x->right ==NULL&&y->right != NULL) || (x->right !=NULL&&y->right == NULL)){
        same = false;
}

bool isBST(TreeNode *node){
    TreeNode *x = node;

    if (x->left != NULL){
        if (x->left->right !=NULL){
            if (x->key < x->left->right->key){
                return false;
            }
        }
        if (x->key > x->left->key){
          isBST(x->left);
        } else {
            cout<< "here1"<< endl;
            return false;
        }
    }
    if (x->right != NULL){
        if (x->key < x->right->key){
            isBST(x->right);
        }
        else{
            cout << "here2" << endl;
            return false;
        }
    }
    return true;
}
