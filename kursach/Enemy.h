#pragma once
#include "Entity.h"
#include "Projectile.h"
class Enemy : public Entity
{
public:
    Enemy(Vector2f position = Vector2f(0.f, 0.f), Entity* target = nullptr);

    void Update(float time) override;
    void Render(RenderTarget* target) override;

    void TryShoot();

    Entity* get_target() const { return target_; };
    void set_target(Entity* target) { target_ = target; };

    float get_basicShootCooldown() const { return basicShootCooldown_; };
    void set_basicShootCooldown(float cooldown) { basicShootCooldown_ = cooldown; }
    float get_shootCooldown() const { return shootCooldown_; };
    void set_shootCooldown(float cooldown) { shootCooldown_ = cooldown; };
private:
    Projectile projectileTemplate_;

    float basicShootCooldown_;
    float shootCooldown_;

    Entity* target_;

    void shoot();

    void updateAI(float time);
    void updateVisuals(float time) override;
    void updateProjectileTemplate();

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};