#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
//сделать базовым
class Visuals
{
public:
    Visuals(Vector2f position = Vector2f(0.f,0.f));
    Visuals(const Visuals& ref);

    void SetPosition(Vector2f position);
    void UpdateSprite() { sprite_.setTextureRect(IntRect(frame_h * int(anim_frame_), frame_w * anim_sheet_row_, frame_w, frame_h)); };
    void Render(RenderTarget* target) { 
        target->draw(sprite_);
    };
    Sprite get_sprite() const { return sprite_; };
    float get_anim_frame() const { return anim_frame_; };
    void set_anim_frame(float x) { anim_frame_ = x; };
    Vector2f get_visuals_position() const { return visuals_position_; };
    void set_visuals_position(Vector2f position) { visuals_position_ = position; };
    int get_anim_sheet_row() const { return anim_sheet_row_; };
    void set_anim_sheet_row(int row) { anim_sheet_row_ = row; };
    int get_anim_length() const { return anim_length_; };
    void set_anim_length(int length) { anim_length_ = length; };
    void printInfo() {};

    Visuals& operator=(const Visuals& ref);

private:
    Texture sheet_;
    Sprite sprite_;
    float scale = 0.5f;
    int frame_w = 140;
    int frame_h = 140;
    float anim_frame_ = 0.f;
    Vector2f visuals_position_;
    int anim_sheet_row_ = 0;
    int anim_length_ = 3;

    void InitVariables();
};

