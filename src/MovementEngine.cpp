#include "MovementEngine.h"


MovementEngine::MovementEngine() {
    
}



bool MovementEngine::Move(Entity* entity, 
                          int vectorX, int vectorY, Cave* cave) {
    
    int newX = entity->GetX()+vectorX;
    int newY = entity->GetY()+vectorY;

    if (!cave->IsWall(newX, newY))
        entity->SetPosition(newX, newY);

    return true;
}

bool MovementEngine::Move(Entity* entity, Point* tile, Cave* cave) {
    int vecX = tile->x-entity->GetX();
    int vecY = tile->y-entity->GetY();

    return Move(entity, vecX, vecY, cave);
}
