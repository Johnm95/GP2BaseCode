//
//  FBXLoader.cpp
//  GP2BaseCode
//
//  Created by John McMillan on 24/11/2015.
//
//

#include "FBXLoader.h"

int level = 0;

void PrintTabs()
{
    for (int i = 0; i<level; i++)
        printf("\t");
}

/**
*Return a string-based representation based on the attribute type
*/

FbxString GetAttributeTypeName(FbxNodeAttribute::EType type)
{
    switch (type)
    {
        case FbxNodeAttribute::eUnknown: return "unidentified";
        case FbxNodeAttribute::eNull: return "null";
        case FbxNodeAttribute::eMarker: return "marker";
        case FbxNodeAttribute::eSkeleton: return "skeleton";
        case FbxNodeAttribute::eMesh: return "mesh";
        case FbxNodeAttribute::eNurbs: return "nurbs";
        case FbxNodeAttribute::ePatch: return "patch";
        case FbxNodeAttribute::eCamera: return "camera";
        case FbxNodeAttribute::eCameraStereo: return "stereo";
        case FbxNodeAttribute::eCameraSwitcher: return "camera switcher";
        case FbxNodeAttribute::eLight: return "light";
        case FbxNodeAttribute::eOpticalReference: return "optical reference";
        case FbxNodeAttribute::eOpticalMarker: return "marker";
        case FbxNodeAttribute::eNurbsCurve: return "nurbs curve";
        case FbxNodeAttribute::eTrimNurbsSurface: return "trim nurbs surface";
        case FbxNodeAttribute::eBoundary: return "boundary";
        case FbxNodeAttribute::eNurbsSurface: return "nurbs surface";
        case FbxNodeAttribute::eShape: return "shape";
        case FbxNodeAttribute::eLODGroup: return "lodgroup";
        case FbxNodeAttribute::eSubDiv: return "subdiv";
        default: return "unknown";
            
    }
}

bool loadFBXFromFile(const string& filename, MeshData *meshData)
{
    return true;
}

void processNode(FbxNode *node, MeshData *meshData)
{
    
}

void processAttribute(FbxNodeAttribute *attribute, MeshData *meshData)
{
    
}

void processMesh(FbxMesh *mesh,MeshData *meshData)
{
    
}

void processMeshTextureCoords(FbxMesh *mesh, Vertex *verts, int numVerts)
{
    
}