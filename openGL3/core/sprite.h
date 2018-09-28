#ifndef SPRITE_H
#define SPRITE_H

#include<core/image.h>

class Sprite
{
private:

public:
    int x,y,w,h;

    Sprite(char * path, int x,int y){

    }

    virtual void draw(){}
};

#endif // SPRITE_H
