#ifndef NODE_H
#define NODE_H


#include <string.h>

#include <vector>

class Node
{
 private:

    vector<map<string,string>> attributes;

public:
    string name;

    Node(){}

    void setTagName(string name){
        this->name = name;
    }

};

#endif // NODE_H
