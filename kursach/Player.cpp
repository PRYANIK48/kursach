#include "Player.h"
#include <iostream>
void Player::initVariables()
{
	this->playerSheet.loadFromFile("Textures/hero.png");
	this->playerSprite.setTexture(playerSheet);
	this->playerSprite.setPosition(0, 0);
	this->playerSprite.setTextureRect(IntRect(0, 192, 96, 96));
	this->moveSpeed = 0.5;
}
void Player::initShape()
{
	this->shape.setFillColor(Color(220, 200, 150));
	this->shape.setSize(Vector2f(100.f, 100.f));
	this->shape.setPosition(0, 0);
}
Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
}
Player::~Player()
{
}
void Player::UpdateInput(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->direction.x = -1.f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->direction.x = 1.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->direction.y = -1.f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->direction.y = 1.f;
	}
	if (abs(this->direction.x) > 0 || abs(this->direction.y) > 0)
	{
		if (abs(this->direction.x) > 0 && abs(this->direction.y) > 0)
		{
			this->direction.x = 0.707 * this->direction.x;
			this->direction.y = 0.707 * this->direction.y;
		}
		this->animFrame += (this->moveSpeed * 0.02 * time);
		if (this->animFrame > this->animLenght)
		{
			this->animFrame -= this->animLenght;
		}
		this->shape.move(this->direction.x * this->moveSpeed * time, this->direction.y * this->moveSpeed * time);
		this->playerSprite.move(this->direction.x * this->moveSpeed * time, this->direction.y * this->moveSpeed * time);

		if (abs(this->direction.y) > abs(this->direction.x))
		{
			if (this->direction.y <= 0)
			{
				this->animSheetRow = 3;
			}
			else
			{
				this->animSheetRow = 0;
			}
		}
		else
		{
			if (this->direction.x >= 0)
			{
				this->animSheetRow = 2;
			}
			else
			{
				this->animSheetRow = 1;
			}
		}
		this->playerSprite.setTextureRect(IntRect(96 * int(animFrame), 96 *animSheetRow, 96, 96));
		std::cout << this->direction.x << " " << this->direction.y << std::endl;
		this->animSheetRow = 0;
		this->direction.x = 0;
		this->direction.y = 0;
	}
}
void Player::Update(float time)
{
	this->UpdateInput(time);
}

void Player::Render(RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->playerSprite);
}
