#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <fstream>

class FileWorker
{
 private:

public:
    FileWorker(){}

  //  typedef string (*ptr_func)(string);

    vector<string> read(string path){
        string line;
        vector<string> stroku;
           ifstream myfile (path);
        if (myfile.is_open()) {
            while ( getline(myfile,line) ) {
                    stroku.push_back(line);
            }
            myfile.close();
            return stroku;
        }
        else cout << "Unable to open file "<<path<<endl;
    }
};

#endif // FILEWORKER_H
