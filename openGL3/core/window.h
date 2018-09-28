#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glut.h>

class Window {


private:

    int w,h;

  static  void reshape(int w, int h){
        glViewport(0, 0, w, h);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }


public:


    Window(int argc, char *argv[]){
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
     //   glutInitDisplayMode (GLUT_SINGLE|GLUT_RGBA);
        glutInitWindowPosition(0,0);

       // gluPerspective(54.0, w/h, -1.0, 1000.0);
        //зададим размеры координатной сетки
      //   glOrtho(-(w/2),w/2,-(h/2),h/2,1,1);
     //    gluOrtho2D (0, w, 0, h);
    }

    void create(char * name,int w,int h){
        glutInitWindowSize(w, h);
        glutCreateWindow(name);
        gluPerspective(0, w/h, 0.0, 1000.0);
    }

    void idle(void (* idle)(void)){
        glutIdleFunc(idle);
    }

    void display(void (* disp)(void)){
      //   glutReshapeFunc(reshape);
        glutDisplayFunc(disp);    
    }

    void keyboard(void (* keyboard)(unsigned char  key,int mouseX,int mouseY)){
        glutKeyboardFunc(keyboard);
    }
    void mouse(void (* mouse)(int button, int state, int x, int y)){
         glutMouseFunc(mouse);
    }


    void startloop(){
  glutMainLoop();
    }


};


#endif // WINDOW_H
