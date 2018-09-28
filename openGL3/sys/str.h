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

    vector<int> getDividers(string line, char chr){
        vector<int> dividers;
        int pos = 0;

        while(pos != -1){
            pos = charPosAfter(line,chr,pos+1);

            if(pos != -1){
                dividers.push_back(pos);
            }
        }
        dividers.push_back(line.length());
        return dividers;
    }

public:
    Str(){}

    char * strToChar(string str){
        char * chr = new char[str.length() + 1];
        strcpy(chr, str.c_str());
        return chr;
    }

    int charPos(string line,char chr){
        return static_cast<int>(line.find(chr));
    }

    int charPosAfter(string line,char chr,int num){
        return static_cast<int>(line.find(chr,num));
    }

    vector<string> devide(string line,char chr){
        vector<string> strings;
        vector<int> dividers = getDividers(line,chr);

        int first = 0;
        for( int d:dividers){
            string str = line.substr(first,d);
            first = d;
            strings.push_back(str);
        }

        return strings;
    }





    //Знайти всі пробіли в рядкові


};

#endif // STR_H
