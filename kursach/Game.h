#pragma once
#include<ctime>
#include "Player.h" 
using namespace sf;
class Game
{
public: 
	Game();
	const bool getWindowIsOpen() const;
	void PollEvents();
	void Update(float time);
	void Render();

private:
	RenderWindow* window_;
	VideoMode video_mode_;
	Event event_;
	Player player_;

	void InitVariables();
	void InitWindow();
};

