#ifndef NODE_H
#define NODE_H


#include <sys/str.h>
#include <primitives/item.h>
#include <vector>

class Circle
{

public:
    string name;
   vector<Item> attr;
    vector<Circle> attachment;

    Circle(){}


private:


};

#endif // NODE_H
