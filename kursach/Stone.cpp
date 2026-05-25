#include "Stone.h"
#include "Player.h"
#include "Wall.h"
#include "Door.h"
#include "Pit.h"
#include "Decoration.h"
Stone::Stone(Vector2f position)
{
    set_position(position);
    set_render_layer(5);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Stone::InitVariables() {
}
void Stone::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sprite().setTexture(Assets::GetTexture("rock"));
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(120);
    get_visuals().set_frame_h(120);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().set_anim_length(1);
    get_visuals().UpdateSprite();
}
void Stone::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(Vector2f(90 * get_visuals().get_sprite().getScale().x, 90 * get_visuals().get_sprite().getScale().x));
    get_collider().setOrigin(get_collider().getSize().x / 2, get_collider().getSize().y / 2);
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Stone::Update(float time)
{
    updateVisuals(time);
}
void Stone::updateVisuals(float time)
{
    get_visuals().UpdateSprite();
}
void Stone::onCollision(Entity* entity)
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
    else if (auto* projectile = dynamic_cast<Projectile*>(entity))
    {
    }
    else if (dynamic_cast<Entity*>(entity))
    {
        PushOut(entity);
    }
}