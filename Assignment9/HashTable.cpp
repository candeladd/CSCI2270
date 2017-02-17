#include <iostream>
#include <string.h>
#include "HashTable.h"

using namespace std;
HashTable::HashTable(int num)
{

    hashT.resize(num);
}
void HashTable::insertMovie(Movie* poin)
{

    int someint =10;
    int sum = hashSum(poin->title, someint);

    if (hashT[sum] == NULL)
    {

    hashT[sum] = poin;
    hashT[sum]->next = NULL;
    }
    else
    {

        Movie* temp = hashT[sum];
        if (temp->title.compare(poin->title)>0)// if A>B A(B) you will get value greater that zero. B is what you want to insert
        {

            poin->next = temp;
            hashT[sum] = poin;
            return;

        }



        while (temp->next != NULL){

            if (temp->next->title.compare(poin->title)>0)// if A<B A(B) alue less than 0
            {
               break;
            }
         temp=temp->next;
        }
        poin->next=temp->next;
        temp->next=poin;



}
}

int HashTable::hashSum(string x, int s) //x is the string to hash, s is the array size
{
    int sum = 0;
    for (int i = 0; i< x.length();i++)
    {
        sum =sum + x[i];  //ascii value of ith character in the string
    }
    sum = sum % s;
    return sum;
}

void HashTable::printInventory()
{
    bool anythingInHere= false;
        for (int i = 0; i<hashT.size();i++)
        {
            if (hashT[i]!= NULL)
            {
                anythingInHere=true;
            }

        }
        if (anythingInHere==false)
        {
            cout << "empty" << endl;
            return;
        }

    for (int i = 0; i<hashT.size();i++)
    {
        if (hashT[i]!=NULL)
        {
            Movie* temp=hashT[i];
            while(temp!=NULL)
            {
                cout<< temp->title<< ":" << temp->year<< endl;
                temp=temp->next;
            }
        }
        else
        {
        }
    }
}
 Movie* HashTable::findMovie(std::string in_title, int index)
 {
      Movie* temp=hashT[index];
            while(temp!=NULL)
            {
               if (temp->title==in_title)
               {
                   return temp;
               }
               temp=temp->next;
            }
        return hashT[index];
 }

void HashTable::deleteMovie(string in_title)
{

    int sum = hashSum(in_title, hashT.size());
    Movie* item = findMovie(in_title, sum);
    Movie* temp = hashT[sum];
    Movie* temp2;
    temp2 = temp;

    if ((item->title == temp->title)&& (temp->next != NULL))
    {
        hashT[sum]=temp->next;
        delete temp;
    }
    else if (item->title == temp->title && temp->next==NULL)
    {
        hashT[sum]=NULL;
        delete temp;
    }

    while(temp->next!=NULL){
        if(temp->next->title == item->title){

            temp2 =item;

            temp->next = temp2->next;

            delete temp2;

            return;
        }
        temp = temp->next;
    }
}


