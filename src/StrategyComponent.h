#pragma once

#include "Component.h"

enum class Strategies {random, patrol};

struct StrategyComponent : Component
{
    Strategies Strategy = Strategies::random;
    int Range = 3; //radius of how far it will consider moving away from present position

    int GoalX;
    int GoalY;
    int NextMove;
};