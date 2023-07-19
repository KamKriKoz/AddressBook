#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "Contact.h"
#include "ContactsFile.h"

using namespace std;

class ContactManager {

    const int ID_LOGGED_USER;
    ContactsFile contactsFile;
    vector <Contact> contacts;

    Contact enterNewContactDetails();
    void showContactData(Contact person);
    void editMenu();

public:

    ContactManager(string contactsFileName, int idLoggedUser)
        : contactsFile(contactsFileName), ID_LOGGED_USER(idLoggedUser) {
        contacts = contactsFile.loadContactsFromFile(ID_LOGGED_USER);
    };
    void addContact();
    void showAllContacts();
    void searchByName();
    void searchByLastName();
    void deleteContact();
    void editContact();
};

#endif // CONTACTMANAGER_H
