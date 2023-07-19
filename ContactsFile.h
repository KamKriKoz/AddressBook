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

    const string CONTACTS_FILE_NAME;
    int lastContactId;

    string transformatingContactToFormat(Contact person);
    Contact downloadOneContactData(string oneContactData);
    int getUserIdFromLine(string oneContactData);
    int getContactIdFromLine(string oneContactData);
    void fileSwapAndDelete (string temporaryFileName);

public:

    ContactsFile(string contactsFileName) : CONTACTS_FILE_NAME(contactsFileName) {
        lastContactId = 0;
    };
    bool addToContactsFile(Contact person);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getLastContactId();
    void modifyContactsFileAfterDelete(int contactIdToDelete);
};

#endif // CONTACTSFILE_H
