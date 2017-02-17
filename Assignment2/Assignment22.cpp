
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Alpha{
    string words;
    int freq;
};

void BubbleSort(Alpha wordslist[], int numwords);
bool compare_common(string a);


int main(int argc, char* argv[]){

    Alpha currentWord;
    int length = 100;

    Alpha* wordslist = new Alpha[length];
    int total_words = 0;

    char* filename = argv[1];   //grabs file name from command line
    char* num = argv[2];
    int n = stoi(num);
    ifstream infile;            //ifstream reads in a file

    infile.open(filename);
    string word;
    bool common = true;
    int numwords = 0;
    currentWord.freq = 1;
    int times_doubled = 0;

        while(infile >> word){

            common = compare_common(word);



            bool inArray = false;

            if(numwords == length){
                times_doubled =  times_doubled + 1;
                Alpha *newwordlist = new Alpha[length *2];
                for (int i=0; i < length;i++){
                newwordlist[i] = wordslist[i];

                }

                delete[]wordslist;
                length = length * 2;
                wordslist = newwordlist;

            }

            //cout << "im breaking your program"<< endl;
            if(common == false){
                total_words++;
                for (int i=0; i < numwords; i++){
                    if (word == wordslist[i].words){
                        wordslist[i].freq++;
                        inArray = true;
                        break;
                    }

                }
            }
            if(common == false){
                if (inArray == false){
                    wordslist[numwords].words = word;
                    numwords++;
                }
            }

        }

        BubbleSort(wordslist, numwords);

        for (int i=0; i < n; i++){
                cout << wordslist[i].freq << " - " <<wordslist[i].words << " " <<  endl;
        }
        cout << "#" << endl;
        cout << "Array doubled: " << times_doubled << endl;
        cout << "#" << endl;
        cout << "numwords2: " << numwords << endl;
        cout << "#" << endl;
        cout << "Total non - common words: " << total_words << endl;



}


//look into notes for doubling

bool compare_common(string a)
{
    string commonWord[50] = {"the", "be", "to", "of", "and", "a", "in",
    "that", "we", "have", "i", "it", "for", "not", "on", "with", "he", "as",
    "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say",
    "her", "she", "or", "an", "will", "my"};

    for (int i = 0; i < 50; i++)
    {
        if (a == commonWord[i])
        {
            return true;
        }

    }
    return false;
}

void BubbleSort(Alpha wordslist[], int numwords)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      Alpha temp;             // holding variable
      for(i = 1; (i <= numwords) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numwords -1); j++)
         {
               if (wordslist[j].freq < wordslist[j+1].freq)      // ascending order simply changes to <
              {
                    temp = wordslist[j];             // swap elements
                    wordslist[j] = wordslist[j+1];
                    wordslist[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}
