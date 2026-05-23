#include "Random.h"

void Random::InitRandom()
{
    srand((time(0)));
}

int Random::Int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

float Random::Float(float min, float max)
{
    return min + (float)(rand()) / RAND_MAX * (max - min);
}
