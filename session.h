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
    string get_USERNAME();
    bool get_login();
    string get_loginFile();
    string get_bookFile();
    void set_bookFile(string x);
    void loginUser();
    void logoutUser();
};