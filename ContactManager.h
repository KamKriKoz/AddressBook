#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Contact.h"
//#include "ContactsFile.h"

using namespace std;

class ContactManager {

    int idLoggedUser;
    vector <Contact> contacts;

    Contact enterNewContactDetails();
    int getNewContactId();
  //  ContactsFile contactsFile;

public:
 //   ContactManager(string contactsFileName):contactsFile(contactsFileName) {};
    void setIdLoggedUser(int loggedUser);
    void addContact();
    void showContacts();
    void showContactData(Contact person);
    void clearContacts();
 //   void loadContactsFromFile();
};

#endif // CONTACTMANAGER_H
