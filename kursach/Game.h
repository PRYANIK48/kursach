#pragma once
#include<ctime>
#include "Player.h" 
#include "Entity.h"
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
	RenderWindow* window_;
	VideoMode video_mode_;
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


	void InitTester();
	Entity* enemy_;
};

