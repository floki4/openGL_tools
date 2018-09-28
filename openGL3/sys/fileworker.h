#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <string>
#include <fstream>

class FileWorker
{
 private:

public:
    FileWorker(){}

  //  typedef string (*ptr_func)(string);

    void read(string path){
        string line;
           ifstream myfile (path);
        if (myfile.is_open()) {
            while ( getline(myfile,line) ) {
                 processing(line);
            }
            myfile.close();
        }
        else cout << "Unable to open file "<<path<<endl;
    }

virtual void processing(string line){}
};

#endif // FILEWORKER_H
