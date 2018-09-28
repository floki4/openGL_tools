#ifndef GAME_H
#define GAME_H


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>


#include <core/input.h>
#include <core/object.h>



#include<core/sprite.h>


using namespace std;

class Game
{
private:

    Input input;
    Object obj;


vector< vec3 > temp_vertices;

Image img;

public:
    Game(){}

    void init(){
img.load("img/bob.png");
        //TODO реалізувати створення вікна в init ігрового циклу
      //  input.setWindow(win);

       // obj.read("models/building.obj");

glShadeModel(GL_FLAT);
    }

    void update(){

    }

    void render(){

       glClearColor(0.8, 1.0, 0.6, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //     glColor3f(1.0, 1.0, 1.0);
    //    glLoadIdentity();
       img.show();


   //    glFlush();
        //TODO зробити класи для примітивів.
        //TODO Додати до них можливість градієнт
      /*  glBegin(GL_QUADS);

      //  glColor3f(1.0, 1.0, 1.0);
         glColor3f(0.0, 0.0, 1.0);
        glVertex2i(250, 450);

       // glColor3f(0.0, 0.0, 1.0);
        glVertex2i(250, 150);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(550, 150);
      //  glColor3f(1.0, 0.0, 0.0);
        glVertex2i(550, 450);
        glEnd();*/


    }

    bool close(){
        return input.keyPress(input.ESCAPE);
    }
};

#endif // GAME_H
