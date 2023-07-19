#include "ContactsFile.h"

int ContactsFile::getLastContactId() {

    return lastContactId;
}

bool ContactsFile::addToContactsFile(Contact person) {

    string lineWithData;
    fstream file;
    file.open(CONTACTS_FILE_NAME.c_str(), ios::app);

    if (file.good()) {
        lineWithData = transformatingContactToFormat(person);

        if (HelperMethods::whetherFileIsEmpty(file)) file << lineWithData;
        else file << endl << lineWithData;

        lastContactId++;
        return true;
    } else {
        cout << "File " << CONTACTS_FILE_NAME << " failed to open." << endl;
        return false;
    }

    file.close();
}

vector <Contact> ContactsFile::loadContactsFromFile(int idLoggedUser) {

    Contact person;
    vector <Contact> contacts;
    string oneContactData = "";
    string lastContactData = "";
    fstream file;
    file.open(CONTACTS_FILE_NAME.c_str(), ios::in);

    if (file.good()) {
        while (getline(file, oneContactData)) {

            if(idLoggedUser == getUserIdFromLine(oneContactData)) {

                person = downloadOneContactData(oneContactData);
                contacts.push_back(person);
            }
            lastContactId = getContactIdFromLine(oneContactData);
        }
    file.close();
    } else {
        cout << endl << "File " << CONTACTS_FILE_NAME << " failed to open." << endl << endl;
        file.close();
    }
    return contacts;
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

int ContactsFile::getUserIdFromLine(string oneContactData) {

    int position = oneContactData.find_first_of('|') + 1;
    return HelperMethods::conversionToInt(HelperMethods::getNumber(oneContactData, position));
}

int ContactsFile::getContactIdFromLine(string oneContactData) {

    return HelperMethods::conversionToInt(HelperMethods::getNumber(oneContactData, 0));
}

Contact ContactsFile::downloadOneContactData(string oneContactData) {

    Contact person;
    string singleData = "";
    int numberOfSingleData = 1;

    for (size_t position = 0; position < oneContactData.length(); position++) {
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
