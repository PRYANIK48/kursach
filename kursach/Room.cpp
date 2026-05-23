#include "Room.h"

Room::Room(Vector2f position)
{
    set_position(position);
    InitVisuals();
    InitWalls();
    InitDoors();
}

Room::~Room()
{
    for (Wall* wall : walls_)
    {
        delete wall;
    }

    walls_.clear();
}

void Room::Render(RenderTarget* target) {
    floor_visuals_.Render(target);
    walls_visuals_.Render(target);
}
void Room::GenerateRoom(Vector2f position)
{
    set_position(position);

}
void Room::InitVisuals()
{
    floor_visuals_.get_sheet().loadFromFile("Textures/room.png");
    floor_visuals_.get_sprite().setScale(Vector2f(0.5f, 0.5f));
    floor_visuals_.set_frame_w(2320);
    floor_visuals_.set_frame_h(1480);
    floor_visuals_.get_sprite().setOrigin(floor_visuals_.get_frame_w() / 2, floor_visuals_.get_frame_h() / 2);
    floor_visuals_.set_anim_sheet_row(0);
    floor_visuals_.set_anim_length(1);
    floor_visuals_.UpdateSprite();

    walls_visuals_.get_sheet().loadFromFile("Textures/room.png");
    walls_visuals_.get_sprite().setScale(Vector2f(0.5f, 0.5f));
    walls_visuals_.set_frame_w(2320);
    walls_visuals_.set_frame_h(1480);
    walls_visuals_.get_sprite().setOrigin(floor_visuals_.get_frame_w() / 2, floor_visuals_.get_frame_h() / 2);
    walls_visuals_.set_anim_sheet_row(0);
    walls_visuals_.set_anim_length(1);
    walls_visuals_.UpdateSprite();
}
void Room::InitWalls()
{
    Wall* wall = new Wall(get_position() + Vector2f(-300, 0), get_position() + Vector2f(80, 400));
    walls_.push_back(wall);

    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(get_position() + Vector2f(300, 0), get_position() + Vector2f(80, 400));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(get_position() + Vector2f(0, -200), get_position() + Vector2f(700, 80));
    walls_.push_back(wall);
    EntityInteractionSystem::AddEntity(wall);

    wall = new Wall(get_position() + Vector2f(0, 200), get_position() + Vector2f(700, 80));
    walls_.push_back(wall);
}
void Room::InitDoors()
{
    Door* door = new Door(get_position() + Vector2f(-250, 0), get_position() + Vector2f(1.f, 0.f));
    doors_.push_back(door);
    EntityInteractionSystem::AddEntity(door);

    door = new Door(get_position() + Vector2f(250, 0), get_position() + Vector2f(-1.f, 0.f));
    doors_.push_back(door);
    EntityInteractionSystem::AddEntity(door);
}