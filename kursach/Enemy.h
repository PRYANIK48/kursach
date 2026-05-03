#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
    Enemy(Vector2f position);

    void Update(float time) override;
    void Render(RenderTarget* target) override;
    void CheckCollision(Entity* entity);

private:

    void updateInput(float time) ;

    void onCollision(Entity* entity);
    void InitVariables();
    void InitCollider();
};