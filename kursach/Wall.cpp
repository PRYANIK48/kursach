#pragma once
#include "Wall.h"
#include "Projectile.h"
#include "Door.h"
#include "Pit.h"
#include "Decoration.h"
#include "Stone.h"
Wall::Wall(Vector2f position, Vector2f colliderSize) {
    set_position(position);
    set_render_layer(3);
    set_collider_size(colliderSize);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Wall::InitVariables() {
}
void Wall::InitVisuals()
{
}
void Wall::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(get_collider_size());
    get_collider().setOrigin(get_collider_size().x / 2, get_collider_size().y / 2);
    get_collider().setPosition(get_position());
}
void Wall::Update(float time) {
}
void Wall::Render(RenderTarget* target) {
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
    get_collider().setPosition(get_position());
}
void Wall::updateVisuals(float time) {
}

void Wall::onCollision(Entity* entity)
{
    if (auto* wall = dynamic_cast<Wall*>(entity)) {
    }
    else if (auto* door = dynamic_cast<Door*>(entity))
    {
    }
    else if (auto* pit = dynamic_cast<Pit*>(entity))
    {
    }
    else if (auto* decoration = dynamic_cast<Decoration*>(entity))
    {
    }
    else if (auto* stone = dynamic_cast<Stone*>(entity))
    {
    }
    else if (dynamic_cast<Entity*>(entity))
    {
        PushOut(entity);
        entity->OnWallCollision(this);
    }
}