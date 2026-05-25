#include "UI.h"
#include <sstream>

void UI::Init()
{
    heart_texture_.loadFromFile(
        "Textures/heart.png"
    );
    InitFonts();
    InitTexts();
}

void UI::InitFonts()
{
    font.loadFromFile("Fonts/Anime Ace.ttf");
    deathScreenFont.loadFromFile("Fonts/Anime Ace.ttf");
}

void UI::InitTexts()
{
    uiText.setFont(font);
    uiText.setCharacterSize(25);
    uiText.setFillColor(sf::Color::White);
    uiText.setOutlineColor(sf::Color::Black);
    uiText.setString("NONE");
    uiText.setPosition(
        20.f, 80.f
    );
    deathScreenText.setFont(deathScreenFont);
    deathScreenText.setCharacterSize(70);
    deathScreenText.setFillColor(sf::Color::Red);
    deathScreenText.setOutlineColor(sf::Color::Black);
    deathScreenText.setString("You died! R to restart");
    deathScreenText.setPosition(
        100.f, 300.f
    );
}

void UI::Render(sf::RenderWindow& window)
{
    window.setView(
        window.getDefaultView()
    );
    RenderText(window);
    for (auto& heart : hearts_)
    {
        window.draw(heart);
    }
}

void UI::RenderText(sf::RenderTarget& target)
{
    target.draw(uiText);
    if (deathScreen_)
    {
        target.draw(deathScreenText);
    }
}

void UI::UpdateText()
{
    std::stringstream ss;

    ss << "Damage: " << damage_ << "\n" << "Firerate: " << firerate_ / 500 << "\n" << "Walkspeed: " << speed_ * 5
        << "\n\n\n\n\n\n\n\n" << "WASD - walk" << "\n" << "F - fire" << "\n" << "R - restart" << "\n\n\n\n\n\n\n\n" << "Rooms cleared : " << roomsCleared_;

    uiText.setString(ss.str());
}
