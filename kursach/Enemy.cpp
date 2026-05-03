#include "Enemy.h"
#include "Player.h"

void Enemy::InitVariables() {
    get_visuals().SetPosition(get_position());
    set_move_speed(0.5f);
    set_damage(1.f);
    set_maxHealth(10.f);
    set_health(get_maxHealth());
    get_visuals().set_anim_sheet_row(1);
    set_facing_direction(Vector2f(0.f, 1.f));
}
void Enemy::InitCollider()
{
    get_collider().setFillColor(Color(100, 200, 100, 80));
    get_collider().setOutlineColor(Color(50, 255, 50, 200));
    get_collider().setOutlineThickness(2.f);
    get_collider().setSize(Vector2f(30 * get_visuals().get_sprite().getScale().x, 30 * get_visuals().get_sprite().getScale().x));
    get_collider().setPosition(get_visuals().get_visuals_position());
}
Enemy::Enemy(Vector2f position) {
    set_position(position);
    InitVariables();
    InitCollider();
}
void Enemy::Update(float time) {
    if (IsDead())
    {
    }
    this->updateInput(time);
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

    this->get_visuals().UpdateSprite();
    this->set_move_direction(Vector2f(0.f, 0.f));
}

void Enemy::onCollision(Entity* entity)
{
    if (auto* player = dynamic_cast<Player*>(entity)) {
        std::cout << "enemy in player" << std::endl;
    }
    else if (dynamic_cast<Entity*>(entity)) {
    }
}

