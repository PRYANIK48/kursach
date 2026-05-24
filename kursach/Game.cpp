#include "Game.h"

bool DebugSettings::collidersVisuals = false;

void Game::InitVariables() {
    player_ = nullptr;
}
void Game::InitWindow() {
    window_resolution_ = Vector2u(1280, 720);
    view_.setCenter(0, 0);
    view_.setSize(Vector2f(window_resolution_));
    video_mode_.width = view_.getSize().x;
    video_mode_.height = view_.getSize().y;
    window_.create(video_mode_, "GameName", Style::Titlebar | Style::Close);
    window_.setVerticalSyncEnabled(true);
}


HUDData Game::GetHUDData() const
{
    HUDData data;

    data.hp = player_->get_health();
    data.max_hp = player_->get_health();
    data.damage = player_->get_damage();
    data.firerate = player_->get_basicShootCooldown();
    data.speed = player_->get_move_speed();
    data.roomsCleared = room_.get_room_number_();
    return data;
}



void Game::InitRoom()
{
    RoomTemplates::InitTemplates();
    room_.GenerateRoom(player_, Vector2f(0.f, 0.f), 0);
}

void Game::InitPlayer() {

    player_ = new Player(Vector2f(0, 0));
    EntityInteractionSystem::AddEntity(player_);
}

void Game::InitTester()
{
    enemy_ = new Enemy(Vector2f(200, 100), player_);
    EntityInteractionSystem::AddEntity(enemy_);
}

Game::Game() {
    InitVariables();
    InitWindow();
    InitPlayer();
    InitRoom();
    InitTester();
    ui_.Init();
}
const bool Game::getWindowIsOpen() const {
    return window_.isOpen();
}
void Game::PollEvents() {
    while (window_.pollEvent(event_)) {
        switch (event_.type) {
        case Event::Closed:
            window_.close();
            break;
        case Event::KeyPressed:
            if (event_.key.code == Keyboard::Escape) {
                window_.close();
            }
            if (event_.key.code == Keyboard::P) {
                DebugSettings::toggleCollidersVisuals();
            }
        }
    }
}
void Game::Update(float time) {
    PollEvents();
    ui_.Update(GetHUDData());
    EntityInteractionSystem::UpdateEntities(time);
    room_.CheckEnemies();
}

void Game::Render() {
    //view_.move(2, 2);
    window_.setView(view_);
    window_.clear(Color(0, 0, 0));
    //window_.draw(room_sprite_);
    room_.Render(&window_);
    EntityInteractionSystem::RenderEntities(&window_);
    ui_.Render(window_);
    window_.setView(window_.getDefaultView());
    window_.display();
}
