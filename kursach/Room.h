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
#include "Pit.h"
#include "Decoration.h"
#include "Stone.h"
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
    int get_room_number_() const { return room_number_; };
    void set_room_number(int number) { room_number_ = number; };
private:
    int room_number_;
    Vector2f position_;
    Visuals floor_visuals_;

    std::vector<Wall*> walls_;
    std::vector<Door*> doors_;
    std::vector<Pit*> pits_;
    std::vector<Decoration*> decorations_;
    std::vector<Stone*> stones_;

    const RoomTemplate* current_template_ = nullptr;

    void InitVisuals();
};

