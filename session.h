#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Session
{
private:
    string username = "";
    bool login = false;
    string loginFile = "login.txt";
    string bookFile = "books.txt";

public:
    string get_username();
    bool get_login();
    string get_loginFile();
    string get_bookFile();
    void loginUser();
    void logout();
};