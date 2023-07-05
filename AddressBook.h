#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include <conio.h>

using namespace std;

class AddressBook {

    UserManager userManager;

public:
    AddressBook(string usersFileName):userManager(usersFileName) {
        userManager.loadUsersFromFile();
    };
    void userRegistration();
    void showUsers();
    void logging();
};

#endif // ADDRESSBOOK_H
