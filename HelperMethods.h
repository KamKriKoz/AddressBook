#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class HelperMethods {

public:
    static string conversionToString(int number);
    static bool whetherFileIsEmpty(fstream &file);
};

#endif // HELPERMETHODS_H
