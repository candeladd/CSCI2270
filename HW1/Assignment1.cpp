//Andrew Candelaresi
//Data structures
//Assignment 1
// collborated with James Draper

//comments should be red
#include <iostream>
#include <fstream>

using namespace std;

struct object{
    string type;
    bool wanted; //true = wanted, false = for sale
    int price;
};
int operations = 0;


int main(int argc, char* argv[]) {

    object itemsforSale[100];

    char* filename = argv[1];   //grabs file name from command line

    ifstream infile;            //ifstream reads in a file

    infile.open(filename);  //infile opens the file for reading

    int counter = 0;

    while(!infile.eof()){    //looping until the end of file

        object temp;    //creating an object

        operations++;
        string type;
        string wanted;
        string price;
        getline(infile, type,',');      //getline says to read from infile, look for type, and go until ','
        getline(infile, wanted,',');
        getline(infile, price);         //no need for ',' since it's the end of the line
        //cout << "type: " << type << endl;
        //cout << "wanted:" << wanted << endl;
        //cout << "price:" << price << endl;

        temp.type = type;

        if(wanted == " wanted"){
            temp.wanted = true;
        }
        else{
            temp.wanted = false;
        }

        temp.price = atoi(price.c_str());


        //cout << temp.wanted << endl;
        //int counter = 0;
        int i = 0;
        int flag = 0;
        for(i = 0; i <= counter; i++){
                operations++;
            if(itemsforSale[i].type == temp.type){
                if((temp.wanted == false)&& (itemsforSale[i].wanted == true)&&(temp.price <= itemsforSale[i].price)){
                        //cout << "made it here 1" << endl;
                        flag = 1; // if true is returned sell the item: don't add to array remove item in array
                        cout << temp.type << " " << temp.price << endl;
                        break;


                }
                else if((temp.wanted == true)&&(itemsforSale[i].wanted == false)&&(temp.price >= itemsforSale[i].price)){
                        //cout << "made it here 3" << endl;
                        cout << itemsforSale[i].type << " " << itemsforSale[i].price << endl;
                        flag = 1;
                        break;
                }

            }
        }


        if (flag == 1){
            //remove the item it matched with
            //item was sold
        operations++;
            for (int j = i; j < counter; j++){

                itemsforSale[j] = itemsforSale[j + 1];
                //cout << "made it here 7" << endl;
            }
            counter--;

        }

        else if (flag == 0){
        operations++;
            itemsforSale[counter] = temp;
            counter++;
        }

    }

    cout << "#" << endl;
    for (int i = 0; i <= counter; i++){

        if (itemsforSale[i].wanted == 1){
            cout << itemsforSale[i].type << ", " << "wanted" << ", " << itemsforSale[i].price << endl;
        }
        else{
            cout << itemsforSale[i].type << ", " << "for sale" << ", " << itemsforSale[i].price << endl;
        }

        //cout << itemsforSale[i].type << " " << itemsforSale[i].wanted << " " << itemsforSale[i].price << endl;
    }

    cout << "#" << endl;
    cout << "operations; "<< operations << endl;

    return 0;

}
