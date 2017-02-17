#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
    TreeNode* chicken = new TreeNode();
    string userinput;
    string userinput2;

    while( userinput!= "6"){
        cout << "-menu-" <<endl;
        cout <<"1. add node" << endl;
        cout << "2. delete node"<< endl;
        cout<< "3. print path" << endl;

    getline(cin, userinput);
        if (userinput=="1")
        {
            cout << "enter a node " << endl;
            getline(cin, userinput2);
            int value = stoi(userinput2);
            chicken->addNode(value);
        }
        else if (userinput == "2")
        {
            cout << "enter a value" << endl;
            getline(cin, userinput2);
            int value = stoi(userinput2);
            chicken->deleteNode(value);
        }
        else if (userinput == "3"){
            chicken->printNodes();
        }


    }

}
