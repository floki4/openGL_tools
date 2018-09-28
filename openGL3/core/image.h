#ifndef IMAGE_H
#define IMAGE_H

#include "SOIL/SOIL.h"

class Image
{
private:
    GLuint texture;
    unsigned char* image;

public:

    int x,y,z, w, h;
   // float scale;
    int angle;

    Image(){
        x = 0;
y = 0;
     //   scale = 1;
        angle = 0;

      //  w = 300;
      //  h = 200;
    }

    void load(char * path){
        texture = SOIL_load_OGL_texture(path,
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_NTSC_SAFE_RGB |SOIL_FLAG_INVERT_Y| SOIL_FLAG_MULTIPLY_ALPHA
                                        );

        if(texture == NULL){
            printf("[Texture loader] \"%s\" failed to load!\n", path);
        }
    }

    void show(){

        matrix();
        effects();
        texCoord();
        clear();
    }

    void effects(){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void texCoord(){
        glBegin(GL_QUADS);

        glTexCoord2d(0, 0); glVertex3d(x, y, 0);
           glTexCoord2d(0, 1); glVertex3d(x, y + h, 0);
           glTexCoord2d(1, 1); glVertex3d(x + w, y + h, 0);
           glTexCoord2d(1, 0); glVertex3d(x + w, y, 0);
        glEnd();
    }

    void matrix(){
        glPushMatrix();
      //  glLoadIdentity();
     //   glTranslated(x, y, z);
        glRotated(angle,0, 0, 1);
     //   glScaled(scale,scale,0);


    }

    void clear(){
        glPopMatrix();
       glDisable(GL_BLEND);
    }
};

#endif // IMAGE_H
