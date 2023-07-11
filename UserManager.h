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
    UsersFile usersFile;

    void showSingleUser(size_t i);
    User enterNewUserDetails();
    int getNewUserId();
    bool whetherThereIsLogin(string login);


public:

    UserManager(string usersFileName) : usersFile(usersFileName) {
        idLoggedUser = 0;
        users = usersFile.loadUsersFromFile();
    };
    void logging();
    void userRegistration();
    void showUsers();
    void passwordChange();
    void loggingOut();
    bool whetherUserIsLogged();
    int getIdLoggedUser();
};

#endif // USERMANAGER_H
