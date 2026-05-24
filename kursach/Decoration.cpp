#include "Decoration.h"
Decoration::Decoration(Vector2f position)
{
    set_position(position);
    set_render_layer(2);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Decoration::InitVariables() {
}
void Decoration::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sheet().loadFromFile("Textures/room1walls.png");
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(1400);
    get_visuals().set_frame_h(900);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().UpdateSprite();
}
void Decoration::InitCollider()
{
}
void Decoration::Update(float time)
{
    updateVisuals(time);
}
void Decoration::updateVisuals(float time)
{
}
void Decoration::onCollision(Entity* entity)
{
}