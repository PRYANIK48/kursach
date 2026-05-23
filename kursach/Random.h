#pragma once

#include <iostream>

class Random
{
public:
    static void InitRandom();

    static int Int(int min, int max);

    static float Float(float min, float max);
};