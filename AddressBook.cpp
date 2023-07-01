#include "AddressBook.h"

void AddressBook::userRegistration() {

    userManager.userRegistration();
}

void AddressBook::showUsers() {

    userManager.showUsers();
}

void AddressBook::logging() {

    userManager.logging();
    userManager.passwordChange();
    userManager.loggingOut();
}