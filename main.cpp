#include <iostream>
#include "AddressBook.h"

using namespace std;

int main() {

    AddressBook addresBook("Users.txt");

    addresBook.showUsers();

    //addresBook.userRegistration();

    addresBook.logging();

    addresBook.showUsers();

    return 0;
}
