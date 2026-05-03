#include "EntityInteractionSystem.h"
#include "Entity.h"

std::vector<Entity*> EntityInteractionSystem::entities;
std::vector<Entity*> EntityInteractionSystem::pendingEntities;
void EntityInteractionSystem::UpdateEntities(float time)
{
    for (auto it = entities.begin(); it != entities.end(); ) {
        checkCollisions(*it);
        if ((*it)->IsDead()) {
            delete* it;
            it = entities.erase(it);
            continue;
        }

        (*it)->Update(time);
        if ((*it)->IsDead()) {
            delete* it;
            it = entities.erase(it);
        }
        else {
            ++it;
        }
    }
    entities.insert(entities.end(), pendingEntities.begin(), pendingEntities.end());
    pendingEntities.clear();
}

void EntityInteractionSystem::RenderEntities(sf::RenderTarget* target)
{
    for (auto it = entities.begin(); it != entities.end(); ) {
        (*it)->Render(target);
        ++it;
    }
}

void EntityInteractionSystem::checkCollisions(Entity* entity)
{
    for (auto it = entities.begin(); it != entities.end(); ) {
        entity->CheckCollision(*it);
        ++it;
    }
}

void EntityInteractionSystem::AddEntity(Entity* entity)
{
    pendingEntities.push_back(entity);
}

