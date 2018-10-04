#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:

public:
    Matrix(){}

    void start(){
  glPushMatrix();
    }

    void rotate(double x,double y,double z){
        glRotated(x,1,0,0);
          glRotated(y,0,1,0);
         glRotated(z,0,0,1);
    }

    void scale(double scale){
         glScaled(scale,scale,scale);
    }

    void move(double x,double y,double z){
        glTranslated(x, y, z);
    }


    void end(){
glPopMatrix();
    }
};

#endif // MATRIX_H
