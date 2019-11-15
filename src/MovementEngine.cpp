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
