#pragma once
#include "Wall.h"
#include "Projectile.h"
Wall::Wall(Vector2f position, Vector2f size) {
    set_position(position);
    set_size(size);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Wall::InitVariables() {
    get_visuals().SetPosition(get_position());
}
void Wall::InitVisuals()
{
    /*get_visuals().SetPosition(get_position());
    get_visuals().get_sheet().loadFromFile("Textures/lizard.png");
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(140);
    get_visuals().set_frame_h(140);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().set_anim_sheet_row(0);
    get_visuals().set_anim_length(1);*/
}
void Wall::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(get_size());
    get_collider().setOrigin(get_size().x / 2, get_size().y / 2);
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Wall::Update(float time) {
    Entity::Update(time);
}
void Wall::Render(RenderTarget* target) {
    /*get_visuals().printInfo();
    get_visuals().Render(target);*/
    if (DebugSettings::collidersVisuals)
    {
        target->draw(get_collider());
    }
}
void Wall::CheckCollision(Entity* entity)
{
    if (get_collider().getGlobalBounds().intersects(entity->get_collider().getGlobalBounds()))
    {
        onCollision(entity);
    }
}

void Wall::updatePosition(float time) {
    /*set_velocity(get_velocity() + get_move_direction() * get_move_speed() * get_friction() * time * 0.01f);
    set_position(get_position() + get_velocity() * time);
    set_velocity(get_velocity() - get_velocity() * get_friction() * time * 0.01f);
    if (abs(get_velocity().x) < 0.01f * get_friction())
    {
        set_velocity(Vector2f(0.f, get_velocity().y));
    }
    if (abs(get_velocity().y) < 0.01f * get_friction())
    {
        set_velocity(Vector2f(get_velocity().x, 0.f));
    } */
    get_collider().setPosition(get_position());
}
void Wall::updateVisuals(float time) {
    //get_visuals().SetPosition(get_position());
    //get_visuals().UpdateSprite();
}

void Wall::onCollision(Entity* entity)
{
    if (auto* wall = dynamic_cast<Wall*>(entity)) {
    }
    else if (dynamic_cast<Entity*>(entity))
    {
        PushOut(entity);
        entity->OnWallCollision(this);
    }
}