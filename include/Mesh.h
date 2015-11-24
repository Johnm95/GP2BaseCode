//
//  Mesh.h
//  GP2BaseCode
//
//  Created by John McMillan on 24/11/2015.
//
//

#ifndef Mesh_h
#define Mesh_h

#include "Vertices.h"
#include "Common.h"

struct MeshData
{
    vector<Vertex> vertices;
    vector<int> indices;
    
    int getNumVerts()
    {
        return vertices.size();
    };
    
    int getNumIndices()
    {
        return indices.size();
    };
    
    ~MeshData()
    {
        vertices.clear();
        indices.clear();
    }
};

#endif /* Mesh_h */
