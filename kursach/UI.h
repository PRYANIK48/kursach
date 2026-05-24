#pragma once

#include <SFML/Graphics.hpp>
#include "HUDData.h"

class UI
{
public:
    void Init();

    void Update(const HUDData& data)
    {
        hp_ = data.hp;
        damage_ = data.damage;
        speed_ = data.speed;
        firerate_ = data.firerate;
        roomsCleared_ = data.roomsCleared;
        hearts_.clear();
        UpdateText();
        for (int i = 0; i < hp_; ++i)
        {
            sf::Sprite heart;

            heart.setTexture(heart_texture_);

            heart.setPosition(
                0.f + i * 70.f, 0.f
            );

            heart.setScale(0.7f, 0.7f);

            hearts_.push_back(heart);
        }
    }

    void Render(sf::RenderWindow& window);

private:
    sf::Font font;

    sf::Text uiText;

    int hp_ = 0;
    int damage_ = 0;
    float speed_ = 0;
    int firerate_ = 0;
    int roomsCleared_ = 0;
    void RenderText(sf::RenderTarget& target);
    void UpdateText();
    void InitFonts();
    void InitTexts();
    sf::Texture heart_texture_;

    std::vector<sf::Sprite> hearts_;


};