#pragma once
#include<ctime>
#include "Player.h" 
using namespace sf;
class Game
{

private:
	Image map_image;
	Texture map;
	Sprite s_map;



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
	void Update(float time);
	void Render();
};

