
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int counter = 0;


struct object
{
    string type;
    int price;
    int wanted;
};


//void openFile()

int main(int argc, char* argv[])
{
    counter++;
    ifstream myfile;
    myfile.open(argv[1]);

    const int NUM_ROWS = 100;
    object itemsforSale[NUM_ROWS];
    itemsforSale[NUM_ROWS-1].type = "end";

    int x = 0;
    while (!myfile.eof())
    {
        object temp;

        string type;
        string status;
        string price;
        getline(myfile, type, ',');
        getline(myfile, status, ',');
        getline(myfile, price);
        //cout << "type: " << type << " "<<
        //"price: " << price <<" "<<
        //"status: "<< status << endl;


        temp.price = atoi(price.c_str());
        temp.type = type;

        if (status == " wanted")
        {
            temp.wanted = 1;
        }
        else
        {
            temp.wanted = 0;
        }
        cout << temp.type<< " "<< temp.wanted<< " " << temp.price<< endl;
        //cout << status<< "*" <<endl;
        //cout << " wanted" << "*" <<endl;
        int flag = 0;
        int flag2 = 0;
        for (int i = 0; i < x;i++)
        {
            cout <<"here we go" << endl;
            if (itemsforSale[i].type == temp.type)
            {
                counter++;
                cout << "passed first if"<< endl;
                cout << itemsforSale[i].wanted << " " << temp.wanted << endl;
                if ((temp.wanted != itemsforSale[i].wanted)
                {

                    cout << "hi"<< endl;
                    if(temp.price <= itemsforSale[i].price)
                    {
                      for (int j=i; j < x; j++)
                            {
                                counter++;
                                cout << "shifting"<< endl;
                                itemsforSale[j].type = itemsforSale[j + 1].type;
                                itemsforSale[j].price = itemsforSale[j+1].price;
                                itemsforSale[j].wanted = itemsforSale[j+1].price;

                            }

                            x--;
                            break;
                    }
                }
                else if ((temp.wanted == 1) && (itemsforSale[i].wanted == 0))
                {

                   if(temp.price >= itemsforSale[i].price)
                    {
                        //cout << "type" <<  temp.type <<  "price"<<temp.price "sold" << endl;
                       cout <<"sold" << endl;
                        flag = i; // if 1 is returned sell the item: don't add to array remove item in array
                        if (flag == i)
                        {
            //remove the item it matched with.
                 //item was sold
                            for (int j=i; j < x; j++)
                            {
                                counter++;
                                cout << "shifting"<< endl;
                                itemsforSale[j].type = itemsforSale[j + 1].type;
                                itemsforSale[j].price = itemsforSale[j+1].price;
                                itemsforSale[j].wanted = itemsforSale[j+1].price;

                            }

                            x--;
                            break;
                        }

                    }
                }


            }
                        // add to array

            else
            {   cout << "flag 02" << endl;
                flag2 = x;
                break;
            }

          //cout << "this is how far" << endl;


        }



        if (flag2 == x)
        {
            cout << "add to array" << endl;
            for (int i=x; i < NUM_ROWS; i++)
            {itemsforSale[x] = temp;
            }
            x++;
        }
    }

        for (int i=0; i< x; i++)
        {
         cout << itemsforSale[i].type<< " " << itemsforSale[i].price << endl;
        }


    return 0;







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



