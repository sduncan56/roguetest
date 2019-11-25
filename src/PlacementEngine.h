#pragma once

#include "Entity.h"
#include "Cave.h"

class PlacementEngine
{
    private:

    public:
        PlacementEngine();
        void PlaceInRandomSpace(Entity& entity, Cave& cave);
};