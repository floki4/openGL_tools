#ifndef GAME_H
#define GAME_H

#include<core/inc.h>

#include<fbxsdk.h>

class Game
{
private:
    Camera camera;
    Light light;
    ObjExporter obj;

   // Xml xml;

    Image img;

    int oldX,newX, oldY,newY;

public:
    Game(){}


    void init(){
         obj.read("models/proba.obj");

        camera.size(640,480);

glEnable(GL_ALPHA_TEST);
 glEnable(GL_DEPTH_TEST);

 light.init();

    }

     void idle(){

     }

       void render(){
   //     glClearColor(0.8, 1.0, 0.6, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glMatrixMode(GL_MODELVIEW);

//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glPointSize(4);
glLineWidth(1);
 //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

camera.show(0,0);

  //camera.eye.x=0.3;

Matrix matrix;
matrix.start();
matrix.rotate(0,0,0);
matrix.scale(0.3);
//matrix.move(-1,-0.5,-1);

//obj.draw();
matrix.end();

    }



       void mouse(int button, int state, int x, int y){

           int center  = 640/2;
          // double d = 1/(center);
            double d = 0.0009375;
           cout<<to_string(d)<<endl;
           switch(button){
           case GLUT_LEFT_BUTTON:
               if(state == GLUT_UP) {

                  if(x>center){ //right

                 camera.eye.x=x*d-0.3;
                   }else{  //left
                     camera.eye.x=-0.3+(x*d);
                   }
                   if(x < center+50 && x > center-50 ){
                        camera.eye.x=0;
                   }

                    glutSwapBuffers();

                    cout<<"x = " << x <<" y = "<<y<<endl;
                   camera.eye.print();
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
