#include "ContactsFile.h"

ContactsFile::ContactsFile() {

    contactsFileName = "Contacts.txt";
}

void ContactsFile::addToContactsFile(Contact person) {

    string lineWithData;
    fstream file;
    file.open(contactsFileName.c_str(), ios::app);

    if (file.good() == true) {
        lineWithData = transformatingContactToFormat(person);
        if (HelperMethods::whetherFileIsEmpty(file) == true) file << lineWithData;
        else file << endl << lineWithData;
        file.close();
    }
    else cout << "File " << contactsFileName << " failed to open." << endl;
}

string ContactsFile::transformatingContactToFormat(Contact person) {

    string lineWithData = "";
    lineWithData += HelperMethods::conversionToString(person.getContactId()) + '|';
    lineWithData += HelperMethods::conversionToString(person.getUserId()) + '|';
    lineWithData += person.getName() + '|';
    lineWithData += person.getLastName() + '|';
    lineWithData += person.getTelNumber() + '|';
    lineWithData += person.getEmail() + '|';
    lineWithData += person.getAddress() + '|';

    return lineWithData;
}
