#include "AddressBook.h"

void AddressBook::userRegistration() {

    userManager.userRegistration();
}

void AddressBook::showUsers() {

    userManager.showUsers();
}

void AddressBook::logging() {

    userManager.logging();

    while (userManager.getidLoggedUser() != 0) {

        system("cls");
        cout << "1. Add contact." << endl;
        cout << "2. Search by name./FUTURE/" << endl;
        cout << "3. Search by last name./FUTURE/" << endl;
        cout << "4. Show saved contacts." << endl;
        cout << "5. Delete contact./FUTURE/" << endl;
        cout << "6. Edit contact./FUTURE/" << endl;
        cout << "7. Change password" << endl;
        cout << "8. Log out" << endl;

        char choose;
        choose = getch();

        switch (choose) {

        case '1':
            contactManager.addContact();
            break;

        case '4':
            contactManager.showContacts();
            break;

        case '7':
            userManager.passwordChange();
            break;

        case '8':
            userManager.loggingOut();
            contactManager.clearContacts();
            break;
        }
    }
}
