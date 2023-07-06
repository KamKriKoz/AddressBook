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

    int getIdLoggedUser();
    void userRegistration();
    void showUsers();
    void loadUsersFromFile();
    void logging();
    void passwordChange();
    void loggingOut();
};

#endif // USERMANAGER_H
