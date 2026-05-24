#include "Room.h"

Room::Room(Vector2f position)
{
    set_position(position);
    InitVisuals();
}

Room::~Room()
{
}

void Room::Render(RenderTarget* target) {
    floor_visuals_.Render(target);
    walls_visuals_.Render(target);
}
void Room::GenerateRoom(Vector2f position, int index)
{
    ClearRoom();
    set_position(position);
    if (index < 0)
    {
        index = Random::Int(1, RoomTemplates::GetRoomCount());
    }
    current_template_ = &RoomTemplates::GetRoom(index);

    for (const auto& wallData : current_template_->walls)
    {
        Wall* wall = new Wall(position + wallData.position, wallData.size);
        walls_.push_back(wall);
        EntityInteractionSystem::AddEntity(wall);
    }

    for (const auto& doorData : current_template_->doors)
    {
        Door* door = new Door(position + doorData.position, doorData.direction);
        doors_.push_back(door);
        EntityInteractionSystem::AddEntity(door);
    }
}
void Room::ClearRoom()
{
    for (Wall* wall : walls_)
    {
        wall->set_dead();
    }
    walls_.clear();

    for (Door* door : doors_)
    {
        door->set_dead();
    }
    doors_.clear();
}
void Room::InitVisuals()
{
    floor_visuals_.get_sheet().loadFromFile("Textures/room1floor.png");
    floor_visuals_.get_sprite().setScale(Vector2f(0.5f, 0.5f));
    floor_visuals_.set_frame_w(1400);
    floor_visuals_.set_frame_h(900);
    floor_visuals_.get_sprite().setOrigin(floor_visuals_.get_frame_w() / 2, floor_visuals_.get_frame_h() / 2);
    floor_visuals_.set_anim_sheet_row(0);
    floor_visuals_.set_anim_length(1);
    floor_visuals_.UpdateSprite();

    walls_visuals_.get_sheet().loadFromFile("Textures/room1walls.png");
    walls_visuals_.get_sprite().setScale(Vector2f(0.5f, 0.5f));
    walls_visuals_.set_frame_w(1400);
    walls_visuals_.set_frame_h(900);
    walls_visuals_.get_sprite().setOrigin(floor_visuals_.get_frame_w() / 2, floor_visuals_.get_frame_h() / 2);
    walls_visuals_.set_anim_sheet_row(0);
    walls_visuals_.set_anim_length(1);
    walls_visuals_.UpdateSprite();
}