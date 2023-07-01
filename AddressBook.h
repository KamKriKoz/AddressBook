#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;

public:
    AddressBook(string usersFileName):userManager(usersFileName) {
        userManager.loadUsersFromFile();
    };
    void userRegistration();
    void showUsers();
};

#endif // ADDRESSBOOK_H
