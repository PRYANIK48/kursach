#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity;

class EntityInteractionSystem
{
public:
    static void UpdateEntities(float time);
    static void RenderEntities(sf::RenderTarget* target);
    static void AddEntity(Entity* entity);
private:
    static std::vector<Entity*> entities;
    static std::vector<Entity*> pendingEntities;
    
    static void checkCollisions(Entity* entity);
};

