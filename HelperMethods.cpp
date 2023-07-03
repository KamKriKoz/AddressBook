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
