#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact {
    int userId;
    int contactId;
    string name;
    string lastName;
    string telNumber;
    string email;
    string address;

public:
    void setContactId(int newContactId);
    void setUserId(int newUserId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setTelNumber(string newTelNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int getContactId();
    int getUserId();
    string getName();
    string getLastName();
    string getTelNumber();
    string getEmail();
    string getAddress();
};

#endif // CONTACT_H
