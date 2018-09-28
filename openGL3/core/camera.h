#ifndef CAMERA_H
#define CAMERA_H



class Camera
{
private:

public:
        int x,y, w,h;
    Camera(){}

    void size(int w,int h){
        this->w = w;
        this->h = h;
    }

    void show(int x,int y){
        glMatrixMode(GL_PROJECTION);
          glPushMatrix();
          glLoadIdentity();

          gluOrtho2D(x, w+x, y, h+y);
          glMatrixMode(GL_MODELVIEW);
 glPopMatrix();
    }
};

#endif // CAMERA_H
