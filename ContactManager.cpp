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

void ContactManager::searchByLastName() {

    system("cls");
    bool flag = true;

    if (contacts.empty()) {
        cout << "There are no contacts yet" << endl;
        system("pause");
        return;
    }

    cout << "Enter last name: ";
    string lastName = HelperMethods::loadLine();
    cout << endl;

    for (Contact person : contacts) {
        if (person.getLastName() == lastName) {
            showContactData(person);
            flag = false;
        }
    }

    if (flag)
        cout << "There is no contact for the given last name." << endl;

    system("pause");
}

void ContactManager::deleteContact() {

    system("cls");
    Contact person;
    int contactIdToDelete = 0;
    char choose;

    if (contacts.empty()) {
        cout << "There are no contacts yet." << endl;
        system ("pause");
        return;
    }

    cout << "Enter contact id: ";
    contactIdToDelete = HelperMethods::loadInteger();

    for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++) {

        person = *itr;
        if (person.getContactId() == contactIdToDelete) {

            cout << "Press t, to confirm deletion or any other button to reject." << endl;
            choose = getch();

            switch (choose) {

            case 't':
                contacts.erase(itr);
                contactsFile.modifyContactsFileAfterDelete(contactIdToDelete);
                cout << "Contact has been deleted." << endl;
                system("pause");
                return;

            default:
                cout << "Deletion cancelled." << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "There is no contact for the given id number." << endl;
    system("pause");
}

void ContactManager::editContact() {

    system("cls");
    Contact person;
    int contactIdToEdit = 0;
    char choose;

    if (contacts.empty()) {
        cout << "There are no contacts yet." << endl;
        system("pause");
        return;
    }

    cout << "Enter contact id: ";
    contactIdToEdit = HelperMethods::loadInteger();

    for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++) {

        person = *itr;
        if (person.getContactId() == contactIdToEdit) {

            system("cls");
            editMenu();
            choose = getch();

            switch(choose) {

            case '1':
                system("cls");
                cout << "Write new name: ";
                itr -> setName(HelperMethods::loadLine());
                contactsFile.modifyContactsFileAfterEdit(*itr);
                cout << "The contact has been changed." << endl;
                system("pause");
                return;

            case '2':
                system("cls");
                cout << "Write new last name: ";
                itr -> setLastName(HelperMethods::loadLine());
                contactsFile.modifyContactsFileAfterEdit(*itr);
                cout << "The contact has been changed." << endl;
                system("pause");
                return;

            case '3':
                system("cls");
                cout << "Write new telephone number: ";
                itr -> setTelNumber(HelperMethods::loadLine());
                contactsFile.modifyContactsFileAfterEdit(*itr);
                cout << "The contact has been changed." << endl;
                system("pause");
                return;

            case '4':
                system("cls");
                cout << "Write new email: ";
                itr -> setEmail(HelperMethods::loadLine());
                contactsFile.modifyContactsFileAfterEdit(*itr);
                cout << "The contact has been changed." << endl;
                system("pause");
                return;

            case '5':
                system("cls");
                cout << "Write new address: ";
                itr -> setAddress(HelperMethods::loadLine());
                contactsFile.modifyContactsFileAfterEdit(*itr);
                cout << "The contact has been changed." << endl;
                system("pause");
                return;

            case '6':
                return;

            default:
                cout << endl << "Option does not exist. Returned to the user menu." << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "There is no contact for the given id number." << endl;
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

void ContactManager::editMenu() {

    cout << "Select data to edit." << endl;
    cout << "1. Name." << endl;
    cout << "2. Last name." << endl;
    cout << "3. Telephone number." << endl;
    cout << "4. Email." << endl;
    cout << "5. Address." << endl;
    cout << "6. Return to user menu." << endl;
}
