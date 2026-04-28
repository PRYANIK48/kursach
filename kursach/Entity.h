#pragma once
#include <vector>
#include "Visuals.h"
using namespace sf;
//сделать наследуемым для player
class Entity
{
public:
    Entity(Vector2f position = Vector2f(0.f, 0.f));

    void Update(float time);
    void Render(RenderTarget* target);

    Vector2f get_position() const { return position_; };

private:
    
    Visuals visuals_;
    RectangleShape collider_;
    Vector2f moveDirection_;
    Vector2f facingDirection_;

    float move_speed_;
    float damage_;
    float maxHealth_;
    float health_;

    Vector2f position_;

    void updateInput(float time);

    void InitVariables();
    void InitCollider();
};

