#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 
using namespace sf;
class Game
{

private:
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
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

