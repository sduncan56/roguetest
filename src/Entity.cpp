#include "Entity.h"
#include <assert.h>


Entity::Entity() {
    SetPosition(x, y);  
}

void Entity::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;     
}

Point Entity::GetPosition() {
    return Point(x, y);
}

int Entity::GetX() {
    return x;
}

int Entity::GetY() {
    return y;
}





