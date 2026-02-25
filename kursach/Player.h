#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 
using namespace sf;
class Player
{
	private:
		Texture playerSheet;
		Sprite playerSprite;
		RectangleShape shape;

		Vector2f direction;
		float moveSpeed;
		float animFrame = 0.f;
		int animSheetRow = 0;
		int animLenght = 3;

		void initVariables();
		void initShape();
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();
	void UpdateInput();
	void Update();
	void Render(RenderTarget* target);
};

