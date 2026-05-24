#include "RoomTemplates.h"

std::vector<RoomTemplate> RoomTemplates::rooms_;

void RoomTemplates::InitTemplates()
{
    WallData wall;
    DoorData door;
    PitData pit;
    DecorationData decoration;
    StoneData stone;
    EnemyData enemy;

    //room0
    RoomTemplate room;
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


    door.position = Vector2f(-320.f, 0.f);
    door.direction = Vector2f(1.f, 0.f);
    door.isLocked = false;
    room.doors.push_back(door);
    door.position = Vector2f(320.f, 0.f);
    door.direction = Vector2f(-1.f, 0.f);
    door.isLocked = true;
    room.doors.push_back(door);
    door.position = Vector2f(0.f, 195.f);
    door.direction = Vector2f(0.f, -1.f);
    door.isLocked = false;
    room.doors.push_back(door);
    door.position = Vector2f(0.f, -195.f);
    door.direction = Vector2f(0.f, 1.f);
    door.isLocked = false;
    room.doors.push_back(door);

    stone.position = Vector2f(265.f, 140.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(265.f, -140.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(-265.f, 140.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(-265.f, -140.f);
    room.stones.push_back(stone);
    
    decoration.position = Vector2f(0.f, 0.f);
    room.decorations.push_back(decoration);

    rooms_.push_back(room);

    //room1
    room = RoomTemplate();
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

    door.position = Vector2f(-320.f, 0.f);
    door.direction = Vector2f(1.f, 0.f);
    door.isLocked = false;
    room.doors.push_back(door);
    door.position = Vector2f(320.f, 0.f);
    door.direction = Vector2f(-1.f, 0.f);
    door.isLocked = true;
    room.doors.push_back(door);

    pit.position = Vector2f(-220.f, 100.f);
    room.pits.push_back(pit);
    pit.position = Vector2f(220.f, 100.f);
    room.pits.push_back(pit);
    pit.position = Vector2f(-220.f, -100.f);
    room.pits.push_back(pit);
    pit.position = Vector2f(220.f, -100.f);
    room.pits.push_back(pit);

    enemy.position = Vector2f(0.f, 100.f);
    room.enemies.push_back(enemy);

    decoration.position = Vector2f(0.f, 0.f);
    room.decorations.push_back(decoration);

    rooms_.push_back(room);

    //room2
    room = RoomTemplate();
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

    door.position = Vector2f(-320.f, 0.f);
    door.direction = Vector2f(1.f, 0.f);
    door.isLocked = false;
    room.doors.push_back(door);
    door.position = Vector2f(320.f, 0.f);
    door.direction = Vector2f(-1.f, 0.f);
    door.isLocked = true;
    room.doors.push_back(door);

    stone.position = Vector2f(0.f, 100.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(100.f, 0.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(0.f, -100.f);
    room.stones.push_back(stone);
    stone.position = Vector2f(-100.f, 0.f);
    room.stones.push_back(stone);

    enemy.position = Vector2f(0.f, 100.f);
    room.enemies.push_back(enemy);

    decoration.position = Vector2f(0.f, 0.f);
    room.decorations.push_back(decoration);

    rooms_.push_back(room);

    //room3
    room = RoomTemplate();
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

    door.position = Vector2f(-320.f, 0.f);
    door.direction = Vector2f(1.f, 0.f);
    door.isLocked = false;
    room.doors.push_back(door);
    door.position = Vector2f(320.f, 0.f);
    door.direction = Vector2f(-1.f, 0.f);
    door.isLocked = true;
    room.doors.push_back(door);

    pit.position = Vector2f(160.f, -120.f);
    room.pits.push_back(pit);
    pit.position = Vector2f(160.f, 0.f);
    room.pits.push_back(pit);
    pit.position = Vector2f(160.f, 120.f);
    room.pits.push_back(pit);

    enemy.position = Vector2f(200.f, 0.f);
    room.enemies.push_back(enemy);

    decoration.position = Vector2f(0.f, 0.f);
    room.decorations.push_back(decoration);

    rooms_.push_back(room);
}

const RoomTemplate& RoomTemplates::GetRoom(int index)
{
    return rooms_[index];
}