#include "Game.h"

bool DebugSettings::collidersVisuals = false;

void Game::InitVariables() {
    this->player_ = nullptr;
}
void Game::InitWindow() {
    this->window_resolution_ = Vector2u(1280, 720);
    this->view_.setCenter(0, 0);
    this->view_.setSize(Vector2f(window_resolution_));
    this->video_mode_.width = this->view_.getSize().x;
    this->video_mode_.height = this->view_.getSize().y;
    this->window_.create(this->video_mode_, "GameName", Style::Titlebar | Style::Close);
    this->window_.setVerticalSyncEnabled(true);

    this->room_texture_.loadFromFile("Textures/room.png");
    this->room_sprite_.setTexture(room_texture_);
    this->room_sprite_.setScale(0.5, 0.5);
    this->room_sprite_.setOrigin(room_sprite_.getLocalBounds().width / 2, room_sprite_.getLocalBounds().height / 2);
}
void Game::InitFonts()
{
    this->font.loadFromFile("Fonts/Anime Ace.ttf");
}

void Game::InitTexts()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(25);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setOutlineColor(sf::Color::Black);
    this->uiText.setString("NONE");
}

void Game::InitPlayer() {

    this->player_ = new Player(Vector2f(0, 0));
    EntityInteractionSystem::AddEntity(this->player_);
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
    this->enemy_ = new Enemy(Vector2f(200, 100), this->player_);
    EntityInteractionSystem::AddEntity(this->enemy_);
}

Game::Game() {
    this->InitVariables();
    this->InitWindow();
    this->InitFonts();
    this->InitTexts();
    this->InitPlayer();
    this->InitWalls();
    this->InitTester();
}
const bool Game::getWindowIsOpen() const {
    return this->window_.isOpen();
}
void Game::PollEvents() {
    while (this->window_.pollEvent(this->event_)) {
        switch (this->event_.type) {
        case Event::Closed:
            this->window_.close();
            break;
        case Event::KeyPressed:
            if (this->event_.key.code == Keyboard::Escape) {
                this->window_.close();
            }
            if (this->event_.key.code == Keyboard::P) {
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
    target.draw(this->uiText);
}

void Game::UpdateText()
{
    std::stringstream ss;

    ss << "Health:" << player_->get_health();

    this->uiText.setString(ss.str());
}

void Game::Render() {
    //view_.move(2, 2);
    this->window_.setView(view_);
    this->window_.clear(Color(150, 150, 150));
    this->window_.draw(room_sprite_);

    EntityInteractionSystem::RenderEntities(&this->window_);
    window_.setView(window_.getDefaultView());
    this->RenderText(this->window_);
    this->window_.display();
}
