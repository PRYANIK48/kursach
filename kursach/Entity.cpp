#include "Entity.h"
#include <iostream>
void Entity::InitVariables() {
    visuals_ = Visuals(position_);
    //костыль
    visuals_.InitTexture();
    this->move_speed_ = 0.5f;
    this->damage_ = 1.f;
    this->maxHealth_ = 10.f;
    this->health_ = maxHealth_;
    visuals_.set_anim_sheet_row(1);
    this->facingDirection_.x = 0.f;
    this->facingDirection_.y = 1.f;
}
void Entity::InitCollider()
{
    this->collider_.setFillColor(Color(100, 200, 100, 80));
    this->collider_.setOutlineColor(Color(50, 255, 50, 200));
    this->collider_.setOutlineThickness(2.f);
    this->collider_.setSize(Vector2f(30 * visuals_.get_sprite().getScale().x, 30 * visuals_.get_sprite().getScale().x));
    this->collider_.setPosition(visuals_.get_visuals_position());
}
Entity::Entity(Vector2f position) {
    this->position_ = position;
    this->InitVariables();
    this->InitCollider();
}
void Entity::Update(float time) {
    this->updateInput(time);
}

void Entity::Render(RenderTarget* target) {
    visuals_.printInfo();
    visuals_.Render(target);
    //test
    target->draw(collider_);
}
void Entity::updateInput(float time) {
    if (Keyboard::isKeyPressed(Keyboard::E))
    {
        std::cout << "e" << std::endl;
    }

    this->visuals_.UpdateSprite();
    this->moveDirection_.x = 0;
    this->moveDirection_.y = 0;
}