#ifndef ITEM_H
#define ITEM_H


class Item
{

public:
    string key;
    string value;
    Item(string key,string value){
        this->key = key;
        this->value = value;
    //     cout<<key<<" "<<value<<endl;
    }

    void print(){
        cout<<this->key<<" "<<this->value<<endl;
    }

};

#endif // ITEM_H
