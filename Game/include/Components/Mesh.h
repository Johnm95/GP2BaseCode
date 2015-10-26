#ifndef _MESH_H
#define _MESH_H

#include "Common.h"
#include "Component.h"
#include "Mesh.h"

class Mesh:public Component
{
public:
  Mesh();
  ~Mesh();

  void init(const string& filename);
  void init(Vertex *pVertex, int numVertices, int *pIndices, int numIndices);
  void onPreRender();
private:
  void onBind();
  void destroy();
private:
  GLuint m_VAO;
  GLuint m_VBO;
  GLuint m_EBO;

};
#endif
