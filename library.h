#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>
#include "book.h"
#include "session.h"
using namespace std;

class Library
{
private:
    Session session;
    vector<Book *> books;

public:
    Library(Session _session);
    void addBook();
    void findBookOnTitle();
    void findBookOnAuthor();
    void findBookOnTag();
    void bookInfo();
    void printAllBooks();
    void bubble_sort(std::function<bool(Book, Book)>);
    void sortOnAuthorDescnew();
    void sortOnAuthorDesc();
    void sortOnTitleDesc();
    void sortOnYearDesc();
    void sortOnRatingDesc();
    void sortOnAuthorAcc();
    void sortOnTitleAcc();
    void sortOnYearAcc();
    void sortOnRatingAcc();
    void readFile();
    void sort();
    void removeBook();
    void userAdd();
    void userRemove();
    void save();
    void saveAs();
    void userMenu();
    void run();
};