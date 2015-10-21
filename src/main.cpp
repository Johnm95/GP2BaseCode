#include "MyGame.h"

int main(int argc, char * arg[])
{
	MyGame * pGame = new MyGame();

	pGame->init();
	pGame->run();

	if (pGame)
	{
		delete pGame;
		pGame = NULL;
	}
	return 0;
}
