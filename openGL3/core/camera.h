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

    //Кут огляду
    GLdouble kut = 90;
    //Куди дивитись
    GLdouble aspect;
    //Звідки
    GLdouble zNear = 1;
    //Як далеко
    GLdouble zFar = 1000;

    int x,y, w,h;
    Camera(){
        eye.set(0, 0,1);
        center.set(0, 0,-1);
        up.set(0,1,0);
    }

    void size(int w,int h){
        this->w = w;
        this->h = h;
        aspect = w/h;
    }

    void show(int x,int y){
      //  glPushMatrix();
     // glOrtho(-(w/2),w/2,-(h/2),h/2,1,1);

        glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
          glLoadIdentity();             // Reset

          gluPerspective(kut, aspect, zNear, zFar);

          gluLookAt(eye.x, eye.y,eye.z,
                  center.x, center.y,center.z,
                  up.x, up.y,up.z);

        //   glMatrixMode(GL_MODELVIEW);
      //  glPopMatrix();
    }
};

#endif // CAMERA_H
