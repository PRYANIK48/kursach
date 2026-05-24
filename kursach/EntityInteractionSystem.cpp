#include "EntityInteractionSystem.h"
#include "Entity.h"

std::vector<Entity*> EntityInteractionSystem::entities;
std::vector<Entity*> EntityInteractionSystem::pendingEntities;
void EntityInteractionSystem::UpdateEntities(float time)
{
    for (auto it = entities.begin(); it != entities.end(); ) {
        if ((*it)->IsReadyToDelete()) {
            delete* it;
            it = entities.erase(it);
            continue;
        }

        checkCollisions(*it);
        if ((*it)->IsReadyToDelete()) {
            delete* it;
            it = entities.erase(it);
            continue;
        }

        (*it)->Update(time);
        if ((*it)->IsReadyToDelete()) {
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
    std::sort(entities.begin(), entities.end(), [](Entity* a, Entity* b)
        {
            return a->get_position().y < b->get_position().y;
        }
    );
    for (int currentLayer = 0; currentLayer < 6; currentLayer++)
    {

        for (auto it = entities.begin(); it != entities.end(); ) {
            if ((*it)->get_render_layer() == currentLayer)
            {
                (*it)->Render(target);
            }
            ++it;
        }
    }
}

void EntityInteractionSystem::checkCollisions(Entity* entity)
{
    for (auto it = entities.begin(); it != entities.end(); ) {
        if (entity != *it)
        {
            entity->CheckCollision(*it);
        }
        if ((*it)->IsReadyToDelete()) {
            break;
        }
        ++it;
    }
}

void EntityInteractionSystem::AddEntity(Entity* entity)
{
    pendingEntities.push_back(entity);
}

