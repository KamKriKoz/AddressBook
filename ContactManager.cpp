#include "ContactManager.h"

void ContactManager::addContact() {

    system("cls");
    cout << "ADDING NEW CONTACT" << endl << endl;

    Contact person = enterNewContactDetails();
    contacts.push_back(person);

    if (contactsFile.addToContactsFile(person)) cout << "Contact created." << endl;
    else cout << "Adding new contact failed. Check file of contacts." << endl;

    system ("pause");
}

void ContactManager::showAllContacts() {

    system("cls");
    if (!contacts.empty()) {

        for (Contact person : contacts) showContactData(person);

    } else cout << "Address book is empty." << endl;
    system("pause");
}

void ContactManager::searchByName() {

    system("cls");
    bool flag = true;

    if (contacts.empty()) {
        cout << "There are no contacts yet" << endl;
        system("pause");
        return;
    }

    cout << "Enter name: ";
    string name = HelperMethods::loadLine();
    cout << endl;

    for (Contact person : contacts) {
        if (person.getName() == name) {
            showContactData(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given name." << endl;

    system("pause");
}

Contact ContactManager::enterNewContactDetails() {

    system("cls");
    string name, lastName, telNumber, email, address;
    Contact person;
    person.setContactId(contactsFile.getLastContactId() + 1);
    person.setUserId(ID_LOGGED_USER);

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

void ContactManager::showContactData(Contact person) {

    cout << "Contact ID number: \t" << person.getContactId() << endl;
    cout << "Name: \t\t\t" << person.getName() << endl;
    cout << "Last name: \t\t" << person.getLastName() << endl;
    cout << "Telephone number: \t" << person.getTelNumber() << endl;
    cout << "Email: \t\t\t" << person.getEmail() << endl;
    cout << "Address: \t\t" << person.getAddress() << endl << endl;
}
