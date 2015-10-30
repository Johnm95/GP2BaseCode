#ifndef _GAMEAPPLICATION_H
#define _GAMEAPPLICATION_H

#include "Common.h"
#include "FileSystem.h"
#include "Graphics.h"
#include "GameObject.h"

class GameApplication
{
public:
	GameApplication();
	virtual ~GameApplication();

	virtual bool init();
	virtual void update();
	virtual void render();
	virtual void destroy();
	void run();
private:
	SDL_Window * m_pWindow;
	SDL_GLContext m_glcontext;
	bool m_bIsRunning;
	vector<GameObject::GameObjectSharedPtr> m_GameObjects;

};
#endif
