#include "TextFile.h"

string TextFile::getFileName() {

    return FILE_NAME;
}

bool TextFile::whetherFileIsEmpty() {

    fstream file;
    file.open(getFileName().c_str(), ios::app);
    file.seekg(0, ios::end);

    if(file.tellg() == 0) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}
