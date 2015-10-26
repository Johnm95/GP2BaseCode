#include "Components/Mesh.h"

Mesh::Mesh()
{
  m_VAO=0;
  m_VBO=0;
  m_EBO=0;
}

Mesh::~Mesh()
{
  destroy();
}

void Mesh::init(const string& filename)
{


}

void Mesh::init(Vertex *pVertex, int numVertices, int *pIndices, int numIndices)
{
    glGenVertexArrays(1,&m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1,GL_ARRAY_BUFFER,m_VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex),pVertex, GL_STATIC_DRAW);

    glGenBuffers(1,GL_ELEMENT_BUFFER,m_EBO);
    glBufferData(GL_ELEMENT_BUFFER, numIndices * sizeof(int),pIndices, GL_STATIC_DRAW);

    //describe vertices
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(offset(Vertices,position)));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(offset(Vertices,colour)));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(offset(Vertices,texCoords)));

}

void Mesh::onPreRender()
{
  bind();
}

void Mesh::bind()
{
  glBindVertexArray(m_VAO);
}

void Mesh::destroy()
{
  glDeleteBuffers(1,&m_EBO);
  glDeleteBuffers(1,&m_VBO);
  glDeleteVertexArrays(1,&m_VAO);
}
