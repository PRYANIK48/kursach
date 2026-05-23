#pragma once
#include<ctime>
#include <iostream>
#pragma once
#include "EntityInteractionSystem.h"
#include "DebugSettings.h"
#include "Wall.h"
#include "Door.h"
class Room
{
public:
    Room(Vector2f position = Vector2f());
    ~Room();

    void Render(RenderTarget* target);
    void GenerateRoom(Vector2f position = Vector2f());

    Vector2f get_position() const { return position_; };
    void set_position(Vector2f position) { position_ = position; };
private:
    Vector2f position_;
    Visuals floor_visuals_;
    Visuals walls_visuals_;
    std::vector<Wall*> walls_;
    std::vector<Door*> doors_;

    void InitVisuals();
    void InitWalls();
    void InitDoors();
};

