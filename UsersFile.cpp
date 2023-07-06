#include "UsersFile.h"

UsersFile::UsersFile() {

    usersFileName = "Users.txt";
}

void UsersFile::addToUsersFile(User person) {

    string lineWithData;
    fstream file;
    file.open(usersFileName.c_str(), ios::app);

    if (file.good() == true) {
        lineWithData = transformatingToFormat(person);
        if (HelperMethods::whetherFileIsEmpty(file) == true) file << lineWithData;
        else file << endl << lineWithData;
        file.close();
    }
    else cout << "File " << usersFileName << " failed to open." << endl;
}

string UsersFile::transformatingToFormat(User person) {

    string lineWithData = "";
    lineWithData += HelperMethods::conversionToString(person.getId()) + '|';
    lineWithData += person.getLogin() + '|';
    lineWithData += person.getPassword() + '|';

    return lineWithData;
}

vector <User> UsersFile::loadUsersFromFile() {

    User person;
    vector <User> users;
    string oneUserData = "";
    fstream file;
    file.open(usersFileName.c_str(), ios::in);

    if (file.good() == true) {
        while (getline(file, oneUserData)) {
            person = downloadOneUserData(oneUserData);
            users.push_back(person);
        }
        file.close();
    }
    return users;
}

User UsersFile::downloadOneUserData(string oneUserData) {

    User person;
    string singleData = "";
    int numberOfSingleData = 1;

    for (int position = 0; position < oneUserData.length(); position++) {
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

void UsersFile::overwriteUsersFile(vector <User> &users) {

    ofstream file;
    file.open(usersFileName);

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
