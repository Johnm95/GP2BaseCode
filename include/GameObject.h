#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Common.h"
#include "Vertices.h"

//google camel case
class GameObject
{
public:
	GameObject();
	~GameObject();

	void update();
	
	void createBuffer(Vertex *pVerts, int numVerts, 
		int *pIndices, int numIndices);

	void loadShader(const string& vsFilename, 
		const string& fsFilename);

	GLuint getShaderProgram()
	{
		return m_ShaderProgram;
	};
private:
	GLuint m_VBO;
	GLuint m_EBO;
	GLuint m_VAO;
	GLuint m_ShaderProgram;
	int m_NoOfVertices;
	int m_NoOfIndices;

	mat4 m_ModelMatrix;
	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	vec4 m_AmbientMaterial;
	vec4 m_DiffuseMaterial;
	vec4 m_SpecularMaterial;
	float m_SpecularPower;

protected:

};

#endif