#include "PathfindingEngine.h"

#include <map>

std::queue<Point> PathfindingEngine::FindPathTo(Point start, Point goal, Cave& cave) {
    std::queue<Point*> frontier;

    frontier.push(&start);

    std::map<Point*, Point*> cameFrom;
    std::map<Point*, int> costSoFar;

    cameFrom[&start] = nullptr;
    costSoFar[&start] = 0;


    while (!frontier.empty())
    {
        Point* current = frontier.front();
        frontier.pop();

        if (*current == goal)
        {
            

        }
    }


}
