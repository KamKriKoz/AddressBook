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

void ContactsFile::modifyContactsFileAfterDelete(int contactIdToDelete) {

    string line, field, temporaryFileName = "temporaryContacts.txt";
    bool flag = false;
    ifstream file(CONTACTS_FILE_NAME, ios::in);
    ofstream temporaryfile(temporaryFileName, ios::out);

    while (getline(file, line)) {

        istringstream iss(line);
        getline(iss, field, '|');

        if (stoi(field) != contactIdToDelete) {

            if (!flag) {
                temporaryfile << line;
                lastContactId = stoi(field);
                flag = true;
            }
            else {
                temporaryfile << endl;
                temporaryfile << line;
                lastContactId = stoi(field);
            }
        }
    }

    file.close();
    temporaryfile.close();

    fileSwapAndDelete(temporaryFileName);
}

void ContactsFile::modifyContactsFileAfterEdit(Contact contactToEdit) {

    string line, field, temporaryFileName = "temporaryContacts.txt";
    bool flag = false;
    ifstream file(CONTACTS_FILE_NAME, ios::in);
    ofstream temporaryfile(temporaryFileName, ios::out);

    while (getline(file, line)) {

        istringstream iss(line);
        getline(iss, field, '|');

        if(stoi(field) != contactToEdit.getContactId()){

            if(!flag) {
                temporaryfile << line;
                flag = true;
            }
            else {
                temporaryfile << endl;
                temporaryfile << line;
            }
        }
        else {
            if(!flag) {
                temporaryfile << transformatingContactToFormat(contactToEdit);
                flag = true;
            }
            else {
                temporaryfile << endl;
                temporaryfile << transformatingContactToFormat(contactToEdit);
            }
        }
    }

    file.close();
    temporaryfile.close();

    fileSwapAndDelete(temporaryFileName);
}

void ContactsFile::fileSwapAndDelete(string temporaryFileName) {

    if (std::remove(CONTACTS_FILE_NAME.c_str()) != 0) perror("Error removing file");
    if (rename(temporaryFileName.c_str(), CONTACTS_FILE_NAME.c_str()) != 0) perror("Error renaming file");
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
