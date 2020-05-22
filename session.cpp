#include "session.h"

string Session::get_username()
{
    return username;
}
bool Session::get_login()
{
    return login;
}
string Session::get_loginFile()
{
    return loginFile;
}
string Session::get_bookFile()
{
    return bookFile;
}

void Session::loginUser()
{
    if (login)
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
        username.assign("admin");
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
                    username.assign(username);
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
        cout << "Welcome, " << username << endl;
    }
    else
    {
        cout << "wrong name or password" << endl;
    }
}

void Session::logout()
{
    login = false;
    username.assign("");
}