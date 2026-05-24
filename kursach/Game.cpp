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
void Game::InitFonts()
{
    font.loadFromFile("Fonts/Anime Ace.ttf");
}

void Game::InitTexts()
{
    uiText.setFont(font);
    uiText.setCharacterSize(25);
    uiText.setFillColor(sf::Color::White);
    uiText.setOutlineColor(sf::Color::Black);
    uiText.setString("NONE");
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
    InitFonts();
    InitTexts();
    InitPlayer();
    InitRoom();
    InitTester();
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
    UpdateText();
    EntityInteractionSystem::UpdateEntities(time);
    room_.CheckEnemies();
}
void Game::RenderText(sf::RenderTarget& target)
{
    target.draw(uiText);
}

void Game::UpdateText()
{
    std::stringstream ss;

    ss << "Health:" << player_->get_health();

    uiText.setString(ss.str());
}

void Game::Render() {
    //view_.move(2, 2);
    window_.setView(view_);
    window_.clear(Color(150, 150, 150));
    //window_.draw(room_sprite_);
    room_.Render(&window_);
    EntityInteractionSystem::RenderEntities(&window_);
    window_.setView(window_.getDefaultView());
    RenderText(window_);
    window_.display();
}
