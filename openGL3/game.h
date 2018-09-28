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


    vector< vec3 > temp_vertices;

    Image img;

    int oldX,newX, oldY,newY;

public:
    Game(){}

    void init(){
    /*    img.load("img/car.png");
        img.x = 128;
        img.y = 32;
        img.w = img.h = 128;*/

        obj.read("models/plant.obj");
      //   obj.read("models/plant2.obj");
     //   fon.load();

        camera.size(640,480);


        //XML
    //    xml.read("xml/1.xml");

// glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

        //light
        glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
            // Create light components
              float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
             float diffuseLight[] = { 0.7f, 0.7f, 0.7, 1.0f };
              float specularLight[] = { 0.4f, 0.4f, 0.4f, 1.0f };
              float position[] = { -1.5f, 1.0f, -4.0f, 1.0f };

              // Assign created components to GL_LIGHT0
              glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
              glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
              glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
              glLightfv(GL_LIGHT0, GL_POSITION, position);

        glShadeModel(GL_FLAT|GL_SMOOTH);


    }

       void render(){
   //     glClearColor(0.8, 1.0, 0.6, 1.0);
       // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //  camera.show(img.x-(camera.w/2-(img.w/2)),0);

       // fon.show(2);


      //  img.show();

  glPushMatrix();
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
 // glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

  glRotatef(30,0,1,0);
 glRotatef(-75,1,0,0);
 glRotatef(30,0,0,1);

 double scale = 0.3;
 glScaled(scale,scale,scale);

glTranslatef(.1f, -.5f, .0f);

obj.draw();

glPopMatrix();

        glFlush();

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
