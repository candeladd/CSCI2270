#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>

struct Movie{
    std::string title;
    int year;
    Movie *next=NULL;

    Movie(){};

    Movie(std::string in_title, int in_year)
    {
        title = in_title;
        year = in_year;

    }


};

class HashTable
{
    public:
        HashTable(int);
        ~HashTable();
        void insertMovie(Movie* poin);
        Movie* findMovie(std::string in_title, int index);
        void deleteMovie(std::string in_title);
        void printInventory();
        int hashSum(std::string x, int s);
    protected:
    private:
        Movie *hashTable;
        std::vector <Movie*> hashT = {};
};

#endif // HASHTABLE_H
