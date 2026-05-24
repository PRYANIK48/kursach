#pragma once
#include<ctime>
#include <iostream>
#include "EntityInteractionSystem.h"
#include "DebugSettings.h"
#include "Player.h" 
#include "Enemy.h"
#include "Entity.h"
#include "Wall.h"
#include "Room.h"
#include "sstream"
#include "UI.h"
using namespace sf;


class Game
{
public: 
	Game();
	const bool getWindowIsOpen() const;
	void PollEvents();
	void Update(float time);
	HUDData GetHUDData() const;
	void Render();

private:
	Vector2u window_resolution_;
	UI ui_;
	Room room_;
    View view_;
	VideoMode video_mode_;
	RenderWindow window_;
	Event event_;
	Player* player_;

	Texture room_texture_;
	Sprite room_sprite_;

	void InitVariables();
	void InitWindow();


	void InitRoom();
	void InitPlayer();
	void InitTester();
	std::vector<Wall*> walls_;
	Enemy* enemy_;
};

