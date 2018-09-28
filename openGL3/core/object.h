#ifndef OBJECT_H
#define OBJECT_H



#include <fstream>
#include <vector>

using namespace std;

//f перше число - індекс вершини | друге число - (напевно кількість її дублів).

class Object
{


private:
    int tmp = 1;
    vector< vec3 > vertices;




public:
    Object(){}

    void read(string path){
        string line;
        ifstream myfile (path);

        //Перебираємо всі рядки
        if (myfile.is_open()) {
            while ( getline (myfile,line) ) {

                char * str = strToChar(line);

                //Вершини
                string name = line.substr(0,2);
                if(name == "v "){
                    vec3 vertex = strToVec(line);
                    vertices.push_back(vertex);
                }
               // vertices.push_back(vertices.);


                cout << '\n';
            }
            myfile.close();
        }
        else cout << "Unable to open file";
    }

    void draw(){
       //   glBegin(GL_POLYGON);

       //     glBegin(GL_QUAD_STRIP);
      //  reverse(vertices.begin(), vertices.end());

          glBegin(GL_TRIANGLES);

                  glColor3f(1.0, 1.0, 0.0);

                        for(vec3 vec:vertices){
                     glVertex3d(vec.x, vec.y, vec.z);
                  }

                   glEnd();

    }

    vec3 strToVec(string line){
        vec3 vertex;
        vertex.x = atof(readToSpace(line).c_str());
        vertex.y = atof(readToSpace(line).c_str());
        vertex.z = atof(readToSpace(line).c_str());

            cout << vertex.x <<" | ";
        cout << vertex.y <<" | ";
        cout << vertex.z <<" | ";

        tmp = 1;
        return vertex;
    }

    char * strToChar(string str){
        char * chr = new char[str.length() + 1];
        strcpy(chr, str.c_str());
        return chr;
    }


    string readToSpace(string line){
        string res = "";
        char * str = strToChar(line);

        for(int i = tmp+1;i<line.length() + 1;i++){
            if(str[i] != ' '){
                res += str[i];
            }else{
                tmp = i;
                break;
            }
        }
        return res;
    }
};
#endif // OBJECT_H
