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
	Player* player_;
	Texture room_texture_;
	Sprite room_sprite_;

	void InitVariables();
	void InitWindow();
	void InitPlayer();
};

