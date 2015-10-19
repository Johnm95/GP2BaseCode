#include "MyGame.h"

int main(int argc, char * arg[])
{
	CMyGame * pGame = new CMyGame();

	pGame->init();
	pGame->run();

	if (pGame)
	{
		delete pGame;
		pGame = NULL;
	}
	return 0;
}
