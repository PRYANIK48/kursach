#pragma once
#include "Entity.h"
class Door : public Entity
{
public:
    Door(Vector2f position, Vector2f facing);

    void Update(float time) override;

    bool IsOpen() const { return is_open_; };
    void set_open(bool state) { is_open_ = state; };
    void try_open(bool state);
    int get_opening_direction() const { return opening_direction_; };
    void set_opening_direction(int direction) { opening_direction_ = direction; };
private:
    bool is_open_ = true;
    int opening_direction_ = 0;

    void updateVisuals(float time) override;

    void onOpen();
    void onClose();
    void onPlayerEntered();
    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

