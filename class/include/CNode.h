#ifndef CNODE_H
#define CNODE_H


class CNode
{
    private:
        int x;
        CNode *next;
        CNode *previous;
        int *dataArray; // pointer size set later in constructor
        int maxSize; // number of elements in array

    public:
        CNode(int, int);
        virtual ~CNode();
        //getters
        CNode* getNext();
        CNode* getPrevious();
        int getX();
        int getArrayData(int);
        void setNext(CNode* n);
        void setPrevious(CNode* n);
        void setX();
        void setArrayData();

    protected:
};

#endif // CNODE_H
