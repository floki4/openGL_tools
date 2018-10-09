#include <iostream>



#include <GL/glew.h>
#include <GL/gl.h>

#include <glm/glm.hpp>
using namespace glm;

#include <core/window.h>
#include <game.h>


static void idle();
static void display();
static void keyboard(unsigned char key,int mouseX,int mouseY);
static void mouse(int button, int state, int x, int y);

Game game;

int main(int argc, char *argv[])
{
    Window win(argc,argv);
    win.create("My window",640,480);

    game.init();

    win.idle(idle);

    win.display(display);

    win.keyboard(keyboard);
     win.mouse(mouse);

    win.startloop();
    return 0;
}

static void idle(){

    game.idle();
}

static void display(){
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   // glClearDepth(1.0f);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game.render();

      //glFlush();
      glutSwapBuffers();
     glutPostRedisplay();
}



static void keyboard(unsigned char key,int mouseX,int mouseY){
game.keyboard(key);

}

static void mouse(int button, int state, int x, int y){
game.mouse(button,state,x,y);
}



