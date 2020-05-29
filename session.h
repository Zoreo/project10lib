#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Session
{
private:
    string USERNAME = "";
    bool login = false;
    string loginFile = "login.txt";
    string bookFile = "books.txt";

public:
    string getUsername();
    bool getLogin();
    string getLoginFile();
    string getBookFile();
    void setBookFile(string x);
    void loginUser();
    void logoutUser();
};