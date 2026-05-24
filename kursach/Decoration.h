#pragma once
#include "Entity.h"
class Decoration : public Entity
{
public:
    Decoration(Vector2f position);

    void Update(float time) override;

private:
    void updateVisuals(float time) override;

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

