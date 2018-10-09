#ifndef GAME_H
#define GAME_H

#include<core/inc.h>

class Game
{
private:
    Camera camera;
    Light light;
    ObjExporter obj;

    Xml xml;

    Image img;

    int oldX,newX, oldY,newY;

    int objZ =0;
    bool b_wire = false;

public:
    Game(){}

    void init(){
        //   xml.read("file/1.xml");
        obj.read("model/proba.obj");

        camera.size(640,480);

        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        light.init();
    }

    void idle(){

    }

    void render(){
       lineOnly(b_wire);

       camera.show(0,0);
       light.draw();
//glNormal3d(0,0.7,1);
        Matrix matrix;
        matrix.start();
           matrix.move(0,0,-3);
        matrix.rotate(0,objZ,0);
        matrix.scale(0.7);

        obj.draw();
        matrix.end();
    }


void lineOnly(bool b){
    if(b) {glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}else{
       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
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

        double speed = 5;
        switch (key) {

        case 'a':     //left
            objZ -=speed;
            break;

        case 'd':    //right
            objZ +=speed;
            break;

        case 's':
            img.y -=speed;
            break;

        /*case 'w':
            img.y +=speed;
            break;*/

        case 'w':
           if(b_wire==true){b_wire=false;}else{b_wire=true;}
            break;



        default:
            break;
        }
    }


};

#endif // GAME_H
