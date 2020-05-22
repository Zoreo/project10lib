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
    string get_author();
    string get_title();
    string get_genre();
    string get_shortDescription();
    string get_yearOfIssue();
    string get_keywords();
    float get_rating();
    int get_book_id();
    void readFile(ifstream &in);
    void input();
    void writeFile(ofstream &out);
    void print();
};