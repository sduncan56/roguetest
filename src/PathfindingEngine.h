#pragma once

#include <queue>
#include <vector>
#include <stack>

#include "Cave.h"

struct PFNode : Point
{
    std::vector<PFNode*> Exits;
    int priority;
    int cost = 1;

    PFNode(Point& p)
    {
        this->x = p.x;
        this->y = p.y;
    }

    PFNode(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

inline bool operator<(const PFNode& lhs, const PFNode& rhs)
{
    return lhs.priority < rhs.priority;
}


class PathfindingEngine
{
    private:

    public:
        PathfindingEngine();
        std::stack<Point*> FindPathTo(Point start, Point goal, Cave& cave);
        

};