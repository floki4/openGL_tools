#ifndef TRIANGLES_H
#define TRIANGLES_H

#include<core/aobject.h>

class Triangles: public AObject{

private:

    // unsigned int VBO;
      unsigned int shaderProgram;

  /*  float vertices[] = {
           -0.5f, -0.5f, 0.5f,
            0.5f, -0.5f, 0.5f,
            0.0f,  0.5f, 0.0f
        };*/

     void createBuffer(){
            unsigned int VBO;
         glGenBuffers(1, &VBO);
         glBindBuffer(GL_ARRAY_BUFFER, VBO);      //   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

     }

     unsigned int createVShader(){
         const char* vertexShaderSource = "#version 330 core\nlayout (location = 0)"
               "in vec3 aPos;\n\nvoid main()\n{\ngl_Position ="
               "vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\n\0";

         unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
         glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
         glCompileShader(vertexShader);
         return vertexShader;
    }

     unsigned int createFShader(){
        const char* fragmentShaderSource = "#version 330 core\n"
              "out vec4 FragColor;\n\nvoid main()\n{\n"
              "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}\n\0";

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
          glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
          glCompileShader(fragmentShader);
          return fragmentShader;
    }

    void linkShader(){
        shaderProgram = glCreateProgram();
         glAttachShader(shaderProgram, createVShader());
         glAttachShader(shaderProgram, createFShader());
         glLinkProgram(shaderProgram);
         glUseProgram(shaderProgram);

          //  // We no longer need the prior shaders after the linking
         // glDeleteShader(vertexShader);
       //   glDeleteShader(fragmentShader);
    }

public: 
    Triangles(){}


    void init(){
          createBuffer();
          //  linkShader();

         //   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
           //  glEnableVertexAttribArray(0);


    }

    void draw(){

  /*      unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);*/

       /* glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glUseProgram(shaderProgram);*/
    }
};

#endif // TRIANGLES_H
