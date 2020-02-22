#pragma once

#include <stack>

#include "Component.h"

enum class Strategies {random, patrol};

struct StrategyComponent : Component
{
    Strategies Strategy = Strategies::random;
    int Range = 10; //radius of how far it will consider moving away from present position

    bool HasGoal = false;

    std::stack<Point*> Path;

    Point Goal;

    int GoalX;
    int GoalY;
    int NextMove;
};