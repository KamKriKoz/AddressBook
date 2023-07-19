#include "UsersFile.h"

void UsersFile::addToUsersFile(User person) {

    string lineWithData;
    fstream file;
    file.open(getFileName().c_str(), ios::app);

    if (file.good()) {
        lineWithData = transformatingToFormat(person);
        if (whetherFileIsEmpty()) file << lineWithData;
        else file << endl << lineWithData;
        file.close();
    }
    else cout << "File " << getFileName() << " failed to open." << endl;
}

vector <User> UsersFile::loadUsersFromFile() {

    User person;
    vector <User> users;
    string oneUserData = "";
    fstream file;
    file.open(getFileName().c_str(), ios::in);

    if (file.good()) {
        while (getline(file, oneUserData)) {
            person = downloadOneUserData(oneUserData);
            users.push_back(person);
        }
        file.close();
    }
    return users;
}

void UsersFile::overwriteUsersFile(vector <User> &users) {

    ofstream file;
    file.open(getFileName());

    file << users[0].getId() << "|";
    file << users[0].getLogin() << "|";
    file << users[0].getPassword() << "|";

    for (size_t i = 1; i < users.size(); i++) {

        file << endl;
        file << users[i].getId() << "|";
        file << users[i].getLogin() << "|";
        file << users[i].getPassword() << "|";
    }

    file.close();
}

string UsersFile::transformatingToFormat(User person) {

    string lineWithData = "";
    lineWithData += HelperMethods::conversionToString(person.getId()) + '|';
    lineWithData += person.getLogin() + '|';
    lineWithData += person.getPassword() + '|';

    return lineWithData;
}

User UsersFile::downloadOneUserData(string oneUserData) {

    User person;
    string singleData = "";
    int numberOfSingleData = 1;

    for (size_t position = 0; position < oneUserData.length(); position++) {
        if (oneUserData[position] != '|') singleData += oneUserData[position];
        else {
            switch (numberOfSingleData) {
            case 1:
                person.setId(atoi(singleData.c_str()));
                break;
            case 2:
                person.setLogin(singleData);
                break;
            case 3:
                person.setPassword(singleData);
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }
    return person;
}
