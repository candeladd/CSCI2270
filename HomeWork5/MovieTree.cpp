#include <iostream>
#include <string.h>
#include "MovieTree.h"
#include <cstdlib>

using namespace std;

MovieTree::MovieTree(){
    opCount = 0; //initializes the operation count to 0
    nil = new MovieNode();
    nil->isRed = false;// set all nil pointers to black
    root=nil;
    nil->leftChild = nil;
    nil->rightChild = nil;
    nil->parent = nil;
}



 MovieNode* MovieTree::searchMovieTree(MovieNode * node, std::string title, json_object * jarr){

    MovieNode* x = node;


    if(x==nil){
        cout << "Movie not found."<< endl;
        return x;
    }
    else{

        if(strcmp(title.c_str(),x->title.c_str())==0){
            json_object *arrtitle = json_object_new_string(x->title.c_str());
            json_object_array_add(jarr, arrtitle);
                return x;
        }
        else if(strcmp(title.c_str(),x->title.c_str())>0){
            json_object *arrtitle = json_object_new_string(x->title.c_str());
            json_object_array_add(jarr, arrtitle);
            return searchMovieTree(x->rightChild, title, jarr);
        }
        else{
            json_object *arrtitle = json_object_new_string(x->title.c_str());
            json_object_array_add(jarr, arrtitle);
            return searchMovieTree(x->leftChild, title, jarr);
        }

    }
 }



void MovieTree::printMovieInventory(MovieNode * node, json_object * jarr){
    if(node->leftChild != nil){
        printMovieInventory(node->leftChild, jarr);

    }
    cout << "Movie: "<<node->title << endl;
        json_object *arrtitle = json_object_new_string(node->title.c_str());
        json_object_array_add(jarr, arrtitle);
    if (node->rightChild != nil){
         printMovieInventory(node->rightChild, jarr);

    }
}

void MovieTree::printMovieInventory(){

    json_object *jarr = json_object_new_array();
    printMovieInventory(root, jarr);

    opCount++;

    json_object *jopCount = json_object_new_object();

    json_object *jtravese = json_object_new_string("traverse");


    json_object_object_add(jopCount, "operation",jtravese);

    json_object_object_add(jopCount, "output", jarr);

    json_object_object_add(Assignment6Output, to_string(opCount).c_str(), jopCount);

}

int MovieTree::countMovieNodes(){
    int ccount = 0;
    ccount = countMovieNodes(root);

    opCount++;
    string counter2 = to_string(opCount);
    string counting = to_string(ccount);

    json_object *jopCount = json_object_new_object();

    json_object *jCount = json_object_new_string("count");

    json_object_object_add(jopCount, "operation",jCount);
    json_object *jtitle = json_object_new_string(counting.c_str());
    json_object_object_add(jopCount, "output", jtitle);
    json_object_object_add(Assignment6Output, counter2.c_str(), jopCount);
    return ccount;
}

int MovieTree::countMovieNodes(MovieNode* root){

    if(root!=nil){
        return 1+countMovieNodes(root->leftChild)+countMovieNodes(root->rightChild);
    }
    return 0;
}

void MovieTree::initJson(){
 Assignment6Output = json_object_new_object();
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity){

    json_object *jarr = json_object_new_array();

   // MovieNode* currentMovie =new MovieNode(ranking, title, releaseYear, quantity);

    MovieNode* x = root;
    MovieNode* P = nil;

    while (x != nil){
       P=x;

        json_object *arrtitle = json_object_new_string(x->title.c_str());

        json_object_array_add(jarr, arrtitle);

       if (strcmp(title.c_str(),x->title.c_str()) >=0){// go right since the first being greater than the second means that the first has a hights ascii value as in lower further in the alphabet
            x=x->rightChild;
        }
        else{// got left
            x=x->leftChild;
        }

    }


    x= new MovieNode;
    x->quantity = quantity;
    x->ranking = ranking;
    x->title = title;
    x->year = releaseYear;
    x->isRed = true;

    x->parent = P;
    x->leftChild =nil;
    x->rightChild =nil;


    //currentMovie->parent = P;

    if (P==nil){
        root = x;
    }
    else if (strcmp (x->title.c_str(),P->title.c_str()) >= 0){
        P->rightChild = x;
    }
    else {
        P->leftChild = x;
    }
    cout << x->title << endl;

    rbAddFixup(x);
    isValid();

    opCount++;


    json_object *jopCount = json_object_new_object();
    json_object *jadd = json_object_new_string("add");
    json_object *jparam = json_object_new_string(title.c_str());

    json_object_object_add(jopCount, "operation",jadd);
    json_object_object_add(jopCount, "parameter",jparam);
    json_object_object_add(jopCount, "output", jarr);

    json_object_object_add(Assignment6Output, to_string(opCount).c_str(), jopCount);


}

/*void MovieTree::findMovie(std::string title){
    MovieNode* y = new MovieNode;
    json_object *jarr = json_object_new_array();
    y = searchMovieTree(root, title, jarr);
    if (y!=NULL){
        cout <<	"Movie Info:"	<<	endl;
        cout <<	"===========" << endl;
        cout <<	"Ranking:"	<< y->ranking	<<	endl;
        cout <<	"Title:" << y->title	<<	endl;
        cout <<	"Year:" <<	y->year	<<	endl;
        cout <<	"Quantity:" <<	y->quantity	<<	endl;
    }

}*/



void MovieTree::rentMovie(std::string title){
    MovieNode* y;

    json_object *jarr = json_object_new_array();
    y = searchMovieTree(root, title, jarr);
    if (y==nil){

        return;
    }

    if ((y!=nil)&&(y->quantity!=0)){
            y->quantity=y->quantity-1;
        cout << "Movie has been rented." <<	endl;
        cout <<	"Movie Info:" << endl;
        cout <<	"===========" << endl;
        cout <<	"Ranking:" << y->ranking << endl;
        cout <<	"Title:" << y->title << endl;
        cout <<	"Year:"	<<	y->year << endl;
        cout <<	"Quantity:"	<< y->quantity << endl;

    }


    opCount++;
    json_object *jopCount = json_object_new_object();
    json_object *jrent = json_object_new_string("rent");
    json_object *jparam = json_object_new_string(title.c_str());
    json_object *jInt = json_object_new_string(to_string(y->quantity).c_str());

    json_object_object_add(jopCount, "operation",jrent);
    json_object_object_add(jopCount, "parameter",jparam);
    json_object_object_add(jopCount, "output", jInt);

    json_object_object_add(Assignment6Output, to_string(opCount).c_str(), jopCount);
      if((y->quantity == 0)&&(y!=nil)){
            deleteMovieNode(y->title);
        }

}


void MovieTree::deleteMovieNode(std::string title)
{
    json_object *jarr = json_object_new_array();

    MovieNode *x = searchMovieTree(root, title, jarr);
    rbDelete(x);
   /*  // call to search function to find the node to be deleted
    MovieNode *x, *xsucc ;





        x = searchMovieTree(root, title, jarr);


    if (x == nil){
            return;
    }

    // if the node to be deleted has two children
    else if ( (x -> leftChild != nil) && (x -> rightChild != nil) )
        {
            xsucc = x -> rightChild ;

        while ( xsucc -> leftChild != nil )
        {
            xsucc = xsucc -> leftChild ;
        }
         if ( (xsucc->rightChild != nil)&& (xsucc->parent->rightChild == xsucc)){
            x->quantity = xsucc->quantity;
            x->ranking = xsucc->ranking;
            x->title = xsucc->title;
            x->year = xsucc->year;

            xsucc->parent->rightChild = xsucc->rightChild;
            xsucc->rightChild->parent = xsucc->parent;
        }
        else if((xsucc->rightChild == nil) && (xsucc->parent->rightChild == xsucc)){
            x->quantity = xsucc->quantity;
            x->ranking = xsucc->ranking;
            x->title = xsucc->title;
            x->year = xsucc->year;

            x->rightChild =nil;

        }
        else if((xsucc->rightChild != nil)&&(xsucc->parent->leftChild == xsucc))
        {
            x->quantity = xsucc->quantity;
            x->ranking = xsucc->ranking;
            x->title = xsucc->title;
            x->year = xsucc->year;

            xsucc->parent->leftChild = xsucc->rightChild;
            xsucc->rightChild->parent = xsucc->parent;

        }
        else {
            x->quantity = xsucc->quantity;
            x->ranking = xsucc->ranking;
            x->title = xsucc->title;
            x->year = xsucc->year;

            xsucc->parent->leftChild = nil;

        }
        delete xsucc;
    }

    // if the node to be deleted has no child
    else if ( x -> leftChild == nil && x -> rightChild == nil )
        {
        if (strcmp(x->title.c_str(),x->parent->title.c_str())>0){
            x->parent->rightChild = nil;
        }
        else {
            x->parent->leftChild = nil;


        }

            delete x;
        }

    // if the node to be deleted has only rightchild
    else if ( x -> leftChild == nil && x -> rightChild != nil )
        {

            if (strcmp(x->title.c_str(),x->parent->title.c_str())>0){
                x->parent->rightChild = x->rightChild;
                x->rightChild->parent = x->parent;
            }
            else {
                x->parent->leftChild = x->rightChild;
                x->rightChild->parent = x->parent;

            }
            delete x;
        }

    // if the node to be deleted has only left child
    else if ( x -> leftChild != nil && x -> rightChild == nil )
    {
        if (strcmp(x->title.c_str(),x->parent->title.c_str())>0){
            x->parent->rightChild = x->leftChild;
            x->leftChild->parent = x->parent;
        }
        else {
            x->parent->leftChild = x->leftChild;
            x->leftChild->parent = x->parent;

        }
        delete x;
    }*/
     opCount++;


    json_object *jopCount = json_object_new_object();
    json_object *jdelete = json_object_new_string("delete");
    json_object *jparam = json_object_new_string(title.c_str());

    json_object_object_add(jopCount, "operation",jdelete);
    json_object_object_add(jopCount, "parameter",jparam);
    json_object_object_add(jopCount, "output", jarr);

    json_object_object_add(Assignment6Output, to_string(opCount).c_str(), jopCount);

}

json_object* MovieTree::getJsonObject()
{
    return Assignment6Output;
}



void MovieTree::DeleteAll(MovieNode * node){
    MovieNode *x = node;

if(x->leftChild != nil)

   DeleteAll(x->leftChild);

if(x->rightChild != nil)

   DeleteAll(x->rightChild);
}

void MovieTree::leftRotate(MovieNode *node)
{

    MovieNode *y;
    y = node->rightChild;
    node->rightChild = y->leftChild;
    if(y->leftChild != nil)
    {
    y->leftChild->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == nil)
    {
    root = y;
    }


    if (node == (node->parent)->leftChild)
    {
    node->parent->leftChild = y;
    }
    if (node == (node->parent)->rightChild)
    {
    node->parent->rightChild = y;
    }

    y->leftChild = node;
    node->parent = y;
}

void MovieTree::rightRotate(MovieNode *node)
{
    MovieNode *x;
    x = node->leftChild;
    node->leftChild = x->rightChild;
    if(x->rightChild != nil)
    {
    x->rightChild->parent = node;
    }
    x->parent = node->parent;
    if(node->parent == nil)
    {
    root = x;
    }

    if (node == (node->parent)->leftChild)
    {
        node->parent->leftChild = x;
    }
    if (node == (node->parent)->rightChild)
    {
        node->parent->rightChild = x;
    }

    x->rightChild = node;
    node->parent = x;
}

void MovieTree::rbAddFixup(MovieNode* x){
    while ( (x != root) && (x->parent->isRed == true))
    {
      if ( x->parent == x->parent->parent->leftChild ) {
            cout << "here 1"<< endl;
           /* If x's parent is a left, y is x's right 'uncle' */
           MovieNode *y = x->parent->parent->rightChild;
           if ( y->isRed == true ) {
                 cout << "here 2 "<< endl;
              // case 1 - change the colors
              x->parent->isRed = false;
              y->isRed = false;
              x->parent->parent->isRed = true;
              // Move x up the tree
              x = x->parent->parent;
          }
          else {


              /* y is a black node */
              if ( x == x->parent->rightChild ) {
                 cout << "here 4"<< endl;
                  /* and x is to the right */
                  /* case 2 - move x up and rotate */
                  x = x->parent;
                  leftRotate( x );
              }
                 cout << "here 3"<< endl;
              /* case 3 */
              x->parent->isRed = false;
              x->parent->parent->isRed = true;

              rightRotate( x->parent->parent );
          }
      }
      else {
         cout << "here 5"<< endl;
          /* repeat the "if" part with right and left exchanged */
           /* If x's parent is a right, y is x's left 'uncle' */
           MovieNode *y = x->parent->parent->leftChild;

           if ( y->isRed == true ) {
                 cout << "here 6"<< endl;

            // case 1 - change the colors */
              x->parent->isRed = false;
              y->isRed = false;
              x->parent->parent->isRed = true;
              /* Move x up the tree */
              x = x->parent->parent;
          }
          else {
                 cout << "here 7"<< endl;
              /* y is a black node */
              if ( x == x->parent->leftChild ) {
                 cout << "here 8"<< endl;
                  /* and x is to the left */
                  /* case 2 - move x up and rotate */
                  x = x->parent;
                  rightRotate( x );
              }
              /* case 3 */
              x->parent->isRed = false;
              x->parent->parent->isRed = true;
              leftRotate( x->parent->parent );
          }
      }
  }
   cout << "here 9"<< endl;
  // Color the root black
  root->isRed = false;
  cout << "root-> "<<root->title <<endl;
}


int MovieTree::rbValid(MovieNode * node)
{
    int lh = 0;
    int rh = 0;

    // If we are at a nil node just return 1
    if (node == nil)
        return 1;

    else
    {
        // First check for consecutive red links.
        if (node->isRed)
        {
            if(node->leftChild->isRed || node->rightChild->isRed)
            {
                cout << "This tree contains a red violation" << endl;
                return 0;
            }
        }

        // Check for valid binary search tree.
        if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0))
        {


            return 0;
        }

        // Deteremine the height of let and right children.
        lh = rbValid(node->leftChild);
        rh = rbValid(node->rightChild);

        // black height mismatch
        if (lh != 0 && rh != 0 && lh != rh)
        {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }

        // If neither height is zero, incrament if it if black.
        if (lh != 0 && rh != 0)
        {
                if (node->isRed)
                    return lh;
                else
                    return lh+1;
        }

        else
            return 0;

    }
}

void MovieTree::rbDelete(MovieNode * z){

    MovieNode *x;
    MovieNode *y = z;
    bool yoriginal= y->isRed;
    if (z==nil)
    {
        return;
    }
    // returns if the movie was not found

    if(z->leftChild == nil)
    {
        x = z->rightChild;
        rbTransplant(z,z->rightChild);
    }
    else if(z->rightChild == nil)
    {
        x = z->leftChild;
        rbTransplant(z,z->leftChild);
    }
    else
    {
        y = minimumNode(z->rightChild);
        yoriginal = y->isRed;
        x= y->rightChild;
        if(y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            rbTransplant(y,y->rightChild);
            y->rightChild = z->rightChild;
            y->rightChild->parent = y;
        }
        rbTransplant(z,y);
        y->leftChild = z->leftChild;
        y->leftChild->parent = y;
        y->isRed = z->isRed;
    }
        if(yoriginal == false)
    {
        rbDeleteFixup(x);
    }
}

MovieNode* MovieTree::minimumNode(MovieNode *x){
    while (x->leftChild != nil)
    {
        x = x->leftChild;
    }
    return x;
}

int MovieTree::countLongestPath(MovieNode *x){
    if (x==nil)
    {
        return 0;
    }
    if(x != nil)
    {
        return max(countLongestPath(x->leftChild),countLongestPath(x->rightChild))+1;
    }
}
bool MovieTree::isValid(){
    if (rbValid(root)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void MovieTree::rbTransplant(MovieNode * u, MovieNode * v){
    if (u->parent == nil)
    {
         root = v;
    }
    else if (u == u->parent->leftChild)
    {
         u->parent->leftChild = v;
    }
    else
    {
        u->parent->rightChild = v;
    }
    v->parent = u->parent;
}

void MovieTree::rbDeleteFixup(MovieNode * x){

    while (x != root && x->isRed == false)
    {
        cout << "hello0" << endl;
        if(x == x->parent-> leftChild)
        {
            cout << "hello1" << endl;
            MovieNode *w = x-> parent -> rightChild;
            if(w -> isRed == true)
            {
                w -> isRed = false;
                x -> parent -> isRed = true;
                leftRotate(x->parent);
                w = x->parent-> rightChild;
            }
            if((w->leftChild-> isRed == false) &&(w->rightChild-> isRed ==false))
            {
                w->isRed = true;
                x = x->parent;
            }
            else
            {
               if(w->rightChild->isRed ==false)
               {
                   w->leftChild->isRed = false;
                   w->isRed = true;
                   rightRotate(w);
                   w= x->parent->rightChild;
               }
               w->isRed = x->parent->isRed;
               x->parent->isRed = false;
               w->rightChild->isRed = false;
               leftRotate(x->parent);
               x=root;
            }
        }
    else
    {
        cout << "hello2" << endl;
        MovieNode *w = x-> parent -> leftChild;
        if(w -> isRed == true)
        {
            w -> isRed = false;
            x-> parent -> isRed = true;
            rightRotate(x->parent);
            w = x->parent-> leftChild;
        }
        if((w->rightChild-> isRed == false) &&(w->leftChild-> isRed ==false))
        {
            w->isRed = true;
            x= x->parent;
        }
        else
        {
            if(w->leftChild->isRed ==false)
            {
                w->rightChild->isRed = false;
                w->isRed = true;
                leftRotate(w);
                w= x->parent->leftChild;
            }
            w->isRed = x->parent->isRed;
            x->parent->isRed = false;
            w->leftChild->isRed = false;
            rightRotate(x->parent);
            x=root;
        }
    }
    }
  x->isRed = false;
}
int MovieTree::countLongestPath(){

    //longestPathCounter = 0;
    countLongestPath(root);
    int longestPath= countLongestPath(root);
    //cout longestPathCounterMax
    cout << "Longest Traversal is:  " << longestPath << endl;
    //do assorted Json stuff associated with this



    opCount++;

    json_object *jopCount = json_object_new_object();
    json_object *jheight = json_object_new_string("height");
    string cntStr = to_string(longestPath);
    json_object *jnumCnt = json_object_new_string(cntStr.c_str());



    json_object_object_add(jopCount, "operation",jheight);
    json_object_object_add(jopCount, "output", jnumCnt);

    json_object_object_add(Assignment6Output, to_string(opCount).c_str(), jopCount);

}



