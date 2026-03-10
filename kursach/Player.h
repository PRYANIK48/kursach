#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class Player
{
public:
    Player(float x = 0.f, float y = 0.f);

    void UpdateInput(float time);
    void Update(float time);
    void Render(RenderTarget* target);

    //void get_ss() const { return x; };

private:
    Texture player_sheet_;
    Sprite player_sprite_;
    RectangleShape shape_;

    Vector2f direction_;
    float move_speed_;
    float anim_frame_ = 0.f;
    int anim_sheet_row_ = 0;
    int anim_lenght_ = 3;

    void InitVariables();
    void InitShape();
};

