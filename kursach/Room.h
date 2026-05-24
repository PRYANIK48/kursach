#pragma once
#include<ctime>
#include <iostream>
#include "EntityInteractionSystem.h"
#include "DebugSettings.h"
#include "Random.h"
#include "RoomTemplates.h"
#include "Visuals.h"
#include "Wall.h"
#include "Door.h"
using namespace sf;
class Room
{
public:
    Room(Vector2f position = Vector2f());
    ~Room();

    void Render(RenderTarget* target);
    void GenerateRoom(Vector2f position = Vector2f(), int index = -1);
    void ClearRoom();

    Vector2f get_position() const { return position_; };
    void set_position(Vector2f position) { position_ = position; };
private:
    Vector2f position_;
    Visuals floor_visuals_;
    Visuals walls_visuals_;

    std::vector<Wall*> walls_;
    std::vector<Door*> doors_;

    const RoomTemplate* current_template_ = nullptr;

    void InitVisuals();
};

