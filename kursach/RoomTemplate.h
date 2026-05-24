#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace sf;

struct WallData
{
    Vector2f position;
    Vector2f size;
};

struct DoorData
{
    Vector2f position;
    Vector2f direction;
};

struct PitData
{
    Vector2f position;
};

struct DecorationData
{
    Vector2f position;
};

struct StoneData
{
    Vector2f position;
};

struct RoomTemplate
{
    std::vector<WallData> walls;
    std::vector<DoorData> doors;
    std::vector<PitData> pits;
    std::vector<DecorationData> decorations;
    std::vector<StoneData> stones;
};