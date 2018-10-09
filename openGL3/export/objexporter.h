#ifndef OBJECT_H
#define OBJECT_H



#include <fstream>
#include <vector>

#include <sys/str.h>
#include <sys/print.h>
#include <sys/fileworker.h>

//f перше число - індекс вершини | друге число - (напевно кількість її дублів).

class ObjExporter
{


private:

    FileWorker fileWorker;
    Str str;
    Print _p;

    int tmp = 1;
    vector< vec3 > vertices;
    vector< vec3 > normals;
    vector< vec4 > faces;

public:
    ObjExporter(){}

    void read(string path){

        vector<string> stroku = fileWorker.read(path);

        for(string line:stroku){
            string name = line.substr(0,2);

            if(name == "v "){
                vertices.push_back(strToVec(line));
            }

            if(name == "vn"){
                normals.push_back(strToVec(line));
            }
            if(name == "f "){
                readFacesFromLine(line);
            }

        }
    }


    void draw(){
      //  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

        int points = 4;
       // int count = (faces.size()+1)/points;

        for(vec4 face:faces){
       // glBegin(GL_POLYGON);
                     vec3 vec_1 = vertices[face[0]];
             vec3 vec_2 = vertices[face[1]];
             vec3 vec_3 = vertices[face[2]];
             vec3 vec_4 = vertices[face[3]];


     //   glBegin(GL_QUADS);
  glBegin(GL_POLYGON);
glVertex3d(vec_1.x, vec_1.y,vec_1.z);
 glVertex3d(vec_2.x, vec_2.y,vec_2.z);
 glVertex3d(vec_3.x, vec_3.y,vec_3.z);
 glVertex3d(vec_4.x, vec_4.y,vec_4.z);

        glEnd();
        // glBegin(GL_TRIANGLES);
        //  glColor3f(1.0, 1.0, 0.0);

        /*  for(vec3 vertex:vertices){
             glVertex3d(vertex.x, vertex.y, vertex.z);
         }*/

        /*  for(vec3 normal:normals){
              glNormal3d(normal.x, normal.y, normal.z);
         }*/

        //  reverse(faces.begin(), faces.end());
        //     reverse(faces.end(), faces.begin());

    /*    for(vec2 face:faces){
            vec3 vertex = vertices[face.x-1];
         //   vec3 normal = normals[face.y];

          //  glNormal3d(normal.x, normal.y, normal.z);
            glVertex3d(vertex.x, vertex.y, vertex.z);
        }*/


        // f v1//vn1
        /*     for(vec2 face:faces){

            vec3 vertex = vertices[face.x];
            vec3 normal = normals[face.y];


            glVertex3d(vertex.x, vertex.y, vertex.z);
        }*/



        glEnd();
        }

    }

    void readFacesFromLine(string line){
      //  vec2 face;
        vec4 poligon;

        string sub = str.sub(1,line);
        vector<string> tmpFaces = str.devide(sub," ");

        poligon[0] = str.toNum(tmpFaces[0])-1;
        poligon[1] = str.toNum(tmpFaces[1])-1;
        poligon[2] = str.toNum(tmpFaces[2])-1;
        poligon[3] = str.toNum(tmpFaces[3])-1;

          faces.push_back(poligon);
       /* for(string s:tmpFaces){
            face.x = str.toNum(s);
            faces.push_back(face);
        }*/

        /* for(string s:tmpFaces){
            vector<string> tmpFace = str.devide(s,"//");

            face.x = str.toNum(tmpFace[0]);
            face.y=str.toNum(tmpFace[1]);

            //  _p.vec(face);
            faces.push_back(face);
        }*/
    }

    vec3 strToVec(string line){
        vec3 vec;
        string sub = str.sub(1,line);
        vector<string> tmpVec = str.devide(sub," ");

        for(string s:tmpVec){
            vec.x = str.toNum(tmpVec[0]);
            vec.y=str.toNum(tmpVec[1]);
            vec.z = str.toNum(tmpVec[2]);
        }
        return vec;
    }


};
#endif // OBJECT_H
