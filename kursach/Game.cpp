#include "Game.h"

bool DebugSettings::collidersVisuals = false;

void Game::InitVariables() {
    player_ = nullptr;
}
void Game::InitTextures()
{
    Assets::LoadTexture("chainmal", "Textures/chainmal.png");
    Assets::LoadTexture("door", "Textures/door.png");
    Assets::LoadTexture("heart", "Textures/heart.png");
    Assets::LoadTexture("ignatiy projectile", "Textures/ignatiy projectile.png");
    Assets::LoadTexture("lizard projectile", "Textures/lizard projectile.png");
    Assets::LoadTexture("lizard", "Textures/lizard.png");
    Assets::LoadTexture("pit", "Textures/pit.png");
    Assets::LoadTexture("player", "Textures/player.png");
    Assets::LoadTexture("rock", "Textures/rock.png");
    Assets::LoadTexture("room1floor", "Textures/room1floor.png");
    Assets::LoadTexture("room1walls", "Textures/room1walls.png");
    Assets::LoadTexture("test", "Textures/test.png");
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
    room_.InitRoom();
    RoomTemplates::InitTemplates();
    room_.GenerateRoom(player_, Vector2f(0.f, 0.f), 0);
}

void Game::InitPlayer() {

    player_ = new Player(Vector2f(0, 0));
    EntityInteractionSystem::AddEntity(player_);
}

Game::Game() {
    InitVariables();
    InitWindow();
    InitTextures();
    InitPlayer();
    InitRoom();
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
            if (event_.key.code == Keyboard::R) {
                ui_.set_deathScreen(false);
                player_->set_ready_to_delete();
                room_.ClearRoom();
                InitPlayer();
                InitRoom();
                view_.setCenter(room_.get_position());
            }
        }
    }
}
void Game::Update(float time) {
    PollEvents();
    EntityInteractionSystem::UpdateEntities(time);
    if (player_->IsDead())
    {
        ui_.set_deathScreen(true);
    }
    room_.CheckEnemies();
    Door* enteredDoor = room_.GetEnteredDoor();
    if (enteredDoor)
    {
        enteredDoor->set_entered(false);
        room_.GenerateRoom(player_, room_.get_position() + ((enteredDoor->get_position() - room_.get_position()) * 2.f) + enteredDoor->get_facing_direction() * 100.f);
        view_.setCenter(room_.get_position());
    }
    ui_.Update(GetHUDData());
}

void Game::Render() {
    window_.setView(view_);
    window_.clear(Color(0, 0, 0));
    room_.Render(&window_);
    EntityInteractionSystem::RenderEntities(&window_);
    ui_.Render(window_);
    window_.setView(window_.getDefaultView());
    window_.display();
}
