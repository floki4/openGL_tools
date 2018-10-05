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

    vector<vec2> getDividers(string line, string chr){
        vector<vec2> dividers;
        vec2 dev;
        dev.x = 0;

        while(dev.x != -1){
            dev.x= charPosAfter(line,chr,dev.x+1);
            dev.y= dev.x+chr.length();

            //end line
            if(dev.x != -1){
                dividers.push_back(dev);
            }
        }

        dividers.push_back(vec2(line.length(),line.length()));
        return dividers;
    }

public:
    Str(){}

    char * toChar(string str){
        char * chr = new char[str.length() + 1];
        strcpy(chr, str.c_str());
        return chr;
    }

    string sub(int n,string line){
        return line.substr(n,line.length());
    }

    string sub(int n,int n2,string line){
        return line.substr(n,line.length()-n2);
    }

    int charPos(string line,string chr){
        return static_cast<int>(line.find(chr));
    }

    int charPosAfter(string line,string chr,int num){
        return static_cast<int>(line.find(chr,num));
    }

    vector<string> devide(string line,string chr){
        vector<string> strings;
        vector<vec2> dividers = getDividers(line,chr);

        int first = 0;
        for( vec2 d:dividers){
            string str = line.substr(first,d.x-first);

            first = d.y;
            strings.push_back(str);
        }

        return strings;
    }

    float toNum(string line){
        return  atof(line.c_str());
    }

    string vec3ToStr(vec3 vec){
        string st(""+to_string(vec.x)+" "+to_string(vec.y)+" "+to_string(vec.z));
        return st;
    }


    void print(string txt){
        cout<<txt<<endl;
    }

    void print(double n){
        cout<<to_string(n)<<endl;
    }

    void print(int n){
        cout<<to_string(n)<<endl;
    }

    void print(vec3 vec){
        cout<<to_string(vec.x)<<" "<<
              to_string(vec.y)<<" "<<
              to_string(vec.z)<<" "<<
              endl;
    }

    void print(int kupa[]){
        for(int i = 0;i<sizeof(kupa);i++){
            cout<<to_string(kupa[i])<<endl;
        }
    }


};

#endif // STR_H
