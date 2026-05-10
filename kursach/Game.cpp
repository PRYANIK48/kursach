#include "Game.h"
#include <iostream>
#include "EntityInteractionSystem.h"
//#include "DebugSettings.h"

void Game::InitVariables() {
    this->window_ = nullptr;
    this->player_ = nullptr;
}
void Game::InitWindow() {
    this->video_mode_.width = 16 * 75;
    this->video_mode_.height = 9 * 75;
    this->window_ = new RenderWindow(this->video_mode_, "GameName", Style::Titlebar | Style::Close);
    this->window_->setVerticalSyncEnabled(true);

    this->room_texture_.loadFromFile("Textures/room.png");
    this->room_sprite_.setTexture(room_texture_);
    this->room_sprite_.setScale(0.5, 0.5);
    this->room_sprite_.setPosition((this->video_mode_.width - (room_texture_.getSize().x) * room_sprite_.getScale().x) / 2, (this->video_mode_.height - (room_texture_.getSize().y) * room_sprite_.getScale().y) / 2);

}
void Game::InitPlayer() {

    this->player_ = new Player(Vector2f(this->video_mode_.width / 2, this->video_mode_.height / 2));
    EntityInteractionSystem::AddEntity(this->player_);
}

void Game::InitTester()
{
    this->enemy_ = new Enemy(Vector2f(this->video_mode_.width / 2 + 200, this->video_mode_.height / 2 + 100));
    EntityInteractionSystem::AddEntity(this->enemy_);
}

Game::Game() {
    //DebugSettings::collidersVisuals = true;
    this->InitVariables();
    this->InitWindow();
    this->InitPlayer();
    this->InitTester();
}
const bool Game::getWindowIsOpen() const {
    return this->window_->isOpen();
}
void Game::PollEvents() {
    while (this->window_->pollEvent(this->event_)) {
        switch (this->event_.type) {
        case Event::Closed:
            this->window_->close();
            break;
        case Event::KeyPressed:
            if (this->event_.key.code == Keyboard::Escape) {
                this->window_->close();
            }
        }
    }
}
void Game::Update(float time) {
    this->PollEvents();
    EntityInteractionSystem::UpdateEntities(time);
}

void Game::Render() {
    this->window_->clear(Color(150, 150, 150));
    
    this->window_->draw(room_sprite_);

    EntityInteractionSystem::RenderEntities(this->window_);

    this->window_->display();
}
