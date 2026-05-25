#pragma once
#include "Entity.h"
class Pickup :public Entity
{
public:
    Pickup(Vector2f position, int type);

    void Update(float time) override;
    int get_type() const { return type_; };
    void set_type(int type);

private:
    int type_;

    void updatePosition(float time) override;
    void updateVisuals(float time) override;

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

