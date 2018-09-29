#ifndef GAME_H
#define GAME_H


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <core/object.h>
#include<core/camera.h>
#include<core/sprite.h>
#include<objects/fon.h>

#include<sys/xml.h>


using namespace std;

class Game
{
private:
    Camera camera;
    Fon fon;
    Object obj;
    Xml xml;


    Image img;

    int oldX,newX, oldY,newY;

public:
    Game(){}

    void init(){
    /*    img.load("img/car.png");
        img.x = 128;
        img.y = 32;
        img.w = img.h = 128;*/

        obj.read("models/pl.obj");
      //   obj.read("models/plant2.obj");
     //   fon.load();

        camera.size(640,480);


        //XML
    //    xml.read("xml/1.xml");

 glEnable(GL_DEPTH_TEST);
     //   glEnable(GL_COLOR_MATERIAL);
      //  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

        //light
   //     glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);
       // glLight(GL_LIGHT0,GL_AMBIENT);

        glShadeModel(GL_FLAT|GL_SMOOTH);

         //  glFrontFace(GL_CW);
      //  glEnable(GL_CULL_FACE);
    }

     void idle(){

     }

       void render(){
   //     glClearColor(0.8, 1.0, 0.6, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);

//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glPointSize(4);
glLineWidth(1);
// glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);


  glPushMatrix();
//glTranslatef(0, 0, -2.0f);

glRotatef(90,1,0,0);
  glRotatef(90,0,1,0);
 glRotatef(0,0,0,1);

 double scale = 0.3;
 glScaled(scale,scale,scale);

//glTranslatef(-1.0f, -.5f, -1.0f);

obj.draw();

/*
gluLookAt(0,0,0,    //eye
          0,0,0,    //center
          0,0,0);   //up
*/

glPopMatrix();

//glFlush();

    }

       void mouse(int button, int state, int x, int y){

           switch(button){
           case GLUT_LEFT_BUTTON:
               if(state == GLUT_UP) {
                   y = 480-y;
                   img.x = x;
                   img.y = y;
                   //       cout<<"x = " << x <<" y = "<<y<<endl;
               }

               break;

           case GLUT_RIGHT_BUTTON:

               break;
           case GLUT_MIDDLE_BUTTON:

               break;
           };
       }

       void keyboard(unsigned char key){

           double speed = 10;
           switch (key) {

           case 'a':     //left
               img.x -=speed;
               break;

           case 'd':    //right
               img.x +=speed;
               break;

           case 's':
               img.y -=speed;
               break;

           case 'w':
               img.y +=speed;
               break;

           default:
               break;
           }
       }


};

#endif // GAME_H
