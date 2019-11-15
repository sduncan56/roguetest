#include "Entity.h"


Entity::Entity(int x, int y) {
    SetPosition(x, y);  
}

void Entity::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;     
}

std::pair<int, int> Entity::GetPosition() {
    return std::pair<int, int>(x, y);
}

int Entity::GetX() {
    return x;
}

int Entity::GetY() {
    return y;
}
