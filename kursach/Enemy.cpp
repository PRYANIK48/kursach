#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(Vector2f position, Entity* target) {
    set_position(position);
    set_target(target);
    set_render_layer(5);
    InitVariables();
    InitVisuals();
    InitCollider();
}
void Enemy::InitVariables() {
    set_basicShootCooldown(500.f);
    set_shootCooldown(0.f);
    get_visuals().SetPosition(get_position());
    set_move_speed(0.1f);
    set_damage(1.f);
    set_maxHealth(3.f);
    set_health(get_maxHealth());
    get_visuals().set_anim_sheet_row(1);
    updateProjectileTemplate();
}
void Enemy::InitVisuals()
{
    get_visuals().SetPosition(get_position());
    get_visuals().get_sprite().setTexture(Assets::GetTexture("lizard"));
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
    get_collider().setOutlineThickness(-2.f);
    get_collider().setSize(Vector2f(60 * get_visuals().get_sprite().getScale().x, 60 * get_visuals().get_sprite().getScale().x));
    get_collider().setOrigin(Vector2f(get_collider().getSize().x / 2, 0));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
void Enemy::Update(float time) {
    if (!IsDead())
    {
        updateAI(time);
    }
    else
    {
        set_position(Vector2f(10000,10000));
    }
    Entity::Update(time);
    set_shootCooldown(get_shootCooldown() - time);
}
void Enemy::Render(RenderTarget* target) {
    if (!IsDead())
    {

        get_visuals().Render(target);
        if (DebugSettings::collidersVisuals)
        {
            target->draw(get_collider());
        }
    }
}

void Enemy::TryShoot()
{
    if (get_shootCooldown() <= 0.f)
    {
        shoot();
        set_shootCooldown(get_basicShootCooldown());
    }
}

void Enemy::shoot()
{
    Projectile* p = new Projectile(projectileTemplate_, get_facing_direction(), get_position(), this);
    EntityInteractionSystem::AddEntity(p);
}

void Enemy::updateAI(float time)
{
    float distance_to_target = GMath::Distance(get_position(), get_target()->get_position());
    float angle_to_target = GMath::AngleBetweenPoints(get_position(), get_target()->get_position());
    Vector2f direction_to_target = GMath::Direction(get_position(), get_target()->get_position());
    if (distance_to_target > 200.f)
    {
        set_move_direction(direction_to_target);
    }
    else
    {
        bool target_in_area = true;
        if (330.f < angle_to_target || angle_to_target < 30.f)
        {
            set_facing_direction(Vector2f(0.f, -1.f));
            if (angle_to_target < 90.f)
            {
                set_move_direction(Vector2f(1.f, 0.f));
            }
            else
            {
                set_move_direction(Vector2f(-1.f, 0.f));
            }
        }
        else if (60.f < angle_to_target && angle_to_target < 120.f)
        {
            set_facing_direction(Vector2f(1.f, 0.f));
            if (90.f < angle_to_target)
            {
                set_move_direction(Vector2f(0.f, 1.f));
            }
            else
            {
                set_move_direction(Vector2f(0.f, -1.f));
            }
        }
        else if (150.f < angle_to_target && angle_to_target < 210.f)
        {
            set_facing_direction(Vector2f(0.f, 1.f));
            if (180.f < angle_to_target)
            {
                set_move_direction(Vector2f(-1.f, 0.f));
            }
            else
            {
                set_move_direction(Vector2f(1.f, 0.f));
            }
        }
        else if (230.f < angle_to_target && angle_to_target < 300.f)
        {
            set_facing_direction(Vector2f(-1.f, 0.f));
            if (270.f < angle_to_target)
            {
                set_move_direction(Vector2f(0.f, -1.f));
            }
            else
            {
                set_move_direction(Vector2f(0.f, 1.f));
            }
        }
        else
        {
            target_in_area = false;
        }
        if (target_in_area && (std::fmodf(angle_to_target, 90.f) < 5.f))
        {
            set_move_direction(Vector2f());
        }
        if (distance_to_target < 150.f)
        {
            set_move_direction(-direction_to_target);
        }
        if (target_in_area)
        {
            TryShoot();
        }
    }
}

void Enemy::updateVisuals(float time) {
    if (GMath::Length(get_move_direction()) > 0.01)
    {
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
    else
    {
        get_visuals().set_anim_frame(0.9);
    }

    get_visuals().SetPosition(get_position());
    get_visuals().UpdateSprite();
}

void Enemy::updateProjectileTemplate()
{
    projectileTemplate_.get_visuals().get_sprite().setTexture(Assets::GetTexture("lizard projectile"));
    projectileTemplate_.set_damage(get_damage());
    projectileTemplate_.set_move_speed(0.3f);
    projectileTemplate_.set_life_time(800.f);
}

void Enemy::onCollision(Entity* entity)
{
    if (!IsDead())
    {
        if (auto* player = dynamic_cast<Player*>(entity)) {
            PushOut(entity, 0.05f);
            if (!player->InIframe())
            {
                player->TryApplyDamage(get_damage());
            }
        }
        else if (dynamic_cast<Entity*>(entity)) {
        }
    }
}

