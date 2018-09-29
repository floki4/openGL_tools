#ifndef OBJECT_H
#define OBJECT_H



#include <fstream>
#include <vector>

#include <sys/str.h>

using namespace std;

//f перше число - індекс вершини | друге число - (напевно кількість її дублів).

class Object
{


private:

    Str str;

    int tmp = 1;
    vector< vec3 > vertices;
    vector< vec2 > faces;

public:
    Object(){}

    void read(string path){
        string line;
        ifstream myfile (path);

        //Перебираємо всі рядки
        if (myfile.is_open()) {
            while ( getline (myfile,line) ) {

                //Вершини
                string name = line.substr(0,2);
                if(name == "v "){
                     vec3 vec = strToVec(line);

                     cout<<str.vec3ToStr(vec)<<endl;

                    vertices.push_back(vec);
                }
                if(name == "f "){
                    readFacesFromLine(line);
                }
                cout << '\n';
            }
            myfile.close();
            cout << "---------"<<endl;
        }
        else cout << "Unable to open file";
    }

    void draw(){
        glBegin(GL_POLYGON);

        glColor3f(1.0, 1.0, 0.0);

        for(vec2 face:faces){
            vec3 vec = vertices[face.x-1];

         //   cout<<face.x<<" "<<str.vec3ToStr(vec)<<endl;

            glVertex3d(vec.x, vec.y, vec.z);
        }
       cout<<"----------------"<<endl;

        glEnd();

    }

    void readFacesFromLine(string line){
        vec2 face;

        string sub = str.sub(1,line);
        vector<string> tmpFaces = str.devide(sub," ");

        for(string s:tmpFaces){
            vector<string> tmpFace = str.devide(s,"//");

            face.x = str.toNum(tmpFace[0]);
            face.y=str.toNum(tmpFace[1]);

            faces.push_back(face);
        }
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
