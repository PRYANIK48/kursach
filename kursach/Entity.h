#pragma once
#include <vector>
#include "EntityInteractionSystem.h";
#include "Visuals.h"
using namespace sf;
class Entity
{
public:

    virtual ~Entity() {};

    virtual void Update(float time) = 0;
    virtual void Render(RenderTarget* target) = 0;
    virtual void CheckCollision(Entity* entity) = 0;

    Visuals& get_visuals() { return visuals_; };
    void set_visuals(Visuals visuals) { visuals_ = visuals; }
    RectangleShape& get_collider() { return collider_; };
    const RectangleShape& get_collider() const { return collider_; }
    void set_collider(RectangleShape collider) { collider_ = collider; }
    Vector2f get_position() const { return position_; };
    void set_position(Vector2f position)  { position_ = position; };
    Vector2f get_move_direction() const { return moveDirection_; };
    void set_move_direction(Vector2f direction) { moveDirection_ = direction; }
    Vector2f get_facing_direction() const { return facingDirection_; };
    void set_facing_direction(Vector2f direction) { facingDirection_ = direction; }
    float get_move_speed() const { return move_speed_; };
    void set_move_speed(float speed) { move_speed_ = speed; }
    float get_damage() const { return damage_; };
    void set_damage(float damage) { damage_ = damage; };
    float get_maxHealth() const { return maxHealth_; };
    void set_maxHealth(float health) { maxHealth_ = health; };
    float get_health() const { return health_; };
    void set_health(float health) { health_ = health; };
    bool IsDead() const { return isDead_; };
    void set_dead() { isDead_ = true; };

private:
    
    Visuals visuals_;
    RectangleShape collider_;
    Vector2f position_;
    Vector2f moveDirection_;
    Vector2f facingDirection_;

    float move_speed_ = 0;
    float damage_ = 0;
    float maxHealth_ = 0;
    float health_ = 0;

    bool isDead_ = false;

    virtual void updateInput(float time) = 0;
    virtual void onCollision(Entity* entity) = 0;
    virtual void InitVariables() = 0;
    virtual void InitCollider() = 0;
};

