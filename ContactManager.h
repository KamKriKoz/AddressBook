#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Contact.h"
#include "ContactsFile.h"

using namespace std;

class ContactManager {

    int idLoggedUser;
    int lastContactId;
    vector <Contact> contacts;

    Contact enterNewContactDetails();
    int getNewContactId();
    ContactsFile contactsFile;

public:
    int getIdLoggedUser();
    void setLastContactId(int lastContact);
    void setIdLoggedUser(int loggedUser);
    void addContact();
    void showContacts();
    void showContactData(Contact person);
    void clearContacts();
    void loadContactsFromFile();
};

#endif // CONTACTMANAGER_H
