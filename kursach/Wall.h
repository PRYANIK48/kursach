#pragma once
#include "Entity.h"
class Wall : public Entity
{
public:
    Wall(Vector2f position, Vector2f size);

    void Update(float time) override;
    void Render(RenderTarget* target) override;
    void CheckCollision(Entity* entity);

    Vector2f get_size() const { return size_; };
    void set_size(Vector2f size) { size_ = size; };
private:
    Vector2f size_ = Vector2f(50.f,50.f);

    void updatePosition(float time) override;
    void updateVisuals(float time) override;

    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};
