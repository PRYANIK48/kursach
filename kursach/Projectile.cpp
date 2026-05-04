#include "Projectile.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"
void Projectile::InitVariables() {
    set_visuals(Visuals(get_position()));
    set_move_speed(0.5f);
    set_friction(0.f);
}
void Projectile::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(2.f);
    get_collider().setSize(Vector2f(30 * get_visuals().get_sprite().getScale().x, 30 * get_visuals().get_sprite().getScale().x));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
Projectile::Projectile(Vector2f position, Vector2f direction) {
    set_position(position);
    set_move_direction(direction);
    InitVariables();
    InitCollider();
}
Projectile::Projectile(const Projectile& ref, Vector2f direction, Vector2f position) {
    set_visuals(Visuals(position));
    set_damage(ref.get_damage());
    set_friction(ref.get_friction());
    set_move_speed(ref.get_move_speed());
    set_position(position);
    set_life_time(ref.get_life_time());
    set_collider(ref.get_collider());
    get_collider().setPosition(position);
    set_move_direction(direction);
    set_velocity(direction*get_move_speed());
}
void Projectile::Update(float time) {
    if (life_time_ < 0)
    {
        set_dead();
    }
    life_time_ -= time;

    updateInput(time);
    updatePosition(time);
    updateVisuals(time);
}
void Projectile::Render(RenderTarget* target) {
    get_visuals().printInfo();
    get_visuals().Render(target);
    target->draw(get_collider());
}
void Projectile::CheckCollision(Entity* entity)
{
    if (get_collider().getGlobalBounds().intersects(entity->get_collider().getGlobalBounds()))
    {
        onCollision(entity);
    }
}

void Projectile::updateInput(float time) {
}
void Projectile::updatePosition(float time) {
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
void Projectile::updateVisuals(float time)
{
    get_visuals().set_anim_frame(get_visuals().get_anim_frame() + get_move_speed() * 0.04f * time);
    if (get_visuals().get_anim_frame() > get_visuals().get_anim_length()) {
        get_visuals().set_anim_frame(get_visuals().get_anim_frame() - get_visuals().get_anim_length());
    }

    if (abs(get_move_direction().y) > abs(get_move_direction().x)) {
        if (get_move_direction().y <= 0) {
            get_visuals().set_anim_sheet_row(0);
        }
        else {
            get_visuals().set_anim_sheet_row(1);
        }
    }
    else {
        if (get_move_direction().x >= 0) {
            get_visuals().set_anim_sheet_row(3);
        }
        else {
            get_visuals().set_anim_sheet_row(2);
        }
    }

    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}

void Projectile::onCollision(Entity* entity)
{
    if (auto* enemy = dynamic_cast<Enemy*>(entity)) {
        std::cout << "projectile in enemy" << std::endl;
        enemy->AddImpulse(get_velocity());
        set_dead();
    }
    if (auto* player = dynamic_cast<Player*>(entity)) {
        std::cout << "projectile in player" << std::endl;
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}