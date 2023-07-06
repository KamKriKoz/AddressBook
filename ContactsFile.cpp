#include "ContactsFile.h"

ContactsFile::ContactsFile() {

    contactsFileName = "Contacts.txt";
    lastContactId = 0;
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

vector <Contact> ContactsFile::loadContactsFromFile(int idLoggedUser) {

    Contact person;
    vector <Contact> contacts;
    string oneContactData = "";
    string lastContactData = "";
    fstream file;
    file.open(contactsFileName.c_str(), ios::in);

    if (file.good() == true) {
        while (getline(file, oneContactData)) {

            if(idLoggedUser == getUserIdFromLine(oneContactData)) {

                person = downloadOneContactData(oneContactData);
                contacts.push_back(person);
            }
            lastContactId = getContactIdFromLine(oneContactData);
        }
    } else cout << endl << "File " << contactsFileName << " failed to open." << endl << endl;

    file.close();

    return contacts;
}

int ContactsFile::getUserIdFromLine(string oneContactData) {

    int position = oneContactData.find_first_of('|') + 1;
    int userId = HelperMethods::conversionToInt(HelperMethods::getNumber(oneContactData, position));

    return userId;
}

int ContactsFile::getContactIdFromLine(string oneContactData) {

    int position = 0;
    int contactId = HelperMethods::conversionToInt(HelperMethods::getNumber(oneContactData, position));

    return contactId;
}

Contact ContactsFile::downloadOneContactData(string oneContactData) {

    Contact person;
    string singleData = "";
    int numberOfSingleData = 1;

    for (int position = 0; position < oneContactData.length(); position++) {
        if (oneContactData[position] != '|') singleData += oneContactData[position];
        else {
            switch (numberOfSingleData) {
            case 1:
                person.setContactId(atoi(singleData.c_str()));
                break;
            case 2:
                person.setUserId(atoi(singleData.c_str()));
                break;
            case 3:
                person.setName(singleData);
                break;
            case 4:
                person.setLastName(singleData);
                break;
            case 5:
                person.setTelNumber(singleData);
                break;
            case 6:
                person.setEmail(singleData);
                break;
            case 7:
                person.setAddress(singleData);
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }
    return person;
}

int ContactsFile::getLastContactId() {

    return lastContactId;
}

