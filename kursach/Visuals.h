#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
class Visuals
{
public:
    Visuals(Vector2f position = Vector2f(0.f,0.f));
    Visuals(const Visuals& ref);

    void SetPosition(Vector2f position);
    void UpdateSprite() { sprite_.setTextureRect(IntRect(frame_h_ * int(anim_frame_), frame_w_ * anim_sheet_row_, frame_w_, frame_h_)); };
    void Render(RenderTarget* target) { 
        target->draw(sprite_);
    };
    Texture& get_sheet() { return sheet_; };
    Sprite& get_sprite() { return sprite_; };
    Vector2f get_visuals_position() const { return visuals_position_; };
    void set_visuals_position(Vector2f position) { visuals_position_ = position; };
    float get_anim_frame() const { return anim_frame_; };
    void set_anim_frame(float x) { anim_frame_ = x; };
    int get_anim_sheet_row() const { return anim_sheet_row_; };
    void set_anim_sheet_row(int row) { anim_sheet_row_ = row; };
    int get_frame_w() const { return frame_w_; };
    void set_frame_w(int pixels) { frame_w_ = pixels; };
    int get_frame_h() const { return frame_h_; };
    void set_frame_h(int pixels) { frame_h_ = pixels; };
    int get_anim_length() const { return anim_length_; };
    void set_anim_length(int length) { anim_length_ = length; };
    void printInfo() {};

    Visuals& operator=(const Visuals& ref);

private:
    Texture sheet_;
    Sprite sprite_;
    Vector2f visuals_position_;
    float anim_frame_ = 0.f;
    float scale = 0.5f;
    int frame_w_ = 140;
    int frame_h_ = 140;
    int anim_sheet_row_ = 0;
    int anim_length_ = 3;

    void InitVariables();
};

