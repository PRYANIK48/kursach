#include "Room.h"
#include "Stone.h"
#include "Player.h"
#include "Assets.h"

Room::Room(Vector2f position)
{
    set_position(position);
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
void Room::GenerateRoom(Player* player, Vector2f position, int index)
{
    ClearRoom();
    set_position(position);
    set_completed(false);
    set_room_number(get_room_number_() + 1);
    if (index < 0)
    {
        index = Random::Int(1, RoomTemplates::GetRoomCount()-1);
    }
    current_template_ = &RoomTemplates::GetRoom(index);

    floor_visuals_.SetPosition(position);
    for (const auto& wallData : current_template_->walls)
    {
        Wall* wall = new Wall(position + wallData.position, wallData.size);
        walls_.push_back(wall);
        EntityInteractionSystem::AddEntity(wall);
    }

    for (const auto& doorData : current_template_->doors)
    {
        Door* door = new Door(position + doorData.position, doorData.direction);
        door->set_locked(doorData.isLocked);
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

    for (const auto& enemyData : current_template_->enemies)
    {
        Enemy* enemy = new Enemy(position + enemyData.position, player);
        enemies_.push_back(enemy);
        EntityInteractionSystem::AddEntity(enemy);
    }
}
void Room::CheckEnemies()
{
    bool roomIsEmpty = true;
    for (int i = 0; i < enemies_.size(); ++i)
    {
        if (!enemies_[i]->IsDead())
        {
            roomIsEmpty = false;
            break;
        }
    }
    if (roomIsEmpty && !IsCompleted())
    {
        set_completed(true);
        for (int i = 0; i < doors_.size(); ++i)
        {
            if (doors_[i]->IsLocked())
            {
                doors_[i]->try_open(true);
            }
        }
    }
}

void Room::ClearRoom()
{
    for (int i = 0; i < walls_.size(); ++i)
    {
        walls_[i]->set_ready_to_delete();
    }
    walls_.clear();
    for (int i = 0; i < doors_.size(); ++i)
    {
        doors_[i]->set_ready_to_delete();
    }
    doors_.clear();
    for (int i = 0; i < pits_.size(); ++i)
    {
        pits_[i]->set_ready_to_delete();
    }
    pits_.clear();
    for (int i = 0; i < decorations_.size(); ++i)
    {
        decorations_[i]->set_ready_to_delete();
    }
    decorations_.clear();
    for (int i = 0; i < stones_.size(); ++i)
    {
        stones_[i]->set_ready_to_delete();
    }
    stones_.clear();
    for (int i = 0; i < enemies_.size(); ++i)
    {
        enemies_[i]->set_ready_to_delete();
    }
    enemies_.clear();
}
void Room::InitRoom()
{
    set_room_number(0);
    InitVisuals();
}
Door* Room::GetEnteredDoor()
{
    for (int i = 0; i < doors_.size(); ++i)
    {
        if (doors_[i]->IsEntered())
        {
            return doors_[i];
        }
    }

    return nullptr;
}
void Room::InitVisuals()
{
    floor_visuals_.get_sprite().setTexture(Assets::GetTexture("room1floor"));
    floor_visuals_.get_sprite().setScale(Vector2f(0.5f, 0.5f));
    floor_visuals_.set_frame_w(1400);
    floor_visuals_.set_frame_h(900);
    floor_visuals_.get_sprite().setOrigin(floor_visuals_.get_frame_w() / 2, floor_visuals_.get_frame_h() / 2);
    floor_visuals_.set_anim_sheet_row(0);
    floor_visuals_.set_anim_length(1);
    floor_visuals_.UpdateSprite();
}