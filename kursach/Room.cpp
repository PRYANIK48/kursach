#include "Room.h"
#include "Stone.h"

Room::Room(Vector2f position)
{
    set_position(position);
    set_room_number(0);
    InitVisuals();
}

Room::~Room()
{
    walls_.clear();
    doors_.clear();
    pits_.clear();
    decorations_.clear();
}

void Room::Render(RenderTarget* target) {
    floor_visuals_.Render(target);
}
void Room::GenerateRoom(Vector2f position, int index)
{
    ClearRoom();
    set_position(position);
    set_room_number(get_room_number_() + 1);
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

    for (const auto& pitData : current_template_->pits)
    {
        Pit* pit = new Pit(position + pitData.position);
        pits_.push_back(pit);
        EntityInteractionSystem::AddEntity(pit);
    }

    for (const auto& decorationData : current_template_->decorations)
    {
        Decoration* decoration = new Decoration(position + decorationData.position);
        decorations_.push_back(decoration);
        EntityInteractionSystem::AddEntity(decoration);
    }

    for (const auto& stoneData : current_template_->stones)
    {
        Stone* stone = new Stone(position + stoneData.position);
        stones_.push_back(stone);
        EntityInteractionSystem::AddEntity(stone);
    }
}
void Room::ClearRoom()
{
    for (int i = 0; i < walls_.size(); ++i)
    {
        walls_[i]->set_dead();
    }
    walls_.clear();
    for (int i = 0; i < doors_.size(); ++i)
    {
        doors_[i]->set_dead();
    }
    for (int i = 0; i < pits_.size(); ++i)
    {
        pits_[i]->set_dead();
    }
    pits_.clear();
    for (int i = 0; i < decorations_.size(); ++i)
    {
        decorations_[i]->set_dead();
    }
    decorations_.clear();
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
}