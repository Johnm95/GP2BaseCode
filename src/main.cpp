#include "Common.h"
#include "Graphics.h"
#include "Vertices.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "FBXLoader.h"
#include "FileSystem.h"


//matrices
mat4 viewMatrix;
mat4 projMatrix;
mat4 worldMatrix;
mat4 MVPMatrix;

GLuint VBO;
GLuint EBO;
GLuint VAO;
GLuint shaderProgram;

MeshData currentMesh;

vec4 ambientMaterialColour=vec4(0.2f,0.2f,0.2f,1.0f);
vec4 ambientLightColour=vec4(1.0f,1.0f,1.0f,1.0f);

vec4 diffuseLightColour=vec4(1.0f,1.0f,1.0f,1.0f);
vec4 diffuseMaterialColour=vec4(1.0f,0.0f,0.0f,1.0f);

vec4 specularLightColour=vec4(1.0f,1.0f,1.0f,1.0f);
vec4 specularMaterialColour=vec4(1.0f,1.0f,1.0f,1.0f);
float specularPower=25.0f;

vec3 lightDirection=vec3(0.0f,0.0f,1.0f);
vec3 cameraPosition=vec3(0.0f,10.0f,50.0f);

void initScene()
{

	string modelPath = ASSET_PATH + MODEL_PATH + "/utah-teapot.fbx";
	loadFBXFromFile(modelPath, &currentMesh);
	//Generate Vertex Array
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, currentMesh.getNumVerts()*sizeof(Vertex), &currentMesh.vertices[0], GL_STATIC_DRAW);

	//create buffer
	glGenBuffers(1, &EBO);
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//Copy Index data to the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, currentMesh.getNumIndices()*sizeof(int), &currentMesh.indices[0], GL_STATIC_DRAW);

	cout<<" Index Numbers "<<currentMesh.getNumIndices()<<" Vertex Numbers "<<currentMesh.getNumVerts()<<endl;

	//Tell the shader that 0 is the position element
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(sizeof(vec3)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(sizeof(vec3) + sizeof(vec4)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void**)(sizeof(vec3) + sizeof(vec4) + sizeof(vec2)));

	GLuint vertexShaderProgram = 0;
	string vsPath = ASSET_PATH + SHADER_PATH + "/specularVS.glsl";
	vertexShaderProgram = loadShaderFromFile(vsPath, VERTEX_SHADER);
	checkForCompilerErrors(vertexShaderProgram);

	GLuint fragmentShaderProgram = 0;
	string fsPath = ASSET_PATH + SHADER_PATH + "/specularFS.glsl";
	fragmentShaderProgram = loadShaderFromFile(fsPath, FRAGMENT_SHADER);
	checkForCompilerErrors(fragmentShaderProgram);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderProgram);
	glAttachShader(shaderProgram, fragmentShaderProgram);

	//Link attributes
	glBindAttribLocation(shaderProgram, 0, "vertexPosition");
	glBindAttribLocation(shaderProgram, 1, "vertexColour");
	glBindAttribLocation(shaderProgram, 2, "vertexTexCoords");
	glBindAttribLocation(shaderProgram, 3, "vertexNormal");

	glLinkProgram(shaderProgram);
	checkForLinkErrors(shaderProgram);
	//now we can delete the VS & FS Programs
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);
}

void cleanUp()
{
	//glDeleteTextures(1, &diffuseMap);
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void update()
{
	projMatrix = perspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);

	viewMatrix = lookAt(cameraPosition, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

	worldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

	MVPMatrix = projMatrix*viewMatrix*worldMatrix;
}


void render()
{
	//old imediate mode!
	//Set the clear colour(background)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//clear the colour and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaderProgram);

	GLint MVPLocation = glGetUniformLocation(shaderProgram, "MVP");

	glUniformMatrix4fv(MVPLocation, 1, GL_FALSE, value_ptr(MVPMatrix));

	GLint ambientLightColourLocation=glGetUniformLocation(shaderProgram,"ambientLightColour");
	GLint ambientMaterialColourLocation=glGetUniformLocation(shaderProgram,"ambientMaterialColour");

	GLint diffuseLightColourLocation=glGetUniformLocation(shaderProgram,"diffuseLightColour");
	GLint diffuseLightMaterialLocation=glGetUniformLocation(shaderProgram,"diffuseMaterialColour");
	GLint lightDirectionLocation=glGetUniformLocation(shaderProgram,"lightDirection");

	GLint specularLightColourLocation=glGetUniformLocation(shaderProgram,"specularLightColour");
	GLint specularLightMaterialLocation=glGetUniformLocation(shaderProgram,"specularMaterialColour");
	GLint specularPowerLocation=glGetUniformLocation(shaderProgram,"specularPower");
	GLint cameraPositionLocation=glGetUniformLocation(shaderProgram,"cameraPosition");

	GLint modelLocation=glGetUniformLocation(shaderProgram,"Model");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, value_ptr(worldMatrix));

	glUniform4fv(ambientLightColourLocation,1,value_ptr(ambientLightColour));
	glUniform4fv(ambientMaterialColourLocation,1,value_ptr(ambientMaterialColour));

	glUniform4fv(diffuseLightColourLocation,1,value_ptr(diffuseLightColour));
	glUniform4fv(diffuseLightMaterialLocation,1,value_ptr(diffuseMaterialColour));
	glUniform3fv(lightDirectionLocation,1,value_ptr(lightDirection));

	glUniform4fv(specularLightColourLocation,1,value_ptr(specularLightColour));
	glUniform4fv(specularLightMaterialLocation,1,value_ptr(specularMaterialColour));
	glUniform1f(specularPowerLocation,specularPower);
	glUniform3fv(cameraPositionLocation,1,value_ptr(cameraPosition));


	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, currentMesh.getNumIndices(), GL_UNSIGNED_INT, 0);
}

int main(int argc, char * arg[])
{
	ChangeWorkingDirectory();
	//Controls the game loop
	bool run = true;

	// init everyting - SDL, if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR SDL_Init " << SDL_GetError() << std::endl;

		return -1;
	}
	//
	int	imageInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int	returnInitFlags = IMG_Init(imageInitFlags);
	if (((returnInitFlags)&	(imageInitFlags)) != imageInitFlags)	{

		cout << "ERROR	SDL_Image	Init	" << IMG_GetError() << endl;
	}

	if (TTF_Init() == -1)	{
		std::cout << "ERROR	TTF_Init:	" << TTF_GetError();
	}

	//Request opengl 4.1 context, Core Context
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	//Create a window
	SDL_Window * window = SDL_CreateWindow(
		"SDL",             // window title
		SDL_WINDOWPOS_CENTERED,     // x position, centered
		SDL_WINDOWPOS_CENTERED,     // y position, centered
		640,                        // width, in pixels
		480,                        // height, in pixels
		SDL_WINDOW_OPENGL           // flags
		);

	// Create an OpenGL context associated with the window.
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	//Call our InitOpenGL Function
	initOpenGL();
	//Set our viewport
	setViewport(640, 480);

	initScene();
	//Value to hold the event generated by SDL
	SDL_Event event;
	//Game Loop
	while (run)
	{
		//While we still have events in the queue
		while (SDL_PollEvent(&event)) {
			//Get event type
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				//set our boolean which controls the loop to false
				run = false;
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				default:
					break;
				}
			}
		}
		//init Scene
		update();
		//render
		render();
		//Call swap so that our GL back buffer is displayed
		SDL_GL_SwapWindow(window);

	}

	// clean up, reverse order!!!
	cleanUp();
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	return 0;
}
