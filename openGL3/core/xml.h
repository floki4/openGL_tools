#ifndef XML_H
#define XML_H


#include <fstream>

#include<core/str.h>
#include<system/xml/node.h>

class Xml
{
private:

    Str str;

    vector<map<string,Node *>> nodes;

        string path;

public:
    Xml(){}


    // Завантажити дані xml файлу до вектора.
    //Якщо файл змінився, треба перезавантажити дані. (перевіряти зміну раз в 3 сек.)

    //Считуємо всі рядки

    void load(char * path){
        string line;
           ifstream myfile (path);
        if (myfile.is_open()) {
            while ( getline(myfile,line) ) {
                 processing(line);
            }
            myfile.close();
        }
        else cout << "Unable to open file";
    }


    void processing(string line){
 cout <<line<<endl;
    }


    bool isChange(){
        return false;
    }
};

#endif // XML_H
