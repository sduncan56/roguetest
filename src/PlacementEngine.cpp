#include "PlacementEngine.h"

#include "libtcod/libtcod.hpp"

PlacementEngine::PlacementEngine() {
    
}

void PlacementEngine::PlaceInRandomSpace(Entity* entity, Cave* cave) {
   auto* rng = TCODRandom::getInstance();

   while (true)
   {
       int x = rng->getInt(0, cave->getWidth());
       int y = rng->getInt(0, cave->getHeight());

       if (!cave->IsWall(x, y))
       {
           entity->SetPosition(x, y);
           break;
       }
   }

}
