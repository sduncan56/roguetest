#pragma once

#include "Entity.h"
#include "Cave.h"
#include "StrategyComponent.h"

class EnemyEngine
{
    private:

    public:
        EnemyEngine();
        Point FindRandomFreeSpace(Entity& enemy, Cave& cave, StrategyComponent& strategyComponent);
        void ConsiderMove(Entity& enemy, Cave& cave);
};