#pragma once
#include <vector>
#include "Enemy.h"
#include "Projectile.h"

using namespace sf;

class Player : public Entity
{
public:
    Player(Vector2f position = Vector2f(0.f,0.f));

    void Update(float time);
    void Render(RenderTarget* target);

    void TryShoot();
    void TryApplyDamage(float damage);

    bool InIframe() const { return iframeCurrent_ > 0; };

    float get_iframeDuration() const { return iframeDuration_; };
    void set_iframeDuration(float duration) { iframeDuration_ = duration; }
    float get_iframeCurrent() const { return iframeCurrent_; };
    void set_iframeCurrent(float current) { iframeCurrent_ = current; }

    float get_basicShootCooldown() const { return basicShootCooldown_; };
    void set_basicShootCooldown(float cooldown) { basicShootCooldown_ = cooldown; }
    float get_shootCooldown() const { return shootCooldown_; };
    void set_shootCooldown(float cooldown) { shootCooldown_ = cooldown; };

private:
    Projectile projectileTemplate_;

    float iframeDuration_;
    float iframeCurrent_;
    float basicShootCooldown_;
    float shootCooldown_;

    void shoot();
    void updateInput(float time);
    void updatePosition(float time) override;
    void updateVisuals(float time) override;
    void updateProjectileTemplate();

    void onDeath() override;
    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

