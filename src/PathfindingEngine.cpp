#include "PathfindingEngine.h"

#include <map>
#include <iostream>
#include <vector>


PathfindingEngine::PathfindingEngine()
{}

PFNode* PathfindingEngine::GetExit(int x, int y)
{
    auto tpl = std::tuple<int, int>(x, y);
    PFNode* node = existingNodes.count(tpl) ? existingNodes[tpl] : new PFNode(x, y);
    existingNodes[tpl] = node;
    return node;

}

void PathfindingEngine::CalculateExits(Cave* cave, PFNode* node)
{
    if (cave->IsWalkable(node->x, node->y - 1))
        node->Exits.push_back(GetExit(node->x, node->y-1));
    if (cave->IsWalkable(node->x, node->y + 1))
        node->Exits.push_back(GetExit(node->x, node->y+1));
    if (cave->IsWalkable(node->x - 1, node->y))
        node->Exits.push_back(GetExit(node->x-1, node->y));
    if (cave->IsWalkable(node->x + 1, node->y))
        node->Exits.push_back(GetExit(node->x+1, node->y));
}

std::stack<Point*> PathfindingEngine::FindPathTo(Point start, Point goal, Cave& cave) {
    std::priority_queue<PFNode*, std::vector<PFNode*>, Comp> frontier;

    PFNode* n = new PFNode(start);

    frontier.push(n);

    std::map<Point*, Point*> cameFrom;
    std::map<Point*, int> costSoFar;

    cameFrom[&start] = nullptr;
    costSoFar[&start] = 0;

    PFNode* endNode = nullptr;


    while (!frontier.empty())
    {
        PFNode* current = frontier.top();
        frontier.pop();

        if (current->x == goal.x && current->y == goal.y)
        {
            endNode = current;
            break;
        }

  

        CalculateExits(&cave, current);

        printf("Current node: x: %d y: %d\n", current->x, current->y);
        printf("currently exploring:\n");
        for (PFNode* next : current->Exits)
        {
            printf("x: %d y: %d\n", next->x, next->y);
            int newCost = costSoFar[current] + next->cost;
            if (!costSoFar.count(next) || newCost < costSoFar[next])
            {
                costSoFar[next] = newCost;
                next->priority = newCost + (abs(goal.x - next->x) + abs(goal.y - next->y));
                frontier.push(next);
                cameFrom[next] = current;
            }
        }
        printf("continuing...\n");
              
    }

    std::stack<Point*> path;

    if (endNode != nullptr)
    {
        Point* cur = endNode;
        while (cur)
        {
            path.push(cur);
            cur = cameFrom[cur];
        }
        path.pop();

    }
    return path;


}
