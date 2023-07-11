#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelperMethods.h"


using namespace std;

class UsersFile {

    const string USERS_FILE_NAME;
    string transformatingToFormat(User person);
    User downloadOneUserData(string oneUserData);

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {};
    void addToUsersFile(User person);
    vector <User> loadUsersFromFile();
    void overwriteUsersFile(vector <User> &users);
};

#endif // USERFILE_H
