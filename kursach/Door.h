#pragma once
#include "Wall.h"
class Door : public Wall
{
public:
    Door(Vector2f position, Vector2f facing);

    void Update(float time) override;
    void Render(RenderTarget* target) override;

    bool IsOpen() const { return is_open_; };
    void set_open(bool state) { is_open_ = state; };
    void try_open(bool state);
private:
    bool is_open_;
    void onOpen();
    void onClose();
    void onPlayerEntered();
    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

