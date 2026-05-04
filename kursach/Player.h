#pragma once
#include <vector>
#include "Visuals.h"
#include "Projectile.h"
using namespace sf;

class Player : public Entity
{
public:
    Player(Vector2f position = Vector2f(0.f,0.f));

    void Update(float time);
    void Render(RenderTarget* target);
    void CheckCollision(Entity* entity);

    void TryShoot();

private:
    Projectile projectileTemplate_;
    //нужно переписать движение с формулами ускорения и т.д под физику

    float basicShootCooldown_;
    float shootCooldown_;

    void shoot();
    void updateInput(float time);
    void updatePosition(float time);
    void updateVisuals(float time);
    void updateProjectileTemplate();

    void onCollision(Entity* entity);
    void InitVariables();
    void InitCollider();
};

