#include "library.h"

Library::Library(Session _session) : session(_session) {}

void Library::addBook()
{
    Book *b = new Book();
    b->input();
    books.push_back(b); //that part here
}

void Library::findBookOnTitle()
{
    string title;
    getline(cin, title, '\n');
    if (title[0] == ' ')
        title.assign(title.substr(1));
    for (int i = 0; i < books.size(); ++i)
    {
        if (books[i]->getTitle() == title)
            books[i]->print();
    }
}

void Library::findBookOnAuthor()
{
    string author;
    getline(cin, author, '\n');
    if (author[0] == ' ')
        author.assign(author.substr(1));
    for (int i = 0; i < books.size(); ++i)
    {
        if (books[i]->getAuthor() == author)
            books[i]->print();
    }
}

void Library::findBookOnTag()
{
    string tag;
    getline(cin, tag, '\n');
    if (tag[0] == ' ')
        tag.assign(tag.substr(1));
    for (int i = 0; i < books.size(); ++i)
    {
        if (books[i]->getKeywords().find(tag) == string::npos)
            books[i]->print();
    }
}

void Library::bookInfo()
{
    int book_id;
    cin >> book_id;
    cin.ignore();
    for (int i = 0; i < books.size(); ++i)
    {
        if (books[i]->getBookId() == book_id)
            books[i]->print();
    }
}

void Library::printAllBooks()
{
    for (int i = 0; i < books.size(); ++i)
    {
        books[i]->print();
    }
}

void Library::sortOnAuthorDesc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getAuthor() < books[j + 1]->getAuthor())
            { //bubble sort, eventualno moje da sme smeni s neshto drugo
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On author in Descending order" << endl;
}

void Library::sortOnTitleDesc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getTitle() < books[j + 1]->getTitle())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Title in Descending order" << endl;
}

void Library::sortOnYearDesc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getYearOfIssue() < books[j + 1]->getYearOfIssue())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Year in Descending order" << endl;
}

void Library::sortOnRatingDesc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getRating() < books[j + 1]->getRating())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Rating in Acceding order" << endl;
}

void Library::sortOnAuthorAcc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getAuthor() > books[j + 1]->getAuthor())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Author in Acceding order" << endl;
}

void Library::sortOnTitleAcc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getTitle() > books[j + 1]->getTitle())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Title in Acceding order" << endl;
}

void Library::sortOnYearAcc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getYearOfIssue() > books[j + 1]->getYearOfIssue())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Year Acceding order" << endl;
}

void Library::sortOnRatingAcc()
{
    int n = books.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (books[j]->getRating() > books[j + 1]->getRating())
            {
                Book *temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
    cout << "Sorting Completed On Rating Acceding order" << endl;
}

void Library::readFile()
{
    string fileName = "books.txt";
    cin >> fileName;
    ifstream fin(fileName);
    if (fin.is_open())
    {
        while (!fin.eof())
        { //end of file
            Book *b = new Book();
            b->readFile(fin);
            books.push_back(b);
        }
    }
    else
    {
        perror(fileName.c_str());
        fin.close();
        return;
    }
    fin.close();
    cout << "File read Successfully" << endl;
}

void Library::sort()
{
    string op;
    getline(cin, op, '\n');
    bool desc = false;
    if (op.find("desc") != string::npos)
        desc = true;
    if (op.find("title") != string::npos)
    {
        if (desc)
            sortOnTitleDesc();
        else
            sortOnTitleAcc();
    }
    else if (op.find("author") != string::npos)
    {
        if (desc)
            sortOnAuthorDesc();
        else
            sortOnAuthorAcc();
    }
    else if (op.find("year") != string::npos)
    {
        if (desc)
            sortOnYearDesc();
        else
            sortOnYearAcc();
    }
    else if (op.find("rating") != string::npos)
    {
        if (desc)
            sortOnRatingDesc();
        else
            sortOnRatingAcc();
    }
}

void Library::removeBook()
{
    string book;
    cin.ignore();
    getline(cin, book, '\n');
    if (book[0] == ' ')
    {
        book.assign(book.substr(1));
    }
    int id = atoi(book.c_str());
    vector<Book *> temp;

    if (id > 0 && id < 500)
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i]->getBookId() != id)
            {
                temp.push_back(books[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i]->getAuthor() != book)
            {
                temp.push_back(books[i]);
            }
        }
    }
    books.clear();
    books.assign(temp.begin(), temp.end());
}

void Library::userAdd()
{
    string fUserName;
    string fPassword;
    cin >> fUserName;
    cin >> fPassword;
    ofstream fout(session.getLoginFile(), ios::app);
    if (fout.is_open())
    {
        fout << fUserName << endl;
        fout << fPassword << endl;
    }
    else
    {
        perror(session.getLoginFile().c_str());
    }
}

void Library::userRemove()
{
    vector<string> names;
    string fUserName;
    string fPassword;
    string username;
    cin >> username;
    ifstream fin(session.getLoginFile());
    if (fin.is_open())
    {
        session.logoutUser();
        while (!fin.eof() && !session.getLogin())
        {
            fin >> fUserName;
            fin >> fPassword;
            if (fUserName != username)
            {
                names.push_back(fUserName);
                names.push_back(fPassword);
            }
        }
    }
    else
    {
        perror(session.getLoginFile().c_str());
        fin.close();
        return;
    }
    fin.close();
    ofstream fout(session.getLoginFile());
    if (fout.is_open())
        for (int i = 0; i < names.size(); ++i)
        {
            fout << names[i] << endl;
        }
    else
    {
        {
            perror(session.getLoginFile().c_str());
            fout.close();
            return;
        }
    }
    cout << "Removed Successfully" << endl;
}

void Library::save()
{
    ofstream out(session.getBookFile());
    if (out.is_open())
    {
        for (int i = 0; i < books.size(); ++i)
        {
            books[i]->writeFile(out);
            if (i != books.size() - 1)
                out << endl;
        }
    }
    else
    {
        perror(session.getBookFile().c_str());
    }
    cout /* << session.loginFile */ << "Saved successfully" << endl;
}

void Library::saveAs()
{
    string filename;
    cin >> filename;
    session.setBookFile(filename);
    ofstream out(session.getBookFile());
    if (out.is_open())
    {
        for (int i = 0; i < books.size(); ++i)
        {
            books[i]->writeFile(out);
            if (i != books.size() - 1)
                out << endl;
        }
    }
    else
    {
        perror(session.getBookFile().c_str());
    }
}

void Library::userMenu()
{
    string option;
    while (true)
    {
        cout << "> ";
        cin >> option;
        if (option == "books")
        {
            string arg1;
            cin >> arg1;
            if (!session.getLogin())
            {
                cout << "You need to log in first.\n";
            }
            if (session.getLogin())
            {
                //admin
                if (arg1 == "add" && session.getUsername() == "admin")
                {
                    addBook();
                    cout << "Book added.\n";
                }
                if (arg1 == "add" && session.getUsername() != "admin")
                {
                    cout << "admin level access is required to add books.\n";
                }
                if (arg1 == "remove" && session.getUsername() == "admin")
                {
                    removeBook();
                    cout << "Book removed.\n";
                }
                if (arg1 == "remove" && session.getUsername() != "admin")
                {
                    cout << "admin level access is required to remove books.\n";
                }

                //user level required
                if (arg1 == "all")
                {
                    printAllBooks();
                }
                else if (arg1 == "find")
                {
                    string arg2;
                    cin >> arg2;
                    if (arg2 == "title")
                    {
                        findBookOnTitle();
                    }
                    else if (arg2 == "author")
                    {
                        findBookOnAuthor();
                    }
                    else if (arg2 == "tag")
                    {
                        findBookOnTag();
                    }
                }
                else if (arg1 == "info")
                {
                    bookInfo();
                }
                else if (arg1 == "sort")
                {
                    sort();
                }
            }
        }
        //admin level rq
        else if (option == "user")
        {
            string arg1;
            cin >> arg1;
            if (!session.getLogin())
            {
                cout << "You need to log in first.\n";
            }
            if (arg1 == "add" && session.getUsername() == "admin")
            {
                userAdd();
                cout << "User added.\n";
            }
            if (arg1 == "add" && session.getUsername() != "admin")
            {
                cout << "admin level access is required to add users.\n";
            }
            if (arg1 == "remove" && session.getUsername() == "admin")
            {
                userRemove();
                cout << "User removed.\n";
            }
            if (arg1 == "remove" && session.getUsername() != "admin")
            {
                cout << "admin level access is required to remove users.\n";
            }
        }
        else if (option == "logout" && session.getLogin())
        {
            session.logoutUser();
        }
        else if (option == "logout" && !session.getLogin())
        {
            cout << "You're already logged out";
        }
        //commands with no required access level
        else if (option == "exit")
        {
            exit(0);
        }
        else if (option == "login")
        {
            session.loginUser();
        }
        else if (option == "open")
        {
            readFile();
        }
        else if (option == "close")
        {
            books.clear();
            cout << "Successfully closed " << session.getBookFile() << endl;
        }
        else if (option == "save")
        {
            save();
        }
        else if (option == "saveas")
        {
            saveAs();
        }
        else if (option == "help")
        {
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
        }
    }
}

void Library::run()
{
    userMenu();
}
