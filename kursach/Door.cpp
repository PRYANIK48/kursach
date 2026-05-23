#include "Door.h"
#include "Player.h"
Door::Door(Vector2f position, Vector2f facing)
{
    set_position(position);
    set_facing_direction(facing);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Door::InitVariables() {
    set_open(false);
}
void Door::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sheet().loadFromFile("Textures/lizard.png");
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(140);
    get_visuals().set_frame_h(140);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);

    if (abs(get_facing_direction().y) > abs(get_facing_direction().x)) {
        if (get_facing_direction().y <= 0) {
            get_visuals().set_anim_sheet_row(0);
        }
        else {
            get_visuals().set_anim_sheet_row(1);
        }
    }
    else {
        if (get_facing_direction().x >= 0) {
            get_visuals().set_anim_sheet_row(3);
        }
        else {
            get_visuals().set_anim_sheet_row(2);
        }
    }
    get_visuals().set_anim_length(1);
    get_visuals().UpdateSprite();
}
void Door::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(get_collider_size());
    get_collider().setOrigin(get_collider_size().x / 2, get_collider_size().y / 2);
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Door::Update(float time)
{
    if (true)
    {
        get_visuals().set_anim_frame(get_visuals().get_anim_frame() + get_move_speed() * 0.04f * time);
    }
    else
    {

    }
}
void Door::Render(RenderTarget* target)
{
    get_visuals().Render(target);
    if (DebugSettings::collidersVisuals)
    {
        target->draw(get_collider());
    }
}
void Door::try_open(bool state)
{
    if (IsOpen() == state)
    {
    }
    else if (state)
    {
        set_open(state);
        onOpen();
    }
    else
    {
        set_open(state);
        onClose();
    }
}
void Door::onOpen()
{
}
void Door::onClose()
{
}
void Door::onPlayerEntered()
{
}
void Door::onCollision(Entity* entity)
{
    if (auto* wall = dynamic_cast<Wall*>(entity)) {
    }
    else if (auto* player = dynamic_cast<Player*>(entity)) {
        if (IsOpen())
        {
            onPlayerEntered();
        }
        else
        {
            PushOut(entity);
            entity->OnWallCollision(this);
        }
    }
    else if (dynamic_cast<Entity*>(entity))
    {
        PushOut(entity);
        entity->OnWallCollision(this);
    }
}