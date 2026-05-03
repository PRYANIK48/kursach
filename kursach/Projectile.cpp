#include "Projectile.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"
void Projectile::InitVariables() {
    set_visuals(Visuals(get_position()));
    set_move_speed(0.5f);
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
    set_move_speed(ref.get_move_speed());
    set_position(position);
    set_life_time(ref.get_life_time());
    set_collider(ref.get_collider());
    get_collider().setPosition(position);
    set_move_direction(direction);
}
void Projectile::updateInput(float time) {
}
void Projectile::Update(float time) {
    if (life_time_ < 0)
    {
        set_dead();
    }
    life_time_ -= time;

    updateInput(time);

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

void Projectile::updateVisuals(float time)
{
    get_visuals().set_anim_frame(get_visuals().get_anim_frame() + get_move_speed() * 0.04f * time);
    if (get_visuals().get_anim_frame() > get_visuals().get_anim_length()) {
        get_visuals().set_anim_frame(get_visuals().get_anim_frame() - get_visuals().get_anim_length());
    }
    this->set_position(get_position() + get_move_direction() * get_move_speed() * time);
    get_visuals().SetPosition(get_position());

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

    get_visuals().UpdateSprite();
    get_collider().setPosition(get_visuals().get_visuals_position());
}

void Projectile::onCollision(Entity* entity)
{
    if (auto* enemy = dynamic_cast<Enemy*>(entity)) {
        std::cout << "projectile in enemy" << std::endl;
    }
    if (auto* player = dynamic_cast<Player*>(entity)) {
        std::cout << "projectile in player" << std::endl;
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}