#include "UserManager.h"

int UserManager::getIdLoggedUser() {

    return idLoggedUser;
}

void UserManager::userRegistration() {

    system ("cls");
    User person = enterNewUserDetails();
    users.push_back(person);
    usersFile.addToUsersFile(person);

    cout << "Account created" << endl;
    system ("pause");
    cout << endl;
}

void UserManager::showUsers() {

    if (users.empty()) {
        cout << endl << "There are no users yet." << endl;
        system("pause");
        return;
    }

    for (size_t i = 0; i < users.size(); i++) showSingleUser(i);

    cout << endl;
    system("pause");
}

void UserManager::logging() {

    string login = "", password = "";

    cout << endl << "Enter your login: ";
    login = HelperMethods::loadLine();

    for (User person : users) {
        if(person.getLogin() == login) {
            for (int trials = 3; trials > 0; trials--) {
                cout << "Enter your password, " << trials << " attempts left: ";
                password = HelperMethods::loadLine();

                if (person.getPassword() == password) {
                    cout << "Logged." << endl;
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
}

void UserManager::passwordChange() {

    string newPassword = "";
    system("cls");

    cout << "Enter new password: ";
    newPassword = HelperMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == idLoggedUser) {
            itr -> setPassword(newPassword);
            cout << "Password changed." << endl;
            system("pause");
        }
    }
    usersFile.overwriteUsersFile(users);
}

void UserManager::loggingOut() {

    idLoggedUser = 0;
}

bool UserManager::whetherUserIsLogged() {

    if (idLoggedUser > 0) return true;
    else return false;
}

void UserManager::showSingleUser(size_t i) {

    cout << endl;
    cout << "User ID number: \t" << users[i].getId() << endl;
    cout << "User login: \t\t" << users[i].getLogin() << endl;
    //cout << "User password: \t\t" << users[i].getPassword() << endl;
}

User UserManager::enterNewUserDetails() {

    User person;
    person.setId(getNewUserId());
    string login, password;

    do {
        cout << "Enter your login: ";
        login = HelperMethods::loadLine();
        person.setLogin(login);
    } while (whetherThereIsLogin(person.getLogin()));

    cout << "Enter your password: ";
    password = HelperMethods::loadLine();
    person.setPassword(password);

    return person;
}

int UserManager::getNewUserId() {

    if (users.empty()) return 1;
    else return users.back().getId()+ 1;
}

bool UserManager::whetherThereIsLogin(string login) {

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << "User exist. Try again." << endl;
            return true;
        }
    }

    return false;
}
