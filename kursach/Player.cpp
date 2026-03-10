#include "Player.h"
#include <iostream>
void Player::InitVariables() {
    this->player_sheet_.loadFromFile("Textures/player.png");
    this->player_sprite_.setTexture(player_sheet_);
    this->player_sprite_.setPosition(position_x_, position_y_);
    this->player_sprite_.setTextureRect(IntRect(0, 140, 140, 140));
    this->player_sprite_.setScale(0.5, 0.5);
    this->move_speed_ = 0.5;
}
void Player::InitShape() {
    this->shape_.setFillColor(Color(220, 200, 200));
    this->shape_.setSize(Vector2f(100.f, 100.f));
    this->shape_.setPosition(position_x_, position_y_);
}
Player::Player(float x, float y) {
    this->position_x_ = x;
    this->position_y_ = y;
    this->InitVariables();
    this->InitShape();
}
void Player::UpdateInput(float time) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        this->direction_.x = -1.f;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        this->direction_.x = 1.f;
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        this->direction_.y = -1.f;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S)) {
        this->direction_.y = 1.f;
    }
    if (abs(this->direction_.x) > 0 || abs(this->direction_.y) > 0) {
        if (abs(this->direction_.x) > 0 && abs(this->direction_.y) > 0) {
            this->direction_.x = 0.707 * this->direction_.x;
            this->direction_.y = 0.707 * this->direction_.y;
        }
        this->anim_frame_ += (this->move_speed_ * 0.04 * time);
        if (this->anim_frame_ > this->anim_lenght_) {
            this->anim_frame_ -= this->anim_lenght_;
        }
        this->position_x_ += this->direction_.x * this->move_speed_ * time;
        this->position_y_ += this->direction_.y * this->move_speed_ * time;
        this->shape_.setPosition(position_x_, position_y_);
        this->player_sprite_.setPosition(position_x_, position_y_);

        if (abs(this->direction_.y) > abs(this->direction_.x)) {
            if (this->direction_.y <= 0) {
                this->anim_sheet_row_ = 0;
            }
            else {
                this->anim_sheet_row_ = 1;
            }
        }
        else {
            if (this->direction_.x >= 0) {
                this->anim_sheet_row_ = 3;
            }
            else {
                this->anim_sheet_row_ = 2;
            }
        }
        std::cout << this->direction_.x << " " << this->direction_.y << std::endl;
    }
    else {
        anim_frame_ = 0;
    }
    this->player_sprite_.setTextureRect(IntRect(140 * int(anim_frame_), 140 * anim_sheet_row_, 140, 140));
    this->direction_.x = 0;
    this->direction_.y = 0;
}
void Player::Update(float time) {
    this->UpdateInput(time);
}

void Player::Render(RenderTarget* target) {
    //target->draw(this->shape_);
    target->draw(this->player_sprite_);
}
