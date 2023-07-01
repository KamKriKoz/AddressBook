#include "UserManager.h"

void UserManager::userRegistration(){

    User person = enterNewUserDetails();
    users.push_back(person);
    usersFile.addToUsersFile(person);

    cout << "Account created" << endl;
    system ("pause");
    cout << endl;
}

User UserManager::enterNewUserDetails(){

    User person;
    person.setId(getNewUserId());
    string login, password;

    do {
        cout << "Enter your login: ";
        cin >> login;
        person.setLogin(login);
    } while (whetherThereIsLogin(person.getLogin()) == true);

    cout << "Enter your password: ";
    cin >> password;
    person.setPassword(password);

    return person;
}

int UserManager::getNewUserId() {

    if(users.empty() == true) return 1;
    else return users.back().getId()+ 1;
}

bool UserManager::whetherThereIsLogin(string login) {

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User exist";
            return true;
        }
    }

    return false;
}

void UserManager::showUsers() {

    for (int i = 0; i < users.size(); i++) {
            cout << users[i].getId() << endl;
            cout << users[i].getLogin() << endl;
            cout << users[i].getPassword() << endl;
    }
}

void UserManager::loadUsersFromFile() {

    users = usersFile.loadUsersFromFile();
}

void UserManager::logging() {

    User person;
    string login = "", password = "";
    idLoggedUser = 0;

    cout << endl << "Enter your login: ";
    cin >> login;

    for (User person : users) {
        if(person.getLogin() == login) {
            for (int trials = 3; trials > 0; trials--) {
                cout << "Enter your password, " << trials << " attempts left: ";
                cin >> password;

                if (person.getPassword() == password) {
                    cout << "Logged" << endl;
                    idLoggedUser = person.getId();
                    system ("pause");
                    return;
                }
            }
            cout << "3 times wrong password.";
            system("pause");
            return;
        }
    }
    cout << "Username doesn't exist." << endl;
    system("pause");
    return;
}

void UserManager::passwordChange() {

    string newPassword = "";

    cout << "Enter new password: ";
    cin >> newPassword;

    for (size_t i = 0; i < users.size(); i++) {
        if(users[i].getId() == idLoggedUser) {
            users[i].setPassword(newPassword);
            usersFile.overwriteUsersFile(users);
            cout << "Password changed.";
            system("pause");
        }
    }
}
