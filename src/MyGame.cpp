#include "MyGame.h"

Vertex verts[] = {
	//Front
	{ vec3(-0.5f, 0.5f, 0.5f),
	vec4(1.0f, 0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f) },// Top Left

	{ vec3(-0.5f, -0.5f, 0.5f),
	vec4(1.0f, 1.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f) },// Bottom Left

	{ vec3(0.5f, -0.5f, 0.5f),
	vec4(0.0f, 1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f) }, //Bottom Right

	{ vec3(0.5f, 0.5f, 0.5f),
	vec4(1.0f, 0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f) },// Top Right


	//back
	{ vec3(-0.5f, 0.5f, -0.5f),
	vec4(1.0f, 0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f) },// Top Left

	{ vec3(-0.5f, -0.5f, -0.5f),
	vec4(1.0f, 1.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f) },// Bottom Left

	{ vec3(0.5f, -0.5f, -0.5f),
	vec4(0.0f, 1.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f) }, //Bottom Right

	{ vec3(0.5f, 0.5f, -0.5f),
	vec4(1.0f, 0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f) },// Top Right

};

int indices[] = {
	//front
	0, 1, 2,
	0, 3, 2,

	//left
	4, 5, 1,
	4, 1, 0,

	//right
	3, 7, 2,
	7, 6, 2,

	//bottom
	1, 5, 2,
	6, 2, 5,

	//top
	4, 0, 7,
	0, 7, 3,

	//back
	4, 5, 6,
	4, 7, 6
};

MyGame::MyGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
  shared_ptr<GameObject> pObj(new GameObject);
	pObj->setName("Cube");
  pObj->addComponent(shared_ptr<Transform>(new Transform));

	shared_ptr<Mesh> pMesh=shared_ptr<Mesh>(new Mesh);
	pMesh->init(verts,8,indices,36);
	pObj->addComponent(pMesh);

	shared_ptr<Shader> pShader=shared_ptr<Shader>(new Shader);
	string vsFilename=ASSET_PATH+SHADER_PATH+"/simpleVS.glsl";
	string fsFilename=ASSET_PATH+SHADER_PATH+"/simpleFS.glsl";
	pShader->loadShaderFromFiles(vsFilename,fsFilename);
	pShader->link();

	shared_ptr<Material> pMaterial=shared_ptr<Material>(new Material);
	pMaterial->setShader(pShader);
	pObj->addComponent(pMaterial);


  m_GameObjects.push_back(pObj);

  GameApplication::initScene();
}
