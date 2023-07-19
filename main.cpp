#include <iostream>
#include <conio.h>
#include "AddressBook.h"

using namespace std;

int main() {

    AddressBook addresBook("Users.txt", "Contacts.txt");
    char choose;

    while(1) {

        if (!addresBook.whetherUserIsLogged()) {

            system("cls");
            addresBook.loginMenu();
            choose = getch();

            switch (choose) {

            case '1':
                addresBook.userRegistration();
                break;

            case '2':
                addresBook.logging();
                break;

            case'3':
                addresBook.showUsers();
                break;

            case '9':
                exit(0);

            default:
                cout << endl << "Option does not exist." << endl << endl;
                system("pause");
                break;
            }

        } else {

            system("cls");
            addresBook.userMenu();
            choose = getch();

            switch (choose) {

            case '1':
                addresBook.addContact();
                break;

            case '2':
                addresBook.searchByName();
                break;

            case '3':
                addresBook.searchByLastName();
                break;

            case '4':
                addresBook.showAllContacts();
                break;

            case '5':
                addresBook.deleteContact();
                break;

            case '6':
                addresBook.editContact();
                break;

            case '7':
                addresBook.passwordChange();
                break;

            case '8':
                addresBook.loggingOut();
                break;

            default:
                cout << endl << "Option does not exist." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}
