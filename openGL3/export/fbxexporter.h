#ifndef FBXEXPORTER_H
#define FBXEXPORTER_H

#include<core/str.h>

class FBXExporter
{

private:
    Str str;

    vector<vec3> points;
    int *indexArray;
    vector<vec3> normals;

    int poligonCount;
    int indexCount;
    int * poligons;

    int pointCount;



public:
    FBXExporter(){}

    void load(char* filename){

    }



    void draw(){

    }



};

#endif // FBXEXPORTER_H
