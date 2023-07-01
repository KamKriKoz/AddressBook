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

    const string usersFileName;
    bool whetherFileIsEmpty(fstream &file);
    string transformatingToFormat(User person);
    User downloadOneUserData(string oneUserData);

public:
    UsersFile(string USERSFILENAME):usersFileName(USERSFILENAME) {};
    void addToUsersFile(User person);
    vector <User> loadUsersFromFile();
};

#endif // USERFILE_H
