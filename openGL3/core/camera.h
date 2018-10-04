#ifndef CAMERA_H
#define CAMERA_H


#include<primitives/point.h>

class Camera
{
private:

public:
    Point eye;
    Point center;
    Point up;

    int x,y, w,h;
    Camera(){
        eye.set(0, 0,1);
         center.set(0, 0,-1);
         up.set(0,1,0);
    }

    void size(int w,int h){
        this->w = w;
        this->h = h;
    }

    void show(int x,int y){
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluLookAt(eye.x, eye.y,eye.z,
                  center.x, center.y,center.z,
                  up.x, up.y,up.z);

        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }
};

#endif // CAMERA_H
