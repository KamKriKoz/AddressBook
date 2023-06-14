#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

struct User {

    int userId;
    string username, password;
};

struct Contact {

    int userId, contactId;
    string name, lastName, telNumber, email, address;
};

string loadLine() {

    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

//Menu

void loginMenu() {

    cout << "1. Registration" << endl;
    cout << "2. Logging in" << endl;
    cout << "9. End program" << endl;
}

void userMenu() {

    cout << "1. Add contact." << endl;
    cout << "2. Search by name." << endl;
    cout << "3. Search by last name." << endl;
    cout << "4. Show saved contacts." << endl;
    cout << "5. Delete contact." << endl;
    cout << "6. Edit contact." << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
}

void editMenu() {

    cout << "Select data to edit." << endl;
    cout << "1. Name." << endl;
    cout << "2. Last name." << endl;
    cout << "3. Telephone number." << endl;
    cout << "4. Email." << endl;
    cout << "5. Address." << endl;
    cout << "6. Return to user menu." << endl;
}

//Users

void readUsersFromFile (vector <User> &users) {

    User person;
    string line, field;

    fstream file;
    file.open("Users.txt", ios::in);

    if (file.good() == false) {
        file.open("Users.txt", ios::out);
        cout << "File of users has been created." << endl;
        Sleep(2000);
    }

    while (getline(file, line)) {

        istringstream iss(line);

        getline(iss, field, '|');
        person.userId = stoi(field);

        getline(iss, person.username, '|');
        getline(iss, person.password, '|');

        users.push_back(person);
    }

    file.close();
}

void addToUsersFile (const User &person) {

    fstream file;
    file.open("Users.txt", ios::out | ios::app);

    file << person.userId << "|";
    file << person.username << "|";
    file << person.password << "|" << endl;

    file.close();
}

void overwriteUsersFile (vector <User> users) {

    ofstream file;
    file.open("Users.txt");

    for (size_t i = 0; i < users.size(); i++) {

        file << users[i].userId << "|";
        file << users[i].username << "|";
        file << users[i].password << "|" << endl;
    }

    file.close();
}

void registration (vector <User> &users) {

    system("cls");
    User person;
    string username;

    cout << "Enter your username: ";
    username = loadLine();

    for (User person : users) {
        if (person.username == username) {
            system("cls");
            cout << "User exist. Enter another username: ";
            username = loadLine();
        }
    }

    person.username = username;
    cout << "Enter your password: ";
    person.password = loadLine();

    if (users.empty()) person.userId = 1;
    else person.userId = users.back().userId + 1;

    users.push_back(person);
    addToUsersFile(person);

    cout << "Account created";
    Sleep(1500);
}

int logging (vector <User> users) {

    system("cls");
    bool flag = true;
    string login, password;

    cout << "Enter your username: ";
    login = loadLine();

    for (User person : users) {
        if (person.username == login) {

            for (int j = 0; j < 3; j++) {
                cout << "Enter your password, " << 3 - j << " attempts left: ";
                password = loadLine();

                if (person.password == password) {
                    cout << "Logged" << endl;
                    flag = false;
                    Sleep(1500);
                    return person.userId;
                }
            }
            cout << "3 times wrong password. Wait 5 seconds for another try.";
            Sleep(5000);
            return 0;
        }
    }
    if (flag) {
        cout << "Username doesn't exist." << endl;
        Sleep(1500);
    }

    return 0;
}

void passwordChange (vector <User> &users, int userId) {

    system("cls");
    string password;

    cout << "Enter new password: ";
    password = loadLine();

    for (size_t i = 0; i < users.size(); i++) {
        if(users[i].userId == userId) {
            users[i].password = password;
            overwriteUsersFile(users);
            cout << "Password changed.";
            Sleep(1500);
        }
    }
}

//Contacts

void pasteContactToFile (ofstream &file, const Contact &person) {

    file << person.userId << "|";
    file << person.contactId << "|";
    file << person.name << "|";
    file << person.lastName << "|";
    file << person.telNumber << "|";
    file << person.email << "|";
    file << person.address << "|" << endl;
}

void addToContactsFile (const Contact &person) {

    ofstream file ("Contacts.txt", ios::app);

    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }

    pasteContactToFile(file, person);

    file.close();
}

int readContactsFromFile (vector <Contact> &userContacts, int idLoggedUser) {

    int lastContactId;
    string fileName = "Contacts.txt";
    Contact person;
    string line, field;

    fstream file;
    file.open(fileName, ios::in);

    if (!file.good()) {
        file.open(fileName, ios::out);
        file.close();
        cout << "File of contacts has been created." << endl;
        Sleep(2000);
        return 0;
    }

    while (getline(file, line)) {

        istringstream iss(line);

        getline(iss, field, '|');
        person.userId = stoi(field);

        getline(iss, field, '|');
        person.contactId = stoi(field);
        lastContactId = person.contactId;

        if (person.userId == idLoggedUser) {
            getline(iss, person.name, '|');
            getline(iss, person.lastName, '|');
            getline(iss, person.telNumber, '|');
            getline(iss, person.email, '|');
            getline(iss, person.address, '|');

            userContacts.push_back(person);
        }
    }

    file.close();

    return lastContactId;
}

void showSelected (const Contact &person) {

    cout << "ID number: \t\t" << person.contactId << endl;
    cout << "Name: \t\t\t" << person.name << endl;
    cout << "Last name: \t\t" << person.lastName << endl;
    cout << "Telephone number: \t" << person.telNumber << endl;
    cout << "Email: \t\t\t" << person.email << endl;
    cout << "Address: \t\t" << person.address << endl << endl;
}

int addContact (vector <Contact> &userContacts, int lastContactId, const int idLoggedUser) {

    system("cls");
    Contact person;

    person.contactId = ++lastContactId;
    person.userId = idLoggedUser;

    cout << "Enter name: " ;
    person.name = loadLine();

    cout << "Enter last name: ";
    person.lastName = loadLine();

    cout << "Enter telephone number: ";
    person.telNumber = loadLine();

    cout << "Enter email: ";
    person.email = loadLine();

    cout << "Enter address: ";
    person.address = loadLine();

    userContacts.push_back(person);
    addToContactsFile(person);

    cout << "New contact created." << endl;
    Sleep(1500);

    return lastContactId;
}

void searchByName (vector <Contact> userContacts) {

    system("cls");
    bool flag = true;

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter name: ";
    string name = loadLine();
    cout << endl;

    for (Contact person : userContacts) {
        if (person.name == name) {
            showSelected(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given name." << endl;

    system("pause");
}

void searchByLastName (vector <Contact> userContacts) {

    system("cls");
    bool flag = true;

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter last name: ";
    string lastName = loadLine();
    cout << endl;

    for (Contact person : userContacts) {
        if (person.lastName == lastName) {
            showSelected(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given name." << endl;

    system("pause");
}

void showSavedContacts (vector <Contact> userContacts) {

    system("cls");

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    for (Contact person : userContacts) showSelected(person);

    system("pause");
}

void fileSwapAndDelete (string oldFileName, string temporaryFileName) {

    if (std::remove(oldFileName.c_str()) != 0) perror("Error removing file");
    if (rename(temporaryFileName.c_str(), oldFileName.c_str()) != 0) perror("Error renaming file");
}

int modifyContactsFileAfterDelete(const int contactIdToDelete) {

    int lastContactId;
    string line, field, oldFileName = "Contacts.txt", temporaryFileName = "temporaryContacts.txt";
    ifstream file(oldFileName, ios::in);
    ofstream temporaryfile(temporaryFileName, ios::out);

    while (getline(file, line)) {

        istringstream iss(line);
        getline(iss, field, '|');
        getline(iss, field, '|');

        if (stoi(field) != contactIdToDelete) {
            temporaryfile << line << endl;
            lastContactId = stoi(field);
        }
    }

    file.close();
    temporaryfile.close();

    fileSwapAndDelete(oldFileName, temporaryFileName);

    return lastContactId;
}

int deleteContact (vector <Contact> &userContacts, int lastContactId) {

    system("cls");
    Contact person;
    int contactIdToDelete;
    char choose;

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return lastContactId;
    }

    cout << "Enter contact id: ";
    cin >> contactIdToDelete;

    for (vector <Contact> :: iterator itr = userContacts.begin(); itr != userContacts.end(); itr++) {

        person = *itr;
        if (person.contactId == contactIdToDelete) {

            cout << "Press t, to confirm deletion or any other button to reject." << endl;
            choose = getch();

            switch (choose) {

            case 't':
                userContacts.erase(itr);
                lastContactId = modifyContactsFileAfterDelete(contactIdToDelete);
                cout << "Contact has been deleted." << endl;
                system("pause");
                return lastContactId;

            default:
                cout << "Deletion cancelled." << endl;
                system("pause");
                return lastContactId;
            }
        }
    }

    cout << "There is no contact for the given id number." << endl;

    Sleep(1500);

    return lastContactId;
}

void modifyContactsFileAfterEdit(const Contact &person) {

    string line, field, oldFileName = "Contacts.txt", temporaryFileName = "temporaryContacts.txt";
    ifstream file(oldFileName, ios::in);
    ofstream temporaryfile(temporaryFileName, ios::out);

    while (getline(file, line)) {

        istringstream iss(line);
        getline(iss, field, '|');
        getline(iss, field, '|');

        if(stoi(field) != person.contactId) temporaryfile << line << endl;
        else pasteContactToFile(temporaryfile, person);
    }

    file.close();
    temporaryfile.close();

    fileSwapAndDelete(oldFileName, temporaryFileName);
}

void editContact (vector <Contact> &userContacts) {

    system("cls");
    int contactId;
    char choose;

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter contact id: ";
    cin >> contactId;

    for (size_t i = 0; i < userContacts.size(); i++) {

        if (userContacts[i].contactId == contactId) {

            system("cls");
            editMenu();
            choose = getch();

            switch(choose) {

            case '1':
                system("cls");
                cout << "Write new name: ";
                userContacts[i].name = loadLine();
                modifyContactsFileAfterEdit(userContacts[i]);
                cout << "The contact has been changed";
                Sleep(1500);
                return;

            case '2':
                system("cls");
                cout << "Write new last name: ";
                userContacts[i].lastName = loadLine();
                modifyContactsFileAfterEdit(userContacts[i]);
                cout << "The contact has been changed";
                Sleep(1500);
                return;

            case '3':
                system("cls");
                cout << "Write new telephone number: ";
                userContacts[i].telNumber = loadLine();
                modifyContactsFileAfterEdit(userContacts[i]);
                cout << "The contact has been changed";
                Sleep(1500);
                return;

            case '4':
                system("cls");
                cout << "Write new email: ";
                userContacts[i].email = loadLine();
                modifyContactsFileAfterEdit(userContacts[i]);
                cout << "The contact has been changed";
                Sleep(1500);
                return;

            case '5':
                system("cls");
                cout << "Write new address: ";
                userContacts[i].address = loadLine();
                modifyContactsFileAfterEdit(userContacts[i]);
                cout << "The contact has been changed";
                Sleep(1500);
                return;

            case '6':
                return;
            }
        }
    }

    cout << "There is no contact for the given id number." << endl;

    Sleep(1500);
}

int main() {

    vector <User> users;
    vector <Contact> userContacts;
    char choose;
    int lastContactId = 0;

    readUsersFromFile(users);
    int idLoggedUser = 0;

    while(1) {

        if (idLoggedUser == 0) {

            system("cls");
            loginMenu();
            choose = getch();

            switch(choose) {

            case '1':
                registration(users);
                break;

            case '2':
                if (users.empty()) {
                    cout << "There is no user yet";
                    Sleep(1500);
                } else {
                    idLoggedUser = logging(users);
                    lastContactId = readContactsFromFile(userContacts, idLoggedUser);
                }
                break;

            case '9':
                exit(0);
            }

        } else {

            system("cls");
            userMenu();
            choose = getch();

            switch(choose) {

            case '1':
                lastContactId = addContact(userContacts, lastContactId, idLoggedUser);
                break;
            case '2':
                searchByName(userContacts);
                break;
            case '3':
                searchByLastName(userContacts);
                break;
            case '4':
                showSavedContacts(userContacts);
                break;
            case '5':
                lastContactId = deleteContact(userContacts, lastContactId);
                break;
            case '6':
                editContact(userContacts);
                break;
            case '7':
                passwordChange(users, idLoggedUser);
                break;
            case '8':
                idLoggedUser = 0;
            }
        }
    }

    return 0;
}
