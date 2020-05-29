#include "session.h"

string Session::getUsername()
{
    return USERNAME;
}

bool Session::getLogin()
{
    return login;
}

string Session::getLoginFile()
{
    return loginFile;
}

void Session::setBookFile(string x){
    bookFile = x;
}

string Session::getBookFile()
{
    return bookFile;
}


void Session::loginUser()
{
    if (getLogin())
    {
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
    if (username == "admin" && password == "i<3c++")
    { //тва със звездичката не се сещам как може да стане освен да вкарам паролата в някакъв динамичен масив и от там един фор да принтва '*' за всяко i
        USERNAME.assign("admin");
        login = true;
    }
    else
    {
        fstream fin(loginFile);
        if (fin.is_open())
        {
            login = false;
            while (!fin.eof() && !login)
            {
                fin >> fUserName;
                fin >> fPassword;
                if (fUserName == username && fPassword == password)
                {
                    USERNAME.assign(username);
                    login = true;
                }
            }
        }
        else
        {
            perror(loginFile.c_str());
        }
    }
    if (login)
    {
        cout << "welcome, " << USERNAME << endl;
    }
    else
    {
        cout << "wrong name or password" << endl;
    }
}

void Session::logoutUser()
{
    login = false;
    USERNAME.assign("");
}
