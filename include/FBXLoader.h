//
//  FBXLoader.h
//  GP2BaseCode
//
//  Created by John McMillan on 24/11/2015.
//
//

#ifndef FBXLoader_h
#define FBXLoader_h


#include "Common.h"
#include "Mesh.h"
#include "Vertices.h"
#include <fbxsdk.h>

bool loadFBXFromFile(const string& filename, MeshData *meshData);

void processNode(FbxNode *node,MeshData *meshData);
void processAttribute(FbxNodeAttribute * attribute, MeshData *meshData);
void processMesh(FbxMesh * mesh,MeshData *meshData);
void processMeshTextureCoords(FbxMesh * mesh, Vertex * verts, int numVerts);

#endif /* FBXLoader_h */
