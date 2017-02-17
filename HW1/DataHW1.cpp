
#include <iostream>
#include <fstream>
#include <string>
using namespace std;




struct object
{
    string type;
    int price;
    bool wanted;
};


int compareStuff(object itemsforSale[], object temp, int num);
//void openFile()

int main(int argc, char* argv[])
{
    ifstream myfile;
    myfile.open(argv[1]);

    const int NUM_ROWS = 100;
    object itemsforSale[NUM_ROWS];

    int counter =0;
    string line;

    while (!myfile.eof())
    {
        object temp;

        string type;
        string wanted;
        string price;
        getline(myfile, type, ',');
        getline(myfile, wanted, ',');
        getline(myfile, price);


        temp.price = stoi(price.c_str());
        temp.type = type;

        if (wanted == "wanted")
        {
            temp.wanted = true;
        }
        else
            temp.wanted = false;

        int counter = 0;
        int placeholder = compareStuff(itemsforSale[NUM_ROWS], temp, counter);
        if (placeholder == 1)
        {
            //remove the item it matched with.
            //item was sold
            itemsforSale[counter] = itemsforSale[counter + 1];

        }

        else if (placeholder == 0)
        {
            itemsforSale[counter] = temp;
            counter++;
        }

    }








   // int counter =0;
   // for (int i=0; i < itemArray.size; i++)
    //{
      //  if (itemArray.forSale == 0)
        //    cout << itemArray.type[i] << ", "<< "for sale"<< ", " << itemArray.price[i];
        //if (itemArray.forsale == 1)
          //  cout << itemArray.type[i] << ", " << "wanted" << ", " << itemArray.price[i];
        //counter = counter + 1;/**<  */
    //}
}

int compareStuff(object itemsforSale[], object temp, int num)
{
        for (int i=0; i <= num;i++)

            if (itemsforSale[i].type == temp.type)
            {
                if (temp.wanted == false)
                {
                    if((itemsforSale[i].wanted == true) && (temp.price <= itemsforSale[i].price))
                    {
                        \ // if 1 is returned sell the item: don't add to array remove item in array
                        return = 1
                    }
                    else
                    {
                        return 0;
                    }
                }        // add to array
                else if (temp.wanted == true)
                {

                    if((itemsforSale[i].wanted == false) && (temp.price >= itemsforSale[i].price))
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            else
                flag = 0;
                break;     //add to array
        }
}
