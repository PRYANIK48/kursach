#include "Player.h"
#include <iostream>
#include "Projectile.h"

Player::Player(Vector2f position) {
    set_position(position);
    set_render_layer(5);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Player::InitVariables() {
    set_basicShootCooldown(500.f);
    set_shootCooldown(0.f);
    set_iframeDuration(500.f);
    set_iframeCurrent(0.f);
    set_move_speed(0.2f);
    set_damage(1.f);
    set_maxHealth(10.f);
    set_health(get_maxHealth());
    updateProjectileTemplate();
}
void Player::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sprite().setTexture(Assets::GetTexture("player"));
    get_visuals().get_sprite().setScale(Vector2f(0.5f, 0.5f));
    get_visuals().set_frame_w(140);
    get_visuals().set_frame_h(140);
    get_visuals().get_sprite().setOrigin(get_visuals().get_frame_w() / 2, get_visuals().get_frame_h() / 2);
    get_visuals().set_anim_sheet_row(1);
    get_visuals().set_anim_length(4);
}
void Player::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(Vector2f(60 * get_visuals().get_sprite().getScale().x, 60 * get_visuals().get_sprite().getScale().x));
    get_collider().setOrigin(Vector2f(get_collider().getSize().x / 2, 0));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Player::Update(float time) {
    updateInput(time);
    Entity::Update(time);
    set_shootCooldown(get_shootCooldown() - time);
    set_iframeCurrent(get_iframeCurrent() - time);
}

void Player::Render(RenderTarget* target) {
    get_visuals().printInfo();
    get_visuals().Render(target);
    if (DebugSettings::collidersVisuals)
    {
        target->draw(get_collider());
    }
}

void Player::TryShoot()
{
    if (get_shootCooldown() <= 0.f)
    {
        shoot();
        set_shootCooldown(get_basicShootCooldown());
    }
}
void Player::TryApplyDamage(float damage)
{
    if (get_iframeCurrent() <= 0.f)
    {
        ApplyDamage(damage);
        set_iframeCurrent(get_iframeDuration());
    }
}

void Player::shoot()
{
    Projectile* p = new Projectile(projectileTemplate_, get_facing_direction(), get_position(), this);
    EntityInteractionSystem::AddEntity(p);
}
void Player::updateInput(float time) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        set_move_direction(Vector2f(-1.f, get_move_direction().y));
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        set_move_direction(Vector2f(1.f, get_move_direction().y));
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        set_move_direction(Vector2f(get_move_direction().x, -1.f));
    }
    else if (Keyboard::isKeyPressed(Keyboard::S)) {
        set_move_direction(Vector2f(get_move_direction().x, 1.f));
    }
    if (GMath::Length(get_move_direction()) > 0.01) {
        set_move_direction(GMath::Normalize(get_move_direction()));
        get_visuals().set_anim_frame(get_visuals().get_anim_frame() + get_move_speed() * 0.04f * time);
        if (get_visuals().get_anim_frame() > get_visuals().get_anim_length()) {
            get_visuals().set_anim_frame(get_visuals().get_anim_frame() - get_visuals().get_anim_length());
        }

        if (abs(get_move_direction().y) > abs(get_move_direction().x)) {
            if (get_move_direction().y <= 0) {
                set_facing_direction(Vector2f(0.f, -1.f));
                get_visuals().set_anim_sheet_row(0);
            }
            else {
                set_facing_direction(Vector2f(0.f, 1.f));
                get_visuals().set_anim_sheet_row(1);
            }
        }
        else {
            if (get_move_direction().x >= 0) {
                set_facing_direction(Vector2f(1.f, 0.f));
                get_visuals().set_anim_sheet_row(3);
            }
            else {
                set_facing_direction(Vector2f(-1.f, 0.f));
                get_visuals().set_anim_sheet_row(2);
            }
        }
    }
    else {
        get_visuals().set_anim_frame(0.9);
    }

    if (Keyboard::isKeyPressed(Keyboard::F))
    {
        TryShoot();
    }
}
void Player::updatePosition(float time)
{
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
void Player::updateVisuals(float time)
{
    if (InIframe())
    {
        get_visuals().get_sprite().setColor(Color(200, 150, 150, 255));
    }
    else
    {
        get_visuals().get_sprite().setColor(Color(255, 255, 255, 255));

    }
    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}
void Player::updateProjectileTemplate()
{
    projectileTemplate_.set_damage(get_damage());
    projectileTemplate_.set_move_speed(get_move_speed() * 2);
    projectileTemplate_.set_life_time(800.f);
}

void Player::onDeath()
{
    std::cout << "player dead" << std::endl;
    //set_ready_to_delete();
}

void Player::onCollision(Entity* entity)
{
    if (auto* enemy = dynamic_cast<Enemy*>(entity)) {
        if (InIframe())
        {
            PushOut(entity, 0.2f);
        }
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}