#ifndef FON_H
#define FON_H


#include<core/image.h>



//TODO fonManager хранить все обьекти в листе и визивать их по ид

class Fon
{
private:

    Image fon1;
    Image fon2;

public:
    Fon(){}

    void load(){
        fon1.load("img/fon/fon1.jpg");
        fon2.load("img/fon/fon2.jpg");

        fon2.w = 2000;
        fon2.h = 480;

    }

    void show(int  fon_id){

        switch(fon_id){

        case 1:
            fon1.show();
            break;

        case 2:
            fon2.show();
            break;
        }
    }
};

#endif // FON_H
