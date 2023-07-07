#include "ContactManager.h"

void ContactManager::addContact(){

    Contact person = enterNewContactDetails();
    contacts.push_back(person);
    contactsFile.addToContactsFile(person);

    cout << "Contact created" << endl;
    system ("pause");
    cout << endl;
}

Contact ContactManager::enterNewContactDetails() {

    system("cls");
    string name, lastName, telNumber, email, address;
    Contact person;
    person.setContactId(contactsFile.getLastContactId() + 1);
    person.setUserId(idLoggedUser);

    cout << "Enter name: ";
    name = HelperMethods::loadLine();
    person.setName(name);

    cout << "Enter last name: ";
    lastName = HelperMethods::loadLine();
    person.setLastName(lastName);

    cout << "Enter telephone number: ";
    telNumber = HelperMethods::loadLine();
    person.setTelNumber(telNumber);

    cout << "Enter email: ";
    email = HelperMethods::loadLine();
    person.setEmail(email);

    cout << "Enter address: ";
    address = HelperMethods::loadLine();
    person.setAddress(address);

    return person;
}

void ContactManager::setIdLoggedUser(int loggedUser) {

    idLoggedUser = loggedUser;
}

void ContactManager::showContacts() {

    system("cls");
    if (!contacts.empty()) {

        for (Contact person : contacts) showContactData(person);

    } else cout << "Address book is empty." << endl;
    system("pause");
}

void ContactManager::showContactData(Contact person) {

    cout << "ID number: \t\t" << person.getContactId() << endl;
    cout << "Name: \t\t\t" << person.getName() << endl;
    cout << "Last name: \t\t" << person.getLastName() << endl;
    cout << "Telephone number: \t" << person.getTelNumber() << endl;
    cout << "Email: \t\t\t" << person.getEmail() << endl;
    cout << "Address: \t\t" << person.getAddress() << endl << endl;
}

void ContactManager::clearContacts() {

    contacts.clear();
}

void ContactManager::loadContactsFromFile() {

    contacts = contactsFile.loadContactsFromFile(idLoggedUser);
}

int ContactManager::getIdLoggedUser() {

    return idLoggedUser;
}
