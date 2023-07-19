#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "ContactManager.h"
#include <conio.h>

using namespace std;

class AddressBook {

    UserManager userManager;
    ContactManager *contactManager;
    const string CONTACTS_FILE_NAME;

public:

    AddressBook (string usersFileName, string contactsFileName)
        : userManager(usersFileName), CONTACTS_FILE_NAME(contactsFileName) {
        contactManager = NULL;
    };

    ~AddressBook() {
        delete contactManager;
        contactManager = NULL;
    }

    void userRegistration();
    void showUsers();
    void logging();
    void passwordChange();
    void loggingOut();
    void addContact();
    void showAllContacts();
    void loginMenu();
    void userMenu();
    bool whetherUserIsLogged();
    void searchByName();
};

#endif // ADDRESSBOOK_H
