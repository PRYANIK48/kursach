#pragma once
#include<ctime>
#include "Player.h" 
<<<<<<< HEAD
#include "Enemy.h"
=======
#include "Entity.h"
>>>>>>> parent of a339588 (obed)
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


	void InitTester();
	Enemy* enemy_;
};

