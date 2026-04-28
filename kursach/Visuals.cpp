#include "Visuals.h"
#include <iostream>
void Visuals::InitVariables() {
    this->sheet_.loadFromFile("Textures/player.png");
    this->sprite_.setTexture(sheet_);
    this->sprite_.setPosition(visuals_position_);
    this->sprite_.setTextureRect(IntRect(0, frame_w, frame_w, frame_h));
    this->sprite_.setScale(scale, scale);
    //this->sprite_.setOrigin(frame_w / 2, frame_h / 2);
}
Visuals::Visuals(Vector2f position) {
    this->visuals_position_ = position;
    this->InitVariables();
}

Visuals::Visuals(const Visuals& ref) {
    this->sheet_ = ref.sheet_;
    this->sprite_ = ref.sprite_;
    this->scale = ref.scale;
    this->frame_w = ref.frame_w;
    this->frame_h = ref.frame_h;
    this->anim_frame_ = ref.anim_frame_;
    this->visuals_position_ = ref.visuals_position_;
    this->anim_sheet_row_ = ref.anim_sheet_row_;
    this->anim_length_ = ref.anim_length_;
}

void Visuals::SetPosition(Vector2f position) {
    this->sprite_.setTexture(sheet_);
    visuals_position_ = position;
    sprite_.setPosition(visuals_position_);
}
