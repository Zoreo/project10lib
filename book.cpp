#include "book.h"

Book::Book() {}
Book::Book(string author, string title, string genre, string shortDescription,
           string keywords, float rating, int bookId) : author(std::move(author)), 
                                                        title(std::move(title)),
                                                        genre(std::move(genre)),
                                                        shortDescription(std::move(shortDescription)),
                                                        keywords(std::move(keywords)),
                                                        rating(rating), book_id(bookId) {}

string Book::getAuthor()
{
    return author;
}
string Book::getTitle()
{
    return title;
}
string Book::getGenre()
{
    return genre;
}
string Book::getShortDescription()
{
    return shortDescription;
}
string Book::getYearOfIssue()
{
    return yearOfIssue;
}
string Book::getKeywords()
{
    return keywords;
}
float Book::getRating()
{
    return rating;
}
int Book::getBookId()
{
    return book_id;
}

void Book::readFile(ifstream &in)
{
    getline(in, author, '\n');
    getline(in, title, '\n');
    getline(in, genre, '\n');
    getline(in, shortDescription, '\n');
    getline(in, yearOfIssue, '\n');
    getline(in, keywords, '\n');
    in >> rating;
    in >> book_id;
    in.ignore();
}

void Book::input()
{
    cin.ignore();
    cout << "Author : ";
    getline(cin, author, '\n');
    cout << "Title : ";
    getline(cin, title, '\n');
    cout << "Genre : ";
    getline(cin, genre, '\n');
    cout << "Short description : ";
    getline(cin, shortDescription, '\n');
    cout << "Year of issue : ";
    getline(cin, yearOfIssue, '\n');
    cout << "Keywords : ";
    getline(cin, keywords, '\n');
    cout << "Rating(out of 10) : ";
    cin >> rating;
    cout << "\"Unique\" number for the library : ";
    cin >> book_id;
    cin.ignore();
}

void Book::writeFile(ofstream &out)
{
    out << author << endl;
    out << title << endl;
    out << genre << endl;
    out << shortDescription << endl;
    out << yearOfIssue << endl;
    out << keywords << endl;
    out << rating << endl;
    out << book_id;
}

void Book::print()
{
    cout << "==================================================================================" << endl;
    cout << "Author : " << author << endl;
    cout << "Title : " << title << endl;
    cout << "Genre : " << genre << endl;
    cout << "Short description : " << shortDescription << endl;
    cout << "Year if issue : " << yearOfIssue << endl;
    cout << "Keywords : " << keywords << endl;
    cout << "Rating(out of 10) : " << rating << endl;
    cout << "Unique number for the library : " << book_id;
    cout << endl;
}
