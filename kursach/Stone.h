#pragma once
#include "Entity.h"
class Stone : public Entity
{
public:
    Stone(Vector2f position);

    void Update(float time) override;

private:
    void updateVisuals(float time) override;

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

