#include "GameApplication.h"

GameApplication::GameApplication()
{

}

GameApplication::~GameApplication()
{
	destroy();
}

bool GameApplication::init()
{
	ChangeWorkingDirectory();
	//Controls the game loop
	m_bIsRunning = true;

	// init everyting - SDL, if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR SDL_Init " << SDL_GetError() << std::endl;

		return false;
	}
	//
	int	imageInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int	returnInitFlags = IMG_Init(imageInitFlags);
	if (((returnInitFlags)&	(imageInitFlags)) != imageInitFlags)	{

		cout << "ERROR	SDL_Image	Init	" << IMG_GetError() << endl;
		return false;
	}

	if (TTF_Init() == -1)	{
		std::cout << "ERROR	TTF_Init:	" << TTF_GetError();
		return false;
	}

	//Request opengl 4.1 context, Core Context
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	//Create a window
	m_pWindow = SDL_CreateWindow(
		"SDL",             // window title
		SDL_WINDOWPOS_CENTERED,     // x position, centered
		SDL_WINDOWPOS_CENTERED,     // y position, centered
		640,                        // width, in pixels
		480,                        // height, in pixels
		SDL_WINDOW_OPENGL           // flags
		);

	// Create an OpenGL context associated with the window.
	m_glcontext = SDL_GL_CreateContext(m_pWindow);

	//Call our InitOpenGL Function
	initOpenGL();
	//Set our viewport
	setViewport(640, 480);
	initScene();

	return true;
}

void GameApplication::initScene()
{
	for (vector<GameObject::GameObjectSharedPtr>::iterator it=m_GameObjects.begin();it!=m_GameObjects.end();++it)
	{
		(*it)->onInit();
	}
}

void GameApplication::update()
{
	for (vector<GameObject::GameObjectSharedPtr>::iterator it=m_GameObjects.begin();it!=m_GameObjects.end();++it)
	{
		(*it)->onUpdate();
	}
}

void GameApplication::render()
{

	//Set the clear colour(background)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//clear the colour and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (vector<GameObject::GameObjectSharedPtr>::iterator it=m_GameObjects.begin();it!=m_GameObjects.end();++it)
	{
		(*it)->onPreRender();
		(*it)->onRender();
		(*it)->onPostRender();
	}
}

void GameApplication::destroy()
{
	// clean up, reverse order!!!
	m_GameObjects.clear();
	SDL_GL_DeleteContext(m_glcontext);
	SDL_DestroyWindow(m_pWindow);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void GameApplication::run()
{
	SDL_Event event;
	//Game Loop
	while (m_bIsRunning)
	{
		//While we still have events in the queue
		while (SDL_PollEvent(&event)) {
			//Get event type
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				//set our boolean which controls the loop to false
				m_bIsRunning = false;
			}
		}
		//init Scene
		update();
		//render
		render();
		//Call swap so that our GL back buffer is displayed
		SDL_GL_SwapWindow(m_pWindow);

	}
}
