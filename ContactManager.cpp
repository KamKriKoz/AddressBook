#include "ContactManager.h"

void ContactManager::addContact(){

    Contact person = enterNewContactDetails();
    contacts.push_back(person);
    //contactsFile.addToContactsFile(person);

    cout << "Contact created" << endl;
    system ("pause");
    cout << endl;
}

Contact ContactManager::enterNewContactDetails() {

    string name, lastName, telNumber, email, address;
    Contact person;
    person.setContactId(getNewContactId());
    person.setUserId(idLoggedUser);

    cout << "Enter name: ";
    cin >> name;
    person.setName(name);

    cout << "Enter last name: ";
    cin >> lastName;
    person.setLastName(lastName);

    cout << "Enter telephone number: ";
    cin >> telNumber;
    person.setTelNumber(telNumber);

    cout << "Enter email: ";
    cin >> email;
    person.setEmail(email);

    cout << "Enter address: ";
    cin >> address;
    person.setAddress(address);

    return person;
}

int ContactManager::getNewContactId() {

    if(contacts.empty() == true) return 1;
    else return contacts.back().getContactId()+ 1;
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
