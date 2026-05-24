#pragma once
#include "Entity.h"
using namespace sf;
class Projectile : public Entity
{
public:
    Projectile(Vector2f position = Vector2f(0.f,0.f), Vector2f direction = Vector2f(0.f, 0.f), Entity* owner = nullptr);
    Projectile(const Projectile& ref, Vector2f direction, Vector2f position, Entity* owner);

    void Update(float time);
    void Render(RenderTarget* target);
    void CheckCollision(Entity* entity);
    void OnWallCollision(Entity* entity) override;

    float get_life_time() const { return life_time_; };
    void set_life_time(float time) { life_time_ = time; };
    Entity* get_owner() const { return owner_; };
    void set_owner(Entity* owner) { owner_ = owner; };

private:
    Entity* owner_;
    float life_time_ = 800.f;

    void updatePosition(float time) override;
    void updateVisuals(float time) override;

    void onDeath() override;
    void onCollision(Entity* entity);
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

