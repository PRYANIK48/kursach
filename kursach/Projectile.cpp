#include "Projectile.h"
#include <iostream>
void Projectile::InitVariables() {
    visuals_ = Visuals(position_);
    //костыль
    visuals_.InitTexture();
    this->move_speed_ = 0.5f;
}
void Projectile::InitCollider()
{
    this->collider_.setFillColor(Color(100, 200, 100, 80));
    this->collider_.setOutlineColor(Color(50, 255, 50, 200));
    this->collider_.setOutlineThickness(2.f);
    this->collider_.setSize(Vector2f(30 * visuals_.get_sprite().getScale().x, 30 * visuals_.get_sprite().getScale().x));
    this->collider_.setPosition(visuals_.get_visuals_position());
}
Projectile::Projectile(Vector2f position, Vector2f direction) {
    this->position_ = position;
    this->direction_ = direction;
    this->InitVariables();
    this->InitCollider();
}
Projectile::Projectile(const Projectile& ref, Vector2f direction, Vector2f position)
{
    visuals_ = Visuals(position_);
    //костыль
    visuals_.InitTexture();
    this->damage_ = ref.damage_;
    this->move_speed_ = ref.move_speed_;
    this->position_ = position;
    this->life_time_ = ref.life_time_;
    this->direction_ = direction;
    this->collider_ = ref.collider_;
}
void Projectile::updateInput(float time) {
}
void Projectile::Update(float time) {
    this->updateInput(time);
    updateVisuals(time);
}

void Projectile::updateVisuals(float time)
{
    if (life_time_ < 0)
    {
        isDead_ = true;
    }
    life_time_ -= time;
    visuals_.set_anim_frame(visuals_.get_anim_frame() + this->move_speed_ * 0.04f * time);
    if (visuals_.get_anim_frame() > visuals_.get_anim_length()) {
        visuals_.set_anim_frame(visuals_.get_anim_frame() - visuals_.get_anim_length());
    }
    this->position_.x += this->direction_.x * this->move_speed_ * time;
    this->position_.y += this->direction_.y * this->move_speed_ * time;
    visuals_.SetPosition(position_);

    if (abs(this->direction_.y) > abs(this->direction_.x)) {
        if (this->direction_.y <= 0) {
            visuals_.set_anim_sheet_row(0);
        }
        else {
            visuals_.set_anim_sheet_row(1);
        }
    }
    else {
        if (this->direction_.x >= 0) {
            visuals_.set_anim_sheet_row(3);
        }
        else {
            visuals_.set_anim_sheet_row(2);
        }
    }

    this->visuals_.UpdateSprite();
    this->collider_.setPosition(visuals_.get_visuals_position());
}

void Projectile::Render(RenderTarget* target) {
    visuals_.printInfo();
    visuals_.Render(target);
    //test
    target->draw(collider_);
}