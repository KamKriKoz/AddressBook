#include "HelperMethods.h"

string HelperMethods::conversionToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
