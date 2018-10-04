#ifndef FBXEXPORTER_H
#define FBXEXPORTER_H

#include<fbxsdk.h>
//#include <fbxio/fbxiosettings.h>

class FBXExporter
{

private:
    FbxNode* root;

    FbxScene* getScene(char* filename){

        FbxManager* lSdkManager = FbxManager::Create();
        FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
        lSdkManager->SetIOSettings(ios);

        FbxImporter* lImporter = FbxImporter::Create(lSdkManager,"");

        if(!lImporter->Initialize(filename, -1, lSdkManager->GetIOSettings())) {
            printf("Call to FbxImporter::Initialize() failed.\n");
            printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
            exit(-1);
        }

        FbxScene* lScene = FbxScene::Create(lSdkManager,"myScene");
        lImporter->Import(lScene);

        lImporter->Destroy();
        return lScene;

    }
public:
    FBXExporter(){}

    void load(char* filename){
        root = getScene(filename)->GetRootNode();

        FbxNode* cube = root->GetChild(0);
        cout<<cube->GetName()<<endl;

        FbxMesh* cubeMesh = cube->GetMesh();

    }

};

#endif // FBXEXPORTER_H
