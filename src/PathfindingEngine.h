#pragma once

#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <tuple>

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

struct Comp
{
    bool operator()(const PFNode *lhs, const PFNode *rhs)
    {
        return lhs->priority > rhs->priority;
    }
};

class PathfindingEngine
{
    private:
        std::map<std::tuple<int, int>, PFNode*> existingNodes;
        PFNode* GetExit(int x, int y);
        void CalculateExits(Cave* cave, PFNode* node);


    public:
        PathfindingEngine();
        std::stack<Point*> FindPathTo(Point start, Point goal, Cave& cave);
        

};