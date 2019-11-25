#pragma once

#include <queue>

#include "Cave.h"

class PathfindingEngine
{
    private:

    public:
        PathfindingEngine();
        std::queue<Point> FindPathTo(Point start, Point goal, Cave& cave);
        

};