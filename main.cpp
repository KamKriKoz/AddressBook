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

    int contactId;
    string name, lastName, telNumber, email, address;
};

void readUsersFromFile(vector <User> &users) {

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

void addToUsersFile(const User &person) {

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

string loadLine() {

    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

void registration(vector <User> &users) {

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

int logging(vector <User> users) {

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

void passwordChange(vector<User> &users, int userId) {

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

void addToContactsFile(const Contact &person, const User &user) {

    fstream file;
    file.open("Contacts.txt", ios::out | ios::app);

    file << user.userId << "|";
    file << person.contactId << "|";
    file << person.name << "|";
    file << person.lastName << "|";
    file << person.telNumber << "|";
    file << person.email << "|";
    file << person.address << "|" << endl;

    file.close();
}

vector <Contact> readAllContactsFromFile() {

    vector <Contact> contacts;
    Contact person;
    string line, field;

    fstream file;
    file.open("Contacts.txt", ios::in);

    if (file.good() == false) {
        file.open("Contacts.txt", ios::out);
        cout << "File of contacts has been created." << endl;
        Sleep(2000);
    }

    while (getline(file, line)) {

        istringstream iss(line);

        getline(iss, field, '|');
        getline(iss, field, '|');
        person.contactId = stoi(field);

        getline(iss, person.name, '|');
        getline(iss, person.lastName, '|');
        getline(iss, person.telNumber, '|');
        getline(iss, person.email, '|');
        getline(iss, person.address, '|');

        contacts.push_back(person);
    }

    file.close();

    return contacts;
}

vector <Contact> readContactsByUser(const User &user) {

    vector <Contact> userContacts;
    Contact person;
    User userToCheck;
    string line, field;

    fstream file;
    file.open("Contacts.txt", ios::in);

    while (getline(file, line)) {

        istringstream iss(line);

        getline(iss, field, '|');
        userToCheck.userId = stoi(field);

        if (user.userId == userToCheck.userId) {

            getline(iss, field, '|');
            person.contactId = stoi(field);

            getline(iss, person.name, '|');
            getline(iss, person.lastName, '|');
            getline(iss, person.telNumber, '|');
            getline(iss, person.email, '|');
            getline(iss, person.address, '|');

            userContacts.push_back(person);
        }
    }
    file.close();

    return userContacts;
}

void showSelected(const Contact &person) {

    cout << "ID number: \t\t" << person.contactId << endl;
    cout << "Name: \t\t\t" << person.name << endl;
    cout << "Last name: \t\t" << person.lastName << endl;
    cout << "Telephone number: \t" << person.telNumber << endl;
    cout << "Email: \t\t\t" << person.email << endl;
    cout << "Address: \t\t" << person.address << endl << endl;
}

void addContact(const User &user) {

    vector <Contact> allContacts;
    vector <Contact> userContacts;
    system("cls");

    allContacts = readAllContactsFromFile();
    userContacts = readContactsByUser(user);

    system("cls");
    Contact person;

    if (allContacts.empty()) person.contactId = 1;
    else person.contactId = allContacts.back().contactId + 1;

    cout << "Enter name: " ;
    person.name = loadLine();

    cout << "Enter last name: ";
    person.lastName = loadLine();

    cout << "Enter telephone number: ";
    person.telNumber = loadLine();

    cout << "Enter email: ";
    person.email = loadLine();

    cout << "Enter adaress: ";
    person.address = loadLine();

    userContacts.push_back(person);
    addToContactsFile(person, user);

    cout << "New contact created." << endl;
    Sleep(1500);
}

void searchByName(const User &user) {

    system("cls");
    vector <Contact> contacts;
    bool flag = true;

    contacts = readContactsByUser(user);

    if (contacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter name: ";
    string name = loadLine();
    cout << endl;

    for (Contact person : contacts) {
        if (person.name == name) {
            showSelected(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given name." << endl;

    system("pause");
}

void searchByLastName(const User &user) {

    system("cls");
    vector <Contact> contacts;
    bool flag = true;

    contacts = readContactsByUser(user);

    if (contacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter last name: ";
    string lastName = loadLine();
    cout << endl;

    for (Contact person : contacts) {
        if (person.lastName == lastName) {
            showSelected(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given name." << endl;

    system("pause");
}

void showSavedContacts(const User &user) {

    system("cls");
    vector <Contact> contacts;

    contacts = readContactsByUser(user);

    if (contacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    for (Contact person : contacts) showSelected(person);

    system("pause");
}

void deleteContact(const User &user) {

    system("cls");

    vector <string> temporaryVector;
    vector <Contact> allContacts;
    vector <Contact> userContacts;
    string line, toDelete;
    bool flag = false;
    int contactId;
    char choose;

    userContacts = readContactsByUser(user);
    allContacts = readAllContactsFromFile();

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter contact id: ";
    cin >> contactId;

    for (Contact person : userContacts)
        if (person.contactId == contactId) flag = true;

    if (flag) {

        for (size_t i = 0; i < allContacts.size(); i++) {

            if (allContacts[i].contactId == contactId) {

                fstream file;
                file.open("Contacts.txt", ios::in);
                while (getline(file, line)) temporaryVector.push_back(line);
                file.close();

                toDelete = temporaryVector[i];

                cout << "Press t, to confirm deletion or any other button to reject." << endl;
                choose = getch();

                if (choose == 't') {

                    fstream file;
                    file.open("Contacts.txt", ios::in);

                    fstream file2;
                    file2.open("temporaryContacts.txt", ios::out | ios::app);

                    while (getline(file, line)) {
                        if (line == toDelete) continue;
                        file2 << line << endl;
                    }

                    file.close();
                    file2.close();

                    remove("Contacts.txt");
                    rename("temporaryContacts.txt", "Contacts.txt");

                    cout << "Contact has been deleted.";
                    Sleep(1500);
                    return;
                }

                else {
                    cout << "Deletion cancelled.";
                    Sleep(1500);
                    return;
                }
            }
        }
    }

    if (!flag) cout << "There is no contact for the given id number." << endl;

    Sleep(1500);
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

void rewritingEdited(const Contact &person, const User &user, string toEdit) {

    string line;
    fstream file;
    file.open("Contacts.txt", ios::in);

    fstream file2;
    file2.open("temporaryContacts.txt", ios::out | ios::app);

    while (getline(file, line)) {
        if (line == toEdit) {

            file2 << user.userId << "|";
            file2 << person.contactId << "|";
            file2 << person.name << "|";
            file2 << person.lastName << "|";
            file2 << person.telNumber << "|";
            file2 << person.email << "|";
            file2 << person.address << "|" << endl;

            continue;
        }

        file2 << line << endl;
    }

    file.close();
    file2.close();

    remove("Contacts.txt");
    rename("temporaryContacts.txt", "Contacts.txt");
}

void editContact(const User &user) {

    system("cls");

    vector <string> temporaryVector;
    vector <Contact> allContacts;
    vector <Contact> userContacts;
    Contact person;
    string line, toEdit;
    bool flag = false;
    int contactId;
    char choose;

    allContacts = readAllContactsFromFile();
    userContacts = readContactsByUser(user);

    if (userContacts.empty()) {
        cout << "There are no contacts yet" << endl;
        Sleep (1500);
        return;
    }

    cout << "Enter contact id: ";
    cin >> contactId;

    for (Contact person : userContacts)
        if (person.contactId == contactId) flag = true;

    if (flag) {

        for (size_t i = 0; i < allContacts.size(); i++) {

            if (allContacts[i].contactId == contactId) {

                system("cls");
                editMenu();

                fstream file;
                file.open("Contacts.txt", ios::in);
                while (getline(file, line)) temporaryVector.push_back(line);
                file.close();

                toEdit = temporaryVector[i];
                person = allContacts[i];
                choose = getch();

                switch(choose) {

                case '1':

                    system("cls");
                    cout << "Write new name: ";
                    person.name = loadLine();
                    rewritingEdited(person, user, toEdit);
                    cout << "The contact has been changed";
                    Sleep(1500);
                    break;

                case '2':

                    system("cls");
                    cout << "Write new last name: ";
                    person.lastName = loadLine();
                    rewritingEdited(person, user, toEdit);
                    cout << "The contact has been changed";
                    Sleep(1500);
                    break;

                case '3':

                    system("cls");
                    cout << "Write new telephone number: ";
                    person.telNumber = loadLine();
                    rewritingEdited(person, user, toEdit);
                    cout << "The contact has been changed";
                    Sleep(1500);
                    break;

                case '4':

                    system("cls");
                    cout << "Write new email: ";
                    person.email = loadLine();
                    rewritingEdited(person, user, toEdit);
                    cout << "The contact has been changed";
                    Sleep(1500);
                    break;

                case '5':

                    system("cls");
                    cout << "Write new address: ";
                    person.address = loadLine();
                    rewritingEdited(person, user, toEdit);
                    cout << "The contact has been changed";
                    Sleep(1500);
                    break;

                case '6':
                    return;
                }
            }
        }
    }

    if (!flag) cout << "There is no contact for the given id number." << endl;

    Sleep(1500);
}

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

int main() {

    vector <User> users;
    char choose;
    User user;

    readUsersFromFile(users);
    int idLogUser = 0;

    while(1) {

        if (idLogUser == 0) {

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
                } else idLogUser = logging(users);
                break;

            case '9':
                exit(0);
            }

        } else {

            system("cls");
            userMenu();

            for (vector <User> :: iterator itr = users.begin(); itr != users.end(); itr++) {
                user = *itr;
                if (user.userId == idLogUser) break;
            }

            choose = getch();

            switch(choose) {

            case '1':
                addContact(user);
                break;

            case '2':
                searchByName(user);
                break;

            case '3':
                searchByLastName(user);
                break;

            case '4':
                showSavedContacts(user);
                break;

            case '5':
                deleteContact(user);
                break;

            case '6':
                editContact(user);
                break;

            case '7':
                passwordChange(users, idLogUser);
                break;

            case '8':
                idLogUser = 0;
            }
        }
    }

    return 0;
}
