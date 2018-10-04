#ifndef LIGHT_H
#define LIGHT_H


class Light
{
private:

    // Assign a default value

    //розсіювання
    float light_diffuse[4]   = { 0.8, 0.8, 0.8, 0.1 };

    //світло навколишнього серидовища, колір
    float light_ambient[4]   = { 0.9, 0.9, 0.9, 0.1 };
//світлоотзеркалення
    float light_specular[4]  = { 0.5, 0.5, 0.9, 0.1 };

    float light_position[4]  = { 0.0, 1.0, 0.0, 0.5 };

public:
    Light(){}

    void init(){
        //Змішувати кольори
        glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //    glEnable(GL_LIGHTING);
           //   glEnable(GL_LIGHT0);

            //    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
            //    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient );
            //    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular );
            //    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
           //     glShadeModel(GL_SMOOTH);
             //      glDisable(GL_CULL_FACE );
    }
};

#endif // LIGHT_H
