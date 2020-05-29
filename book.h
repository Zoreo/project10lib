#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Book
{
private:
    string author;
    string title;
    string genre;
    string shortDescription;
    string yearOfIssue;
    string keywords;
    float rating;
    int book_id;

public:
    Book();
    Book(string author, string title, string genre, string shortDescription, string keywords, float rating, int bookId);
    string getAuthor();
    string getTitle();
    string getGenre();
    string getShortDescription();
    string getYearOfIssue();
    string getKeywords();
    float getRating();
    int getBookId();
    void readFile(ifstream &in);
    void input();
    void writeFile(ofstream &out);
    void print();
};