#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "ContactManager.h"
#include <conio.h>

using namespace std;

class AddressBook {

    UserManager userManager;
    ContactManager contactManager;

public:

    void loadUsers();
    void userRegistration();
    void showUsers();
    void logging();
};

#endif // ADDRESSBOOK_H
