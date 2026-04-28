#include "Player.h"
#include <iostream>
void Player::InitVariables() {
    visuals = Visuals(position_);
    //костыль
    visuals.InitTexture();
    this->basicShootCooldown_ = 10.f;
    this->shootCooldown_ = 0.f;
    this->move_speed_ = 0.5f;
    this->damage_ = 1.f;
    this->maxHealth_ = 10.f;
    this->health_ = maxHealth_;
    visuals.set_anim_sheet_row(1);
    this->facingDirection_.x = 0.f;
    this->facingDirection_.y = 1.f;
    updateProjectileTemplate();
}
Player::Player(Vector2f position) {
    this->position_ = position;
    this->InitVariables();
}
void Player::Update(float time) {
    this->updateInput(time);
    this->updateProjectiles(time);
    shootCooldown_ -= 0.05f * time;
}

void Player::Render(RenderTarget* target) {
    visuals.printInfo();
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->Render(target);
    }
    visuals.Render(target);
}

void Player::TryShoot()
{
    if (shootCooldown_ <= 0.f)
    {
        shoot();
        shootCooldown_ = basicShootCooldown_;
    }
}

void Player::shoot()
{
    projectiles.push_back(new Projectile(projectileTemplate_, facingDirection_, position_));
}
void Player::updateInput(float time) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        this->moveDirection_.x = -1.f;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        this->moveDirection_.x = 1.f;
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        this->moveDirection_.y = -1.f;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S)) {
        this->moveDirection_.y = 1.f;
    }
    if (abs(this->moveDirection_.x) > 0 || abs(this->moveDirection_.y) > 0) {
        if (abs(this->moveDirection_.x) > 0 && abs(this->moveDirection_.y) > 0) {
            //сделать нормальную нормализацию
            this->moveDirection_.x = 0.707f * this->moveDirection_.x;
            this->moveDirection_.y = 0.707f * this->moveDirection_.y;
        }
        visuals.set_anim_frame(visuals.get_anim_frame() + this->move_speed_ * 0.04f * time);
        if (visuals.get_anim_frame() > visuals.get_anim_length()) {
            visuals.set_anim_frame(visuals.get_anim_frame() - visuals.get_anim_length());
        }
        this->position_.x += this->moveDirection_.x * this->move_speed_ * time;
        this->position_.y += this->moveDirection_.y * this->move_speed_ * time;
        visuals.SetPosition(position_);

        if (abs(this->moveDirection_.y) > abs(this->moveDirection_.x)) {
            if (this->moveDirection_.y <= 0) {
                this->facingDirection_.x = 0;
                this->facingDirection_.y = -1;
                visuals.set_anim_sheet_row(0);
            }
            else {
                visuals.set_anim_sheet_row(1);
                this->facingDirection_.x = 0;
                this->facingDirection_.y = 1;
            }
        }
        else {
            if (this->moveDirection_.x >= 0) {
                this->facingDirection_.x = 1;
                this->facingDirection_.y = 0;
                visuals.set_anim_sheet_row(3);
            }
            else {
                this->facingDirection_.x = -1;
                this->facingDirection_.y = 0;
                visuals.set_anim_sheet_row(2);
            }
        }
    }
    else {
        visuals.set_anim_frame(0);
    }

    if (Keyboard::isKeyPressed(Keyboard::F))
    {
        TryShoot();
    }

    this->visuals.UpdateSprite();
    this->moveDirection_.x = 0;
    this->moveDirection_.y = 0;
}
void Player::updateProjectiles(float time)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        (*it)->Update(time);
        if ((*it)->IsDead()) {
            delete* it;
            it = projectiles.erase(it);
        }
        else {
            ++it;
        }
    }
}
void Player::updateProjectileTemplate()
{
    projectileTemplate_.set_damage(damage_);
    projectileTemplate_.set_move_speed(move_speed_ * 2);
    projectileTemplate_.set_life_time(600.f);
}
