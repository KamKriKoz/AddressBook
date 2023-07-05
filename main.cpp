#include <iostream>
#include <conio.h>
#include "AddressBook.h"

using namespace std;

//Menu

void loginMenu() {

    cout << "1. Registration" << endl;
    cout << "2. Logging in" << endl;
    cout << "3. Show users" << endl;
    cout << "9. End program" << endl;
}

int main() {

    AddressBook addresBook("Users.txt");
    char choose;

    while(1) {

        system("cls");
        loginMenu();
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
        }
    }

    return 0;
}
