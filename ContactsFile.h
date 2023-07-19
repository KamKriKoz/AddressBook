#ifndef CONTACTSFILE_H
#define CONTACTSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Contact.h"
#include "HelperMethods.h"
#include "TextFile.h"

using namespace std;

class ContactsFile : public TextFile {

    int lastContactId;

    string transformatingContactToFormat(Contact person);
    Contact downloadOneContactData(string oneContactData);
    int getUserIdFromLine(string oneContactData);
    int getContactIdFromLine(string oneContactData);
    void fileSwapAndDelete (string temporaryFileName);

public:

    ContactsFile(string fileName) : TextFile(fileName) {
        lastContactId = 0;
    };
    bool addToContactsFile(Contact person);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getLastContactId();
    void modifyContactsFileAfterDelete(int contactIdToDelete);
    void modifyContactsFileAfterEdit(Contact contactToEdit);
};

#endif // CONTACTSFILE_H
