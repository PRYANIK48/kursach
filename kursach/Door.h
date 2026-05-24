#pragma once
#include "Entity.h"
class Door : public Entity
{
public:
    Door(Vector2f position, Vector2f facing);

    void Update(float time) override;

    bool IsLocked() const { return is_locked_; };
    void set_locked(bool state) { is_locked_ = state; };
    bool IsEntered() const { return is_entered_; };
    void set_entered(bool state) { is_entered_ = state; };
    bool IsOpen() const { return is_open_; };
    void set_open(bool state) { is_open_ = state; };
    void try_open(bool state);
    int get_opening_direction() const { return opening_direction_; };
    void set_opening_direction(int direction) { opening_direction_ = direction; };
private:
    bool is_locked_;
    bool is_entered_;
    bool is_open_;
    int opening_direction_;

    void updateVisuals(float time) override;

    void onOpen();
    void onClose();
    void onPlayerEntered();
    void onCollision(Entity* entity) override;
    void InitVariables() override;
    void InitVisuals() override;
    void InitCollider() override;
};

