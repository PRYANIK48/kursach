#include "Door.h"
#include "Player.h"
#include "Pit.h"
Door::Door(Vector2f position, Vector2f facing)
{
    set_position(position);
    set_render_layer(4);
    set_facing_direction(facing);
    set_opening_direction(0);
    set_open(true);
    try_open(false);
    set_locked(true);
    set_entered(false);
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
    get_visuals().get_sprite().setTexture(Assets::GetTexture("door"));
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(200);
    get_visuals().set_frame_h(200);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);

    if (abs(get_facing_direction().y) > abs(get_facing_direction().x)) {
        if (get_facing_direction().y <= 0) {
            get_visuals().set_anim_sheet_row(2);
        }
        else {
            get_visuals().set_anim_sheet_row(0);
        }
    }
    else {
        if (get_facing_direction().x >= 0) {
            get_visuals().set_anim_sheet_row(1);
        }
        else {
            get_visuals().set_anim_sheet_row(3);
        }
    }
    get_visuals().set_anim_length(6);
    get_visuals().UpdateSprite();
}
void Door::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(Vector2f(100,100));
    get_collider().setOrigin(get_collider().getSize().x / 2, get_collider().getSize().y / 2);
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Door::Update(float time)
{
    updateVisuals(time);
}
void Door::try_open(bool state)
{
    if (IsOpen() == state)
    {
    }
    else if (state)
    {
        set_open(state);
        set_opening_direction(-1);
        onOpen();
    }
    else
    {
        set_open(state);
        set_opening_direction(1);
        onClose();
    }
}
void Door::updateVisuals(float time)
{
    if (get_opening_direction() != 0)
    {
        get_visuals().set_anim_frame(get_visuals().get_anim_frame() + get_opening_direction() * 0.02f * time);
        if ((get_visuals().get_anim_frame() < 0) || (get_visuals().get_anim_frame() > get_visuals().get_anim_length())) {
            set_opening_direction(0);
        }
    }
    get_visuals().UpdateSprite();
}
void Door::onOpen()
{
}
void Door::onClose()
{
}
void Door::onPlayerEntered()
{
    set_entered(true);
}
void Door::onCollision(Entity* entity)
{
    if (auto* player = dynamic_cast<Player*>(entity)) {
        if (IsOpen())
        {
            onPlayerEntered();
        }
    }
}