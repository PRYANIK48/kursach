#pragma once
#include "Visuals.h"
#include "Entity.h"
using namespace sf;
class Projectile : public Entity
{
public:
    Projectile(Vector2f position = Vector2f(0.f,0.f), Vector2f direction = Vector2f(0.f, 0.f));
    Projectile(const Projectile& ref, Vector2f direction, Vector2f position);

    void Update(float time);
    void Render(RenderTarget* target);
    void CheckCollision(Entity* entity);


    float get_life_time() const { return life_time_; };
    void set_life_time(float time) {life_time_ = time; };

private:
    float life_time_ = 300.f;

    void updateInput(float time);

    void onCollision(Entity* entity);
    void InitVariables();
    void InitCollider();
    void updateVisuals(float time);
};

