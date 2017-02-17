#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Alpha{
    string words;
    int freq;
};


bool compare_common(string a);

int main(int argc, char* argv[]){


    char* filename = argv[1];   //grabs file name from command line

    ifstream infile;            //ifstream reads in a file

    infile.open(filename);
    string line;
        while(getline(infile,line)){

            string word;
            stringstream ss(line);
            ss >> word;

            cout << word<< endl;
        }
}


//look into notes for doubling

/*bool compare_common(string a){
    string commonWord[] = [the, be, to, of, and, a, in, that, we, have, i, it, for, not, on , with, he, as, you, do, at, this, but, his, by, from, they, we, say, her, she, or, an, will, my]
    for (int i= 0; i<= commonWord[]; i++){
        if (string == commonWord[i]{
            found == false;
            }
        else
            found ==  true;
    }
    return found;
         }*/
