#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <conio.h> tva e za zvezdichkite na parolata
//#include <cstdlib>
//#include <utility>
using namespace std;


class Book {
public:
    string author;
    string title;
    string genre;
    string shortDescription;
    string yearOfIssue;
    string keywords;
    float rating;
    int book_id;
public:
    Book(string author, string title, string genre, string shortDescription,
         string keywords, float rating, int bookId) : author(std::move(author)), title(std::move(title)),
                                                      genre(std::move(genre)),
                                                      shortDescription(std::move(shortDescription)),
                                                      keywords(std::move(keywords)),
                                                      rating(rating), book_id(bookId) {}

    void readFile(ifstream &in) {
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

    void input() {
        cin.ignore();
        cout << "Author : ";
        getline(cin, author, '\n');
        cout << "Title : ";
        getline(cin, title, '\n');
        cout << "Genre : ";
        getline(cin, genre, '\n');
        cout << "Short description : ";
        getline(cin, shortDescription, '\n');
        cout << "Year if issue : ";
        getline(cin, yearOfIssue, '\n');
        cout << "Keywords : ";
        getline(cin, keywords, '\n');
        cout << "Rating(out of 10) : ";
        cin >> rating;
        cout << "\"Unique\" number for the library : ";
        cin >> book_id;
        cin.ignore();
    }

    void writeFile(ofstream &out) {
        out << author << endl;
        out << title << endl;
        out << genre << endl;
        out << shortDescription << endl;
        out << yearOfIssue << endl;
        out << keywords << endl;
        out << rating << endl;
        out << book_id;
    }


    Book() {

    }

    void print() {
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
};

string USERNAME = "";
bool login = false;
string loginFile = "login.txt";
string bookFile = "books.txt";

void loginUser() {
    if (login) {
        cout << "The user is already logged in " << endl;
        return;
    }
    string username;
    string password;
    string fUserName;
    string fPassword;
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    //magic
    cin >> password;
    if (username == "admin" && password == "i<3c++") { //тва със звездичката не се сещам как може да стане освен да вкарам паролата в някакъв динамичен масив и от там един фор да принтва '*' за всяко i
        USERNAME.assign("admin");
        login = true;
    } else {
        fstream fin(loginFile);
        if (fin.is_open()) {
            login = false;
            while (!fin.eof() && !login) {
                fin >> fUserName;
                fin >> fPassword;
                if (fUserName == username && fPassword == password) {
                    USERNAME.assign(username);
                    login = true;
                }
            }
        } else {
            perror(loginFile.c_str());
        }
    }
    if (login) {
        cout << "Welcome, " << USERNAME << endl;
    } else {
        cout << "wrong name or password" << endl;
    }


}

class Library {
private:
    vector<Book *> books;
public:
    void addBook() {
        Book *b = new Book();
        b->input();
        books.push_back(b);          //that part here
    }

    void findBookOnTitle() {
        string title;
        getline(cin, title, '\n');
        if (title[0] == ' ')
            title.assign(title.substr(1));
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->title == title)
                books[i]->print();
        }
    }

    void findBookOnAuthor() {
        string author;
        getline(cin, author, '\n');
        if (author[0] == ' ')
            author.assign(author.substr(1));
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->author == author)
                books[i]->print();
        }
    }

    void findBookOnTag() {
        string tag;
        getline(cin, tag, '\n');
        if (tag[0] == ' ')
            tag.assign(tag.substr(1));
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->keywords.find(tag) == string::npos)
                books[i]->print();
        }
    }

    void bookInfo() {
        int book_id;
        cin >> book_id;
        cin.ignore();
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->book_id == book_id)
                books[i]->print();
        }
    }

    void printAllBooks() {
        for (int i = 0; i < books.size(); ++i) {
            books[i]->print();
        }
    }

    void sortOnAuthorDesc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->author < books[j + 1]->author) { //bubble sort, eventualno moje da sme smeni s neshto drugo
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On author in Descending order"<<endl;

    }

    void sortOnTitleDesc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->title < books[j + 1]->title) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Title in Descending order"<<endl;

    }

    void sortOnYearDesc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->yearOfIssue < books[j + 1]->yearOfIssue) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Year in Descending order"<<endl;

    }

    void sortOnRatingDesc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->rating < books[j + 1]->rating) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Rating in Acceding order"<<endl;

    }

    void sortOnAuthorAcc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->author > books[j + 1]->author) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Author in Acceding order"<<endl;
    }

    void sortOnTitleAcc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->title > books[j + 1]->title) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Title in Acceding order"<<endl;
    }

    void sortOnYearAcc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->yearOfIssue > books[j + 1]->yearOfIssue) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Year Acceding order"<<endl;
    }

    void sortOnRatingAcc() {
        int n = books.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (books[j]->rating > books[j + 1]->rating) {
                    Book *temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
        cout<<"Sorting Completed On Rating Acceding order"<<endl;
    }

    void readFile() {
        string fileName = "books.txt";
        cin>>fileName;
        ifstream fin(fileName);
        if (fin.is_open()) {
            while (!fin.eof()) {     //end of file
                Book *b = new Book();
                b->readFile(fin);
                books.push_back(b);
            }
        } else {
            perror(fileName.c_str());
            fin.close();
            return;
        }
        fin.close();
        cout << "File read Successfully" << endl;
    }

    void sort() {
        string op;
        getline(cin, op, '\n');
        bool desc = false;
        if (op.find("desc") != string::npos)
            desc = true;
        if (op.find("title") != string::npos) {
            if (desc)
                sortOnTitleDesc();
            else
                sortOnTitleAcc();
        } else if (op.find("author") != string::npos) {
            if (desc)
                sortOnAuthorDesc();
            else
                sortOnAuthorAcc();
        } else if (op.find("year") != string::npos) {
            if (desc)
                sortOnYearDesc();
            else
                sortOnYearAcc();
        } else if (op.find("rating") != string::npos) {
            if (desc)
                sortOnRatingDesc();
            else
                sortOnRatingAcc();
        }
    }

    void removeBook() {
        string book;
        cin.ignore();
        getline(cin, book, '\n');
        if (book[0] == ' ') {
            book.assign(book.substr(1));
        }
        int id = atoi(book.c_str());
        vector<Book *> temp;

        if (id > 0 && id < 500) {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i]->book_id != id) {
                    temp.push_back(books[i]);
                }
            }
        } else {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i]->author != book) {
                    temp.push_back(books[i]);
                }
            }
        }
        books.clear();
        books.assign(temp.begin(), temp.end());
    }

    void userAdd() {
        string fUserName;
        string fPassword;
        cin >> fUserName;
        cin >> fPassword;
        ofstream fout(loginFile, ios::app);
        if (fout.is_open()) {
            fout << fUserName << endl;
            fout << fPassword << endl;
        } else {
            perror(loginFile.c_str());
        }
    }

    void userRemove() {
        vector<string> names;
        string fUserName;
        string fPassword;
        string username;
        cin >> username;
        ifstream fin(loginFile);
        if (fin.is_open()) {
            login = false;
            while (!fin.eof() && !login) {
                fin >> fUserName;
                fin >> fPassword;
                if (fUserName != username) {
                    names.push_back(fUserName);
                    names.push_back(fPassword);
                }
            }
        } else {
            perror(loginFile.c_str());
            fin.close();
            return;
        }
        fin.close();
        ofstream fout(loginFile);
        if (fout.is_open())
            for (int i = 0; i < names.size(); ++i) {
                fout << names[i] << endl;
            }
        else {
            {
                perror(loginFile.c_str());
                fout.close();
                return;
            }
        }
        cout << "Removed Successfully" << endl;
    }

    void save() {
        ofstream out(bookFile);
        if (out.is_open()) {
            for (int i = 0; i < books.size(); ++i) {
                books[i]->writeFile(out);
                if (i != books.size() - 1)
                    out << endl;
            }
        } else {
            perror(bookFile.c_str());
        }
        cout /* << loginFile */ << "Saved successfully" << endl;
    }

    void saveAs() {
        cin >> bookFile;
        ofstream out(bookFile);
        if (out.is_open()) {
            for (int i = 0; i < books.size(); ++i) {
                books[i]->writeFile(out);
                if (i != books.size() - 1)
                    out << endl;
            }
        } else {
            perror(bookFile.c_str());
        }
    }

    void userMenu() {
        string option;
        while (true) {
            cout << "> ";
            cin >> option;
            if (option == "books" && login) {
                string arg1;
                cin >> arg1;
                if (login && USERNAME == "admin") {
                    if (arg1 == "add") {
                        addBook();
                    } else if (arg1 == "remove") {
                        removeBook();
                    }
                }
                if (arg1 == "all") {
                    printAllBooks();
                } else if (arg1 == "find") {
                    string arg2;
                    cin >> arg2;
                    if (arg2 == "title") {
                        findBookOnTitle();
                    } else if (arg2 == "author") {
                        findBookOnAuthor();
                    } else if (arg2 == "tag") {
                        findBookOnTag();
                    }
                } else if (arg1 == "info") {
                    bookInfo();
                } else if (arg1 == "sort") {
                    sort();
                }
            } else if (option == "logout" && login) {
                logout();
            } else if (option == "exit") {
                exit(0);
            } else if (option == "login") {
                loginUser();
            } else if (option == "open") {
                readFile();
            } else if (option == "close") {
                books.clear();
                cout << "Successfully closed " << bookFile << endl;
            } else if (option == "save") {
                save();
            } else if (option == "saveas") {
                saveAs();
            } else if (option == "help") {
                cout << "The following commands are supported:\n";
                cout << "--------------------------------------General options------------------------------------------\n";
                cout << "open <file>:                              opens <file>\n";
                cout << "close:                                    closes currently opened file\n";
                cout << "save:                                     saves the currently open file\n";
                cout << "saveas <file>:                            saves the currently open file in <file>\n";
                cout << "help:                                     prints this information\n";
                cout << "exit:                                     exits the program\n";
                cout << "--------------------------------------Program options------------------------------------------\n";
                cout << "login:                                    logs in the system\n";
                cout << "logout:                                   logs the logged in user out\n";
                cout << "books all:                                shows all the books available\n";
                cout << "books info <book_id>:                     shows info about chosen book\n";
                cout << "books find <option> <option_string>:      finds book (by author, title, tag)\n";
                cout << "books sort <option> [asc | desc]:         sorts listed books(title, year, author, rating\n";
                cout << "books add:                                adds a book    //admin only\n";
                cout << "books remove:                             removes a book //admin only\n";
                cout << "user add:                                 adds a user    //admin only\n";
                cout << "user remove:                              removes a user //admin only\n";
            } else if (option == "user") {
                string arg1;
                cin >> arg1;
                if (arg1 == "add") {
                    userAdd();
                } else if (arg1 == "remove") {
                    userRemove();
                }
            }
        }
    }

    void logout() {
        login = false;
        USERNAME.assign("");
    }

    void run() {
        userMenu();
    }

};

int main() {
    Library library;
    library.run();
    return 0;
}
