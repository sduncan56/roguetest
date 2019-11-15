#pragma once

#include <utility>

class Entity
{
    private:
        int x, y;

    public:
        Entity(int x, int y);
        Entity();

        void SetPosition(int x, int y);
        std::pair<int, int> GetPosition();
        int GetX();
        int GetY();


};