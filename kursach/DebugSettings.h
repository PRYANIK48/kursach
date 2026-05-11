#pragma once
#include <iostream>
class DebugSettings
{
public:
    static void toggleCollidersVisuals() {collidersVisuals = !collidersVisuals;};
    static bool collidersVisuals;
};

