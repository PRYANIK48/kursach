#pragma once
#include "Visuals.h"
using namespace sf;
//сделать базовым и наследовать от entity
class Projectile
{
public:
    Projectile(Vector2f position = Vector2f(0.f,0.f), Vector2f direction = Vector2f(0.f, 0.f));
    Projectile(const Projectile& ref, Vector2f direction, Vector2f position);

    void updateInput(float time);
    void Update(float time);
    void updateVisuals(float time);
    void Render(RenderTarget* target);


    bool IsDead() const { return isDead_; };
    Vector2f get_position() const { return position_; };
    float get_damage() const { return damage_; };
    void set_damage(float damage) { damage_ = damage; };
    float get_move_speed() const { return move_speed_; };
    void set_move_speed(float speed) { move_speed_ = speed; };
    float get_life_time() const { return life_time_; };
    void set_life_time(float time) {life_time_ = time; };

private:
    Visuals visuals_;
    RectangleShape collider_;
    Vector2f direction_;
    Vector2f position_;
    float damage_ = 0.f;
    float move_speed_ = 0.f;
    float life_time_ = 300.f;
    bool isDead_ = false;

    void InitVariables();
    void InitCollider();
};

