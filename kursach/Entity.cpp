#include "Entity.h"
void Entity::Update(float time) {
    updatePosition(time);
    updateVisuals(time);
    set_move_direction(Vector2f(0.f, 0.f));
}
void Entity::Render(RenderTarget* target)
{
    get_visuals().Render(target);
    if (DebugSettings::collidersVisuals)
    {
        target->draw(get_collider());
    }
}
void Entity::CheckCollision(Entity* entity)
{
    if (get_collider().getGlobalBounds().intersects(entity->get_collider().getGlobalBounds()))
    {
        onCollision(entity);
    }
}
void Entity::ApplyDamage(float damage)
{
    set_health(get_health()-damage);
}
void Entity::PushOut(Entity* entity, float power)
{
    FloatRect entityBounds = entity->get_collider().getGlobalBounds();
    FloatRect wallBounds = get_collider().getGlobalBounds();

    Vector2f overlap(std::min(entityBounds.left + entityBounds.width - wallBounds.left,
        wallBounds.left + wallBounds.width - entityBounds.left),
        std::min(entityBounds.top + entityBounds.height - wallBounds.top,
            wallBounds.top + wallBounds.height - entityBounds.top));

    if (overlap.x < overlap.y)
    {
        if (entityBounds.left < wallBounds.left)
        {
            entity->set_position(Vector2f(entity->get_position().x - overlap.x * power, entity->get_position().y));
        }
        else
        {
            entity->set_position(Vector2f(entity->get_position().x + overlap.x * power, entity->get_position().y));
        }
        entity->set_velocity(Vector2f(entity->get_velocity().x * (1 - power), entity->get_velocity().y));
    }
    else
    {
        if (entityBounds.top < wallBounds.top)
        {
            entity->set_position(Vector2f(entity->get_position().x, entity->get_position().y - overlap.y * power));
        }
        else
        {
            entity->set_position(Vector2f(entity->get_position().x, entity->get_position().y + overlap.y * power));
        }
        entity->set_velocity(Vector2f(entity->get_velocity().x, entity->get_velocity().y * (1 - power)));
    }
    entity->get_collider().setPosition(entity->get_position());
}
void Entity::set_health(float health)
{
    health_ = health;
    if (health > maxHealth_)
    {
        health_ = maxHealth_;
    }
    else if (health <= 0)
    {
        health = 0;
        set_dead();
    }
}
void Entity::set_dead()
{
    is_dead_ = true;
    onDeath();
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
}
void Entity::updateVisuals(float time)
{
    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}

void Entity::onDeath()
{
}
