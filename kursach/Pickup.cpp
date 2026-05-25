#include "Pickup.h"
#include "Player.h"
Pickup::Pickup(Vector2f position, int type)
{
    set_position(position);
    set_type(type);
    set_render_layer(5);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Pickup::InitVariables() {
}
void Pickup::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(210);
    get_visuals().set_frame_h(210);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().set_anim_length(1);
    get_visuals().UpdateSprite();
}
void Pickup::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(Vector2f(55 * get_visuals().get_sprite().getScale().x, 55 * get_visuals().get_sprite().getScale().y));
    get_collider().setOrigin(get_collider().getSize().x / 2, get_collider().getSize().y / 2);
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Pickup::Update(float time)
{
    updateVisuals(time);
    updatePosition(time);
}
void Pickup::set_type(int type)
{
    type_ = type;
    switch (get_type())
    {
    case 1:
        get_visuals().get_sprite().setTexture(Assets::GetTexture("chainmal"));
        break;
    default:
        get_visuals().get_sprite().setTexture(Assets::GetTexture("test"));
        break;
    }
}
void Pickup::updatePosition(float time)
{
    get_visuals().SetPosition(get_position());
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Pickup::updateVisuals(float time)
{
    get_visuals().UpdateSprite();
}
void Pickup::onCollision(Entity* entity)
{
    if (!IsDead())
    {
        if (auto* player = dynamic_cast<Player*>(entity)) {
            switch (get_type())
            {
            case 1:
                player->set_damage(player->get_damage() + 1.f);
                player->set_move_speed(player->get_move_speed() + 0.05f);
                player->set_health(player->get_health() + 3.f);
                break;
            default:
                break;
            }
            set_dead();
            set_position(Vector2f(10000, 10000));
        }
    }
}