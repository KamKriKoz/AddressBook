#ifndef CONTACTSFILE_H
#define CONTACTSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Contact.h"
#include "HelperMethods.h"


using namespace std;

class ContactsFile {

    string contactsFileName;
    int lastContactId;
    string transformatingContactToFormat(Contact person);
    Contact downloadOneContactData(string oneContactData);
    int getUserIdFromLine(string oneContactData);
    int getContactIdFromLine(string oneContactData);

public:
    ContactsFile();
    void addToContactsFile(Contact person);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getLastContactId();
};

#endif // CONTACTSFILE_H
