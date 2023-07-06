#include "Contact.h"

void Contact::setContactId(int newContactId) {
    if (newContactId >= 0) contactId = newContactId;
}

void Contact::setUserId(int newUserId) {
    if (newUserId >= 0) userId = newUserId;
}

void Contact::setName(string newName) {
    name = newName;
}

void Contact::setLastName(string newLastName) {
    lastName = newLastName;
}

void Contact::setTelNumber(string newTelNumber) {
    telNumber = newTelNumber;
}

void Contact::setEmail(string newEmail) {
    email = newEmail;
}

void Contact::setAddress(string newAddress) {
    address = newAddress;
}

int Contact::getUserId() {
    return userId;
}

int Contact::getContactId() {
    return contactId;
}

string Contact::getName() {
    return name;
}

string Contact::getLastName() {
    return lastName;
}

string Contact::getTelNumber() {
    return telNumber;
}

string Contact::getEmail() {
    return email;
}

string Contact::getAddress() {
    return address;
}
