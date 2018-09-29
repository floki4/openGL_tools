#ifndef XML_H
#define XML_H



#include<sys/fileworker.h>
#include<sys/str.h>
#include<sys/xml/node.h>

class Xml : public FileWorker
{
private:

    //  FileWorker fWorker;
    Str str;

    vector<Node> nodes;

    string path;

public:
    Xml(){}

    //TODO Якщо файл змінився, треба перезавантажити дані. (перевіряти зміну раз в 3 сек.)

    /*  void load(char * path){
        fWorker.read(path);
    }*/

    //Сформувати список нодів
    void processing(string line){
        //Чи пустий рядок

        if(line.size() >0 && !closeTag(line)){
            //Побудова нода
            Node node;
            //Знаходимо дані нода

            //Назва тега
                 node.name = tagName(line);
                 //Атрибути
                  readAttrs(line);

                 nodes.push_back(node);
                 // cout << node.name <<endl;
        }

    }

    void readAttrs(string line){
      vector<string> strings =  str.devide(line," ");

        for( string str:strings){
           cout<<str<<endl;
        }
        cout<< "end"<<endl;

    }

    bool closeTag(string line){

        if(str.charPos(line,"/") == 1){
            return true;
        }
        return false;
    }


    string tagName(string line){
        int nStart, nEnd,space;
        string res;

        nStart = str.charPos(line,"<");
        nEnd = str.charPos(line,">");
        space = str.charPos(line," ");

        //-1 = нет символа
        if(space != -1) nEnd = space;
        res = line.substr(nStart+1,nEnd-nStart-1);
            return res;
        }


        bool isChange(){
            return false;
        }
    };

#endif // XML_H
