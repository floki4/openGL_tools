#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <regex>

using namespace std;

class Str
{
private:

public:
    Str(){}

    char * strToChar(string str){
        char * chr = new char[str.length() + 1];
        strcpy(chr, str.c_str());
        return chr;
    }
};

#endif // STR_H
