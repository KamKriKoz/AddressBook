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
    string transformatingContactToFormat(Contact person);
    // Contact downloadOneUserData(string oneUserData);

public:
    ContactsFile();
    void addToContactsFile(Contact person);
   // vector <Contact> loadContactsFromFile();
};

#endif // CONTACTSFILE_H
