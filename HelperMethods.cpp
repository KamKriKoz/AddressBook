#include "HelperMethods.h"

string HelperMethods::conversionToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool HelperMethods::whetherFileIsEmpty(fstream &file) {

    file.seekg(0, ios::end);
    if(file.tellg() == 0) return true;
    else return false;
}

int HelperMethods::conversionToInt(string number) {

    int numInt;
    istringstream iss(number);
    iss >> numInt;
    return numInt;
}

string HelperMethods::getNumber(string text, int position) {
    string number = "";
    while(isdigit(text[position]) == true)
    {
        number += text[position];
        position ++;
    }
    return number;
}
