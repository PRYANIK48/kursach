#include "Player.h"
#include <iostream>
#include "Enemy.h"
void Player::InitVariables() {
    this->basicShootCooldown_ = 10.f;
    this->shootCooldown_ = 0.f;
    set_visuals(Visuals(get_position()));
    set_move_speed(0.2f);
    set_damage(1.f);
    set_maxHealth(10.f);
    set_health(get_maxHealth());
    get_visuals().set_anim_sheet_row(1);
    set_facing_direction(Vector2f(0.f, 1.f));
    updateProjectileTemplate();
}
void Player::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(2.f);
    get_collider().setSize(Vector2f(30 * get_visuals().get_sprite().getScale().x, 30 * get_visuals().get_sprite().getScale().x));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
Player::Player(Vector2f position) {
    set_position(position);
    InitVariables();
    InitCollider();
}
void Player::Update(float time) {
    updateInput(time);
    updatePosition(time);
    updateVisuals(time);
    shootCooldown_ -= 0.05f * time;
}

void Player::Render(RenderTarget* target) {
    get_visuals().printInfo();
    get_visuals().Render(target);
    target->draw(get_collider());
}

void Player::CheckCollision(Entity* entity)
{
    if (get_collider().getGlobalBounds().intersects(entity->get_collider().getGlobalBounds()))
    {
        onCollision(entity);
    }
}

void Player::TryShoot()
{
    if (shootCooldown_ <= 0.f)
    {
        shoot();
        shootCooldown_ = basicShootCooldown_;
    }
}

void Player::shoot()
{
    Projectile* p = new Projectile(projectileTemplate_, get_facing_direction(), get_position());
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
    if (abs(get_move_direction().x) > 0 || abs(get_move_direction().y) > 0) {
        if (abs(get_move_direction().x) > 0 && abs(get_move_direction().y) > 0) {
            set_move_direction(get_move_direction() / sqrt(get_move_direction().x * get_move_direction().x + get_move_direction().y * get_move_direction().y));
        }
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
        get_visuals().set_anim_frame(0);
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
    set_move_direction(Vector2f(0.f, 0.f));
}
void Player::updateVisuals(float time)
{
    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}
void Player::updateProjectileTemplate()
{
    projectileTemplate_.set_damage(get_damage());
    projectileTemplate_.set_move_speed(get_move_speed() * 2);
    projectileTemplate_.set_life_time(800.f);
}

void Player::onCollision(Entity* entity)
{
    if (auto* enemy = dynamic_cast<Enemy*>(entity)) {
        std::cout << "player in enemy" << std::endl;
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}