#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
    Enemy(Vector2f position = Vector2f(0.f, 0.f));

    void Update(float time) override;
    void Render(RenderTarget* target) override;
    void CheckCollision(Entity* entity);

private:

    void updateInput(float time) override;
    void updatePosition(float time) override;
    void updateVisuals(float time) override;

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};