#include "RoomTemplates.h"

std::vector<RoomTemplate> RoomTemplates::rooms_;

void RoomTemplates::InitTemplates()
{
    RoomTemplate room;
    WallData wall;
    wall.position = Vector2f(-330.f, 0.f);
    wall.size = Vector2f(80.f, 400.f);
    room.walls.push_back(wall);
    wall.position = Vector2f(330.f, 0.f);
    wall.size = Vector2f(80.f, 400.f);
    room.walls.push_back(wall);
    wall.position = Vector2f(0.f, 210.f);
    wall.size = Vector2f(700.f, 80.f);
    room.walls.push_back(wall);
    wall.position = Vector2f(0.f, -210.f);
    wall.size = Vector2f(700.f, 80.f);
    room.walls.push_back(wall);

    room.doors.push_back({
        {-320.f, 0.f},
        {1.f, 0.f}
        });
    room.doors.push_back({
        {320.f, 0.f},
        {-1.f, 0.f}
        });

    rooms_.push_back(room);
}

const RoomTemplate& RoomTemplates::GetRoom(int index)
{
    return rooms_[index];
}