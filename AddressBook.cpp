#include "AddressBook.h"

void AddressBook::userRegistration() {

    userManager.userRegistration();
}

void AddressBook::showUsers() {

    userManager.showUsers();
}

void AddressBook::logging() {

    userManager.logging();
    if (userManager.whetherUserIsLogged()) {
        contactManager = new ContactManager(CONTACTS_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void AddressBook::passwordChange() {

    userManager.passwordChange();
}

void AddressBook::loggingOut() {

    userManager.loggingOut();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::addContact() {

    if (userManager.whetherUserIsLogged()) contactManager -> addContact();
    else {
        cout << "You must be logged in to add a contact." << endl;
        system("pause");
    }
}

void AddressBook::showAllContacts() {

    if (userManager.whetherUserIsLogged()) contactManager -> showAllContacts();
    else {
        cout << "You must be logged in to show contacts." << endl;
        system("pause");
    }
}

void AddressBook::searchByName() {

    if (userManager.whetherUserIsLogged()) contactManager -> searchByName();
    else {
        cout << "You must be logged in to search contact by name." << endl;
        system("pause");
    }
}

void AddressBook::searchByLastName() {

    if (userManager.whetherUserIsLogged()) contactManager -> searchByLastName();
    else {
        cout << "You must be logged in to search contact by last name." << endl;
        system("pause");
    }
}

void AddressBook::deleteContact() {

    if (userManager.whetherUserIsLogged()) contactManager -> deleteContact();
    else {
        cout << "You must be logged in to delete contact." << endl;
        system("pause");
    }
}

void AddressBook::editContact() {

    if (userManager.whetherUserIsLogged()) contactManager -> editContact();
    else {
        cout << "You must be logged in to edit contact." << endl;
        system("pause");
    }
}

void AddressBook::loginMenu() {

    cout << "1. Registration." << endl;
    cout << "2. Logging in." << endl;
    cout << "3. Show users." << endl;
    cout << "9. End program." << endl;
}

void AddressBook::userMenu() {

    cout << "1. Add contact." << endl;
    cout << "2. Search by name." << endl;
    cout << "3. Search by last name." << endl;
    cout << "4. Show saved contacts." << endl;
    cout << "5. Delete contact." << endl;
    cout << "6. Edit contact." << endl;
    cout << "7. Change password." << endl;
    cout << "8. Log out." << endl;
}

bool AddressBook::whetherUserIsLogged(){

    return userManager.whetherUserIsLogged();
}
