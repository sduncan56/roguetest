#include "PathfindingEngine.h"

#include <map>


std::stack<Point*> PathfindingEngine::FindPathTo(Point start, Point goal, Cave& cave) {
    std::priority_queue<PFNode*> frontier;

    PFNode* n = new PFNode(start);

    frontier.push(n);

    std::map<Point*, Point*> cameFrom;
    std::map<Point*, int> costSoFar;

    cameFrom[&start] = nullptr;
    costSoFar[&start] = 0;


    while (!frontier.empty())
    {
        PFNode* current = frontier.top();
        frontier.pop();

        if (*current == goal)
            break;

        if (cave.IsWalkable(current->x, current->y-1))
            current->Exits.push_back(new PFNode(current->x, current->y-1));
        if (cave.IsWalkable(current->x, current->y+1))
            current->Exits.push_back(new PFNode(current->x, current->y+1));
        if (cave.IsWalkable(current->x-1, current->y))
            current->Exits.push_back(new PFNode(current->x-1, current->y));
        if (cave.IsWalkable(current->x+1, current->y))
            current->Exits.push_back(new PFNode(current->x+1, current->y));

        
        for (PFNode* next : current->Exits)
        {
            int newCost = costSoFar[current] + next->cost;
            if (!costSoFar.count(next) || newCost < costSoFar[next])
            {
                costSoFar[next] = newCost;
                next->priority = newCost + (abs(current->x - next->x) + abs(current->y - next->y));
                frontier.push(next);
                cameFrom[next] = current;
            }
        }
              
    }

    std::stack<Point*> path;

    if (cameFrom.count(&goal))
    {
        path.push(&goal);
        Point* cur = cameFrom[&goal];

        while (cur)
        {
            path.push(cur);
            cur = cameFrom[cur];
        }

    }
    return path;


}
