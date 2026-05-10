#include "Entity.h"
void Entity::Update(float time) {
    updateInput(time);
    updatePosition(time);
    updateVisuals(time);
}
void Entity::ApplyDamage(float damage)
{
    set_health(get_health()-damage);
}
void Entity::updatePosition(float time)
{
    set_velocity(get_velocity() + get_move_direction() * get_move_speed() * get_friction() * time * 0.01f);
    set_position(get_position() + get_velocity() * time);
    set_velocity(get_velocity() - get_velocity() * get_friction() * time * 0.01f);
    if (abs(get_velocity().x) < 0.01f * get_friction())
    {
        set_velocity(Vector2f(0.f, get_velocity().y));
    }
    if (abs(get_velocity().y) < 0.01f * get_friction())
    {
        set_velocity(Vector2f(get_velocity().x, 0.f));
    }
    get_collider().setPosition(get_position());
    set_move_direction(Vector2f(0.f, 0.f));
}
void Entity::updateVisuals(float time)
{
    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}