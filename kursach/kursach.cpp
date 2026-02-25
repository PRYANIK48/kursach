#include <iostream>
#include "Game.h"


int main()
{
	srand(static_cast<unsigned>(time(0)));
	Game game;

	//Clock clock;
	while (game.getWindowIsOpen())
	{
		//float time = clock.getElapsedTime().asMilliseconds();
		//clock.restart(); 
		game.Update();
		game.Render();
	}
	return 0;
}