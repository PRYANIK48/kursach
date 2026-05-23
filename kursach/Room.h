#pragma once
#include<ctime>
#include <iostream>
#include "EntityInteractionSystem.h"
#include "DebugSettings.h"
#include "Wall.h"
class Room
{
public:
private:

    std::vector<Wall*> walls_;
    


    void InitWalls();
};

