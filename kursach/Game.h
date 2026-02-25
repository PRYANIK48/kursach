#pragma once
#include<ctime>
#include "Player.h" 
using namespace sf;
class Game
{

private:
	RenderWindow* window;
	VideoMode videoMode;
	Event event;
	Player player;
	void initVariables();
	void initWindow();

public: 
	Game();
	virtual ~Game();
	const bool getWindowIsOpen() const;
	void PollEvents();
	void Update();
	void Render();
};

