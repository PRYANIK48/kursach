#include "Visuals.h"
#include <iostream>
void Visuals::InitVariables() {
    this->sheet_.loadFromFile("Textures/player.png");
    this->sprite_.setTexture(sheet_);
    this->sprite_.setTextureRect(IntRect(0, 0, frame_w_, frame_h_));
    this->sprite_.setPosition(visuals_position_);
    this->sprite_.setScale(scale, scale);
}
Visuals::Visuals(Vector2f position) {
    this->visuals_position_ = position;
    this->InitVariables();
}

Visuals::Visuals(const Visuals& ref) {
    this->sheet_ = ref.sheet_;
    this->sprite_ = ref.sprite_;
    this->scale = ref.scale;
    this->frame_w_ = ref.frame_w_;
    this->frame_h_ = ref.frame_h_;
    this->anim_frame_ = ref.anim_frame_;
    this->visuals_position_ = ref.visuals_position_;
    this->anim_sheet_row_ = ref.anim_sheet_row_;
    this->anim_length_ = ref.anim_length_;
    this->sprite_.setTexture(this->sheet_);
}

void Visuals::SetPosition(Vector2f position) {
    visuals_position_ = position;
    sprite_.setPosition(visuals_position_);
}
Visuals& Visuals::operator=(const Visuals& ref) {
    if (this == &ref)
        return *this;

    this->sheet_ = ref.sheet_;
    this->sprite_ = ref.sprite_;
    this->scale = ref.scale;
    this->frame_w_ = ref.frame_w_;
    this->frame_h_ = ref.frame_h_;
    this->anim_frame_ = ref.anim_frame_;
    this->visuals_position_ = ref.visuals_position_;
    this->anim_sheet_row_ = ref.anim_sheet_row_;
    this->anim_length_ = ref.anim_length_;
    this->sprite_.setTexture(this->sheet_);

    return *this;
}
