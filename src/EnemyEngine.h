#pragma once

#include "Entity.h"
#include "Cave.h"
#include "StrategyComponent.h"

class EnemyEngine
{
    private:

    public:
        EnemyEngine();
        void ConsiderStrategy(Entity& enemy, Cave& cave);
        Point FindRandomFreeSpace(Entity& enemy, Cave& cave, StrategyComponent& strategyComponent);
        void ConsiderMove(Entity& enemy, Cave& cave);
};