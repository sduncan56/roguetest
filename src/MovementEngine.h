

#pragma once

#include "Cave.h"
#include "Entity.h"

class MovementEngine
{
    private:

    public:
        MovementEngine();
        bool Move(Entity* entity, int vectorX, int vectorY, Cave* cave);
};