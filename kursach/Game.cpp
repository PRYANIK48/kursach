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

    room_texture_.loadFromFile("Textures/room.png");
    room_sprite_.setTexture(room_texture_);
    room_sprite_.setScale(0.5, 0.5);
    room_sprite_.setOrigin(room_sprite_.getLocalBounds().width / 2, room_sprite_.getLocalBounds().height / 2);
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

void Game::InitPlayer() {

    player_ = new Player(Vector2f(0, 0));
    EntityInteractionSystem::AddEntity(player_);
}

void Game::InitWalls()
{
    Wall* wall = new Wall(Vector2f(-300, 0), Vector2f(80, 400));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(Vector2f(300, 0), Vector2f(80, 400));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(Vector2f(0, -200), Vector2f(700, 80));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(Vector2f(0, 200), Vector2f(700, 80));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);
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
    InitWalls();
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
    this->PollEvents();
    this->UpdateText();
    EntityInteractionSystem::UpdateEntities(time);
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
    std::cout << "rend" << std::endl;
    EntityInteractionSystem::RenderEntities(&window_);
    window_.setView(window_.getDefaultView());
    RenderText(window_);
    window_.display();
}
