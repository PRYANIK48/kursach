#pragma once
#include <vector>
#include "EntityInteractionSystem.h";
#include "Assets.h";
#include "DebugSettings.h"
#include "GMath.h"
#include "Visuals.h"
using namespace sf;
class Entity
{
public:

    Entity(Vector2f position = Vector2f(0.f, 0.f)) { position_ = position; };

    virtual void Update(float time) = 0;
    virtual void Render(RenderTarget* target);
    virtual void CheckCollision(Entity* entity);
    virtual void ApplyDamage(float damage);
    virtual void OnWallCollision(Entity* entity) {};

    virtual void PushOut(Entity* entity, float power = 1);
    void AddImpulse(Vector2f force) { velocity_ += force; };

    Visuals& get_visuals() { return visuals_; };
    const Visuals& get_visuals() const { return visuals_; };
    void set_visuals(Visuals visuals) { visuals_ = visuals; }
    RectangleShape& get_collider() { return collider_; };
    const RectangleShape& get_collider() const { return collider_; }
    void set_collider(RectangleShape collider) { collider_ = collider; }
    Vector2f get_position() const { return position_; };
    void set_position(Vector2f position) { position_ = position; };
    Vector2f get_velocity() const { return velocity_; };
    void set_velocity(Vector2f direction) { velocity_ = direction; }
    Vector2f get_move_direction() const { return moveDirection_; };
    void set_move_direction(Vector2f direction) { moveDirection_ = direction; }
    Vector2f get_facing_direction() const { return facingDirection_; };
    void set_facing_direction(Vector2f direction) { facingDirection_ = direction; }
    int get_render_layer() const { return render_layer_; };
    void set_render_layer(int layer) { render_layer_ = layer; }
    float get_friction() const { return friction_; };
    void set_friction(float friction) { friction_ = friction; }
    float get_move_speed() const { return move_speed_; };
    void set_move_speed(float speed) { move_speed_ = speed; }
    float get_damage() const { return damage_; };
    void set_damage(float damage) { damage_ = damage; };
    float get_maxHealth() const { return maxHealth_; };
    void set_maxHealth(float health) { maxHealth_ = health; };
    float get_health() const { return health_; };
    void set_health(float health);
    bool IsDead() const { return is_dead_; };
    void set_dead();
    bool IsReadyToDelete() const { return ready_to_delete_; };
    void set_ready_to_delete() { ready_to_delete_ = true; };

private:
    Visuals visuals_;
    RectangleShape collider_;
    Vector2f position_;
    Vector2f velocity_ = Vector2f();
    Vector2f moveDirection_ = Vector2f();
    Vector2f facingDirection_ = Vector2f(0.f,1.f);

    int render_layer_ = 0;

    float friction_ = 0.5f;
    float move_speed_ = 0.f;
    float damage_ = 0.f;
    float maxHealth_ = 0.f;
    float health_ = 0.f;

    bool is_dead_ = false;
    bool ready_to_delete_ = false;

    virtual void updatePosition(float time);
    virtual void updateVisuals(float time);

    virtual void onDeath();
    virtual void onCollision(Entity* entity) = 0;
    virtual void InitVariables() = 0;
    virtual void InitVisuals() = 0;
    virtual void InitCollider() = 0;
};

