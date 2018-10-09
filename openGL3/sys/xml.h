#ifndef XML_H
#define XML_H



#include<sys/fileworker.h>
#include<sys/str.h>
#include<sys/print.h>
#include<sys/xml/circle.h>

class Xml
{
private:

    FileWorker fworker;
    Str str;


    vector<Circle> circles;

    string path;
    vector<string> stroku;

    Print _p;

public:
    Xml(){}

    //TODO Якщо файл змінився, треба перезавантажити дані. (перевіряти зміну раз в 3 сек.)

    void read(char * path){
        stroku = fworker.read(path);

        for(string s:stroku){
            processing(s);
        }
    }

    //Сформувати список нодів
    void processing(string line){
        //Чи пустий рядок

        if(line.size() >0){
            //Побудова нода
            Circle circle;
            //Знаходимо дані нода

            //Назва тега
            circle.name = circleName(line);
            //Атрибути
           circle = readAttrs(line,circle);
      _p.arr(circle.attr);

            circles.push_back(circle);
        }

    }

    Circle readAttrs(string line,Circle circle){
        //Circle circle;
        int  start = str.charPos("<",line);
        int  end = str.charPos(">",line);
        int space = str.charPosAfter(start," ",line);

        string attrs = str.sub(space,end-1,line);
        vector<string> strings =  str.devide(attrs," ");


        for( string s:strings){

            vector<string> t = str.devide(s,"=");

            try{
                string key = t[0];
                string value = t[1];
                Item item(key,value);

                circle.attr.push_back(item);

            }catch (exception& e) {
                _p.stroka(e.what());
            }

            //   }
        }

       return circle;

    }

    string circleName(string line){
        int start, end,space;
        string res;

        start = str.charPos(line,"<");
        space = str.charPosAfter(start," ",line);

        res = str.sub(start,space,line);
        return res;
    }

    bool isChange(){
        return false;
    }
};

#endif // XML_H
