#include "Game.h"

void Game::InitVariables(){
    this->window_ = nullptr;
}

void Game::InitWindow(){
    this->video_mode_.height = 600;
    this->video_mode_.width = 800;
    this->window_ = new RenderWindow(this->video_mode_, "GameName", Style::Titlebar | Style::Close);
    this->window_->setVerticalSyncEnabled(true);
}

Game::Game(){
    this->InitVariables();
    this->InitWindow();
}
const bool Game::getWindowIsOpen() const{
    return this->window_->isOpen();
}
void Game::PollEvents(){
    while (this->window_->pollEvent(this->event_)){
        switch (this->event_.type){
        case Event::Closed:
            this->window_->close();
            break;
        case Event::KeyPressed:
            if (this->event_.key.code == Keyboard::Escape){
                this->window_->close();
            }
        }
    }
}
void Game::Update(float time){
    this->PollEvents();

    this->player_.Update(time);
}

void Game::Render(){
    this->window_->clear(Color(150, 150, 150));

    this->player_.Render(this->window_);

    this->window_->display();
}
