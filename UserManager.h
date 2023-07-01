#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {

    int idLoggedUser;
    vector <User> users;

    User enterNewUserDetails();
    int getNewUserId();
    bool whetherThereIsLogin(string login);
    UsersFile usersFile;

public:
    UserManager(string usersFileName):usersFile(usersFileName) {};
    void userRegistration();
    void showUsers();
    void loadUsersFromFile();
};

#endif // USERMANAGER_H
