#pragma once
#include <vector>
#include "Visuals.h"
#include "Projectile.h"
using namespace sf;
//сделать наследником класса от entity
class Player
{
public:
    Player(Vector2f position = Vector2f(0.f,0.f));

    void Update(float time);
    void Render(RenderTarget* target);

    void TryShoot();

    Vector2f get_position() const { return position_; };

private:
    Visuals visuals;
    Projectile projectileTemplate_;
    std::vector<Projectile*> projectiles;
    //нужно переписать движение с формулами ускорения и т.д под физику
    Vector2f moveDirection_;
    Vector2f facingDirection_;

    float basicShootCooldown_;
    float shootCooldown_;
    float move_speed_;
    float damage_;
    float maxHealth_;
    float health_;

    Vector2f position_;

    void shoot();
    void updateInput(float time);
    void updateProjectiles(float time);
    void updateProjectileTemplate();

    void InitVariables();
};

