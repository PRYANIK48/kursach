#pragma once

#include "RoomTemplate.h"
#include <iostream>

class RoomTemplates
{
public:
    static void InitTemplates();

    static const RoomTemplate& GetRoom(int index);
    static const int GetRoomCount() { return rooms_.size(); };

private:
    static std::vector<RoomTemplate> rooms_;
};