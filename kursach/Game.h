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
using namespace sf;

class UI
{

};

class Game
{
public: 
	Game();
	const bool getWindowIsOpen() const;
	void PollEvents();
	void Update(float time);
	void Render();
	void RenderText(sf::RenderTarget& target);
	void UpdateText();

private:
	Vector2u window_resolution_;

    View view_;
	VideoMode video_mode_;
	RenderWindow window_;
	Event event_;
	Player* player_;

	Texture room_texture_;
	Sprite room_sprite_;

	sf::Font font;

	sf::Text uiText;

	void InitVariables();
	void InitWindow();
	void InitFonts();
	void InitTexts();
	void InitPlayer();
	void InitWalls();
	void InitTester();
	std::vector<Wall*> walls_;
	Enemy* enemy_;
};

