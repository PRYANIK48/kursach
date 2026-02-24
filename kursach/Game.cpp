#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new RenderWindow(this->videoMode, "GameName", Style::Titlebar | Style::Close);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}
Game::~Game()
{
	delete this->window;
}
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}
void Game::PollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->window->close();
			}
		}
	}
}
void Game::Update()
{
	this->PollEvents();
}

void Game::Render()
{
	this->window->clear(Color(150, 150, 150));
	this->window->display();
}
