#include "Game.h"
#include "map.h"
#include <iostream>

void Game::initVariables()
{
    map_image.loadFromFile("Textures/map.png");//загружаем файл для карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой
    s_map.setTexture(map);//заливаем текстуру спрайтом
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new RenderWindow(this->videoMode, "GameName", Style::Titlebar | Style::Close);
    this->window->setVerticalSyncEnabled(true);
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
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape)
            {
                this->window->close();
            }
        }
    }
}
void Game::Update(float time)
{
    this->PollEvents();

    this->player.Update(time);
}

void Game::Render()
{
    this->window->clear(Color(150, 150, 150));

    std::cout << TileMap[0][0] << std::endl;
    for (int i = 0; i < height_map; i++)
    {

        for (int j = 0; j < width_map; j++)
        {
            if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
            if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
            if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));


            s_map.setPosition(j * 32, i * 32);

            this->window->draw(s_map);
        }
    }
    this->player.Render(this->window);

    this->window->display();
}
