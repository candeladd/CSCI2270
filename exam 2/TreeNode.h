#ifndef TREENODE_H
#define TREENODE_H
struct node{
    int ranking;
    node*left;
    node* right;
    node*parent;

};


class TreeNode
{
    public:
        TreeNode();

        node* searchMovieTree(node * node, int value);
        void printNodes();
        node* minimumNode(node *x);
        void addNode(int value);
        void deleteNode(int value);
    protected:
    private:
        void printNodes(node *bread);
        node * root;
};

#endif // TREENODE_H
