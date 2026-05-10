#include "Enemy.h"
#include "Player.h"

void Enemy::InitVariables() {
    get_visuals().SetPosition(get_position());
    set_move_speed(0.5f);
    set_damage(1.f);
    set_maxHealth(3.f);
    set_health(get_maxHealth());
    get_visuals().set_anim_sheet_row(1);
}
void Enemy::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sheet().loadFromFile("Textures/lizard.png");
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(140);
    get_visuals().set_frame_h(140);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().set_anim_sheet_row(1);
    get_visuals().set_anim_length(4);
}
void Enemy::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(2.f);
    get_collider().setSize(Vector2f(60 * get_visuals().get_sprite().getScale().x, 60 * get_visuals().get_sprite().getScale().x));
    get_collider().setOrigin(Vector2f(15, 0));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
Enemy::Enemy(Vector2f position) {
    set_position(position);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Enemy::Update(float time) {
    updateInput(time);
    updatePosition(time);
    updateVisuals(time);
}
void Enemy::Render(RenderTarget* target) {
    get_visuals().printInfo();
    get_visuals().Render(target);
    target->draw(get_collider());
}
void Enemy::CheckCollision(Entity* entity)
{
    if (get_collider().getGlobalBounds().intersects(entity->get_collider().getGlobalBounds()))
    {
        onCollision(entity);
    }
}
void Enemy::updateInput(float time) {
    if (Keyboard::isKeyPressed(Keyboard::E))
    {
        std::cout << "e" << std::endl;
    }
}
void Enemy::updatePosition(float time) {
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
void Enemy::updateVisuals(float time) {
    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}

void Enemy::onCollision(Entity* entity)
{
    if (auto* player = dynamic_cast<Player*>(entity)) {
        if (!player->InIframe())
        {
        std::cout << "enemy in player" << std::endl;
            player->TryApplyDamage(get_damage());
            player->AddImpulse(Vector2f(-1.f, 0.f));
        }
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}

