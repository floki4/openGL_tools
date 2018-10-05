#ifndef FBXEXPORTER_H
#define FBXEXPORTER_H

#include<fbxsdk.h>
//#include <fbxio/fbxiosettings.h>
#include<core/str.h>

class FBXExporter
{

private:
    Str str;
    FbxNode* root;

    vector<vec3> points;
    vector<vec3> normals;

    int poligonCount;
    int * poligons;

    FbxScene* getScene(char* filename){

        FbxManager* lSdkManager = FbxManager::Create();
        FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
        lSdkManager->SetIOSettings(ios);

        FbxImporter* lImporter = FbxImporter::Create(lSdkManager,"");

        if(!lImporter->Initialize(filename, -1, lSdkManager->GetIOSettings())) {
            str.print("Call to FbxImporter::Initialize() failed.");
            str.print(lImporter->GetStatus().GetErrorString());
            exit(-1);
        }

        FbxScene* lScene = FbxScene::Create(lSdkManager,"myScene");
        lImporter->Import(lScene);

        lImporter->Destroy();
        return lScene;

    }

    void readPoints(FbxMesh* mesh){
        int numVerts = mesh->GetControlPointsCount();

        for ( int j=0; j<numVerts; j++){
            FbxVector4 vert = mesh->GetControlPointAt(j);
            vec3 vic;
            vic.x=(float)vert.mData[0];
            vic.y=(float)vert.mData[1];
            vic.z=(float)vert.mData[2];
            points.push_back(vic);
            // str.print(vic);
        }
    }

    void readNormals(FbxMesh* mesh){
        int numNormals;
        FbxGeometryElementNormal* normalEl = mesh->GetElementNormal();
        if( normalEl)
        {
            numNormals = mesh->GetPolygonCount()*3;
            for(int j = 0 ; j < mesh->GetPolygonCount(); j++)
            {
                for(int i=0;i<3;i++)
                {
                    FbxVector4 normal = normalEl->GetDirectArray().GetAt(j);
                    vec3 vic;
                    vic.x= normal[0];
                    vic.y= normal[1];
                    vic.z= normal[2];
                    normals.push_back(vic);
                }
            }
        }
    }

public:
    FBXExporter(){}

    void load(char* filename){
        root = getScene(filename)->GetRootNode();

        FbxNode* cube = root->GetChild(0);

        str.print(cube->GetName());

        FbxMesh* cubeMesh = cube->GetMesh();

        int edgeCount = cubeMesh->GetMeshEdgeCount();



        readPoints(cubeMesh);
        readNormals(cubeMesh);

        poligonCount=cubeMesh->GetPolygonCount();

        FbxDouble3 pos = cube->LclTranslation.Get();
        FbxDouble3 rotation = cube->LclRotation.Get();
        FbxDouble3 scaling = cube->LclScaling.Get();
    }



    void draw(){
           int i,j;
        for(i=0;i<poligonCount-3;i++)
        {
            glBegin(GL_TRIANGLES);
          //  glNormalf(normals[i*3],normals[i*3+1],normals[i*3+2]);
            for(j=i;j<=i+2;j++)
                    glVertex3f(points[poligons[j]].x,
                               points[poligons[j]].y,
                               points[poligons[j]].z);
            glEnd();
        }
    }



};

#endif // FBXEXPORTER_H
