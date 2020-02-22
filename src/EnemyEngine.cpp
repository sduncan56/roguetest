#include "EnemyEngine.h"

#include "libtcod/libtcod.hpp"


#include "StrategyComponent.h"
#include "PathfindingEngine.h"

void EnemyEngine::ConsiderStrategy(Entity& enemy, Cave& cave) {
    auto strategyComponent = enemy.GetComponent<StrategyComponent>();

    if (!strategyComponent->HasGoal || enemy.GetPosition() == strategyComponent->Goal)
    {
        strategyComponent->HasGoal = false;
        while (!strategyComponent->HasGoal)
            ConsiderMove(enemy, cave);
    }
    else
    {
        
    }
    
}

void EnemyEngine::ConsiderMove(Entity& enemy, Cave& cave) {
    auto strategyComponent = enemy.GetComponent<StrategyComponent>();

    switch(strategyComponent->Strategy)
    {
        case Strategies::random:
        {
            strategyComponent->Goal  = FindRandomFreeSpace(enemy, cave, *strategyComponent);
            strategyComponent->HasGoal = true;

            PathfindingEngine pfEngine;
            strategyComponent->Path = pfEngine.FindPathTo(enemy.GetPosition(), strategyComponent->Goal, cave);
            if (strategyComponent->Path.empty())
                strategyComponent->HasGoal = false;

            break;
        }
        default:
        break;
    }
}

EnemyEngine::EnemyEngine() {
    
}

Point EnemyEngine::FindRandomFreeSpace(Entity& enemy, Cave& cave, StrategyComponent& strategyComponent) {
    //pick a random square within a given radius
    auto *rng = TCODRandom::getInstance();

    int goalX = rng->getInt(strategyComponent.Range * -1, strategyComponent.Range) + enemy.GetX();
    int goalY = rng->getInt(strategyComponent.Range * -1, strategyComponent.Range) + enemy.GetY();

    int timesTried = 0;
    while (cave.IsWall(goalX, goalY))
    {
        timesTried++;
        timesTried % 2 != 0 ? goalX > 0 ? goalX-- : goalX++ : goalY > 0 ? goalY-- : goalY++;

        if (timesTried > strategyComponent.Range * 2)
            return FindRandomFreeSpace(enemy, cave, strategyComponent); //:-/
    }

    Point p = Point{goalX, goalY};
    return p;
}


