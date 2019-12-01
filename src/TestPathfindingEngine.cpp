
#define CATCH_CONFIG_MAIN
#include "extern/catch.hpp"

#include "PathfindingEngine.h"
#include "Cave.h"

TEST_CASE("Finds path", "[findspath]")
{
    int width = 11;
    int height = 8;
    Cave cave = Cave(width, height);
    const char* text = "11111111111"
                       "10001111111"
                       "10000000111"
                       "11101110111"
                       "11101110011"
                       "11101111011"
                       "11100011011"
                       "11111011001"
                       "11111111111";

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            cave.SetWall(x, y, static_cast<bool>(text+(x*width+y)));
        }
    }

    PathfindingEngine pathfinding;

    Point start = Point(1,1);
    Point end = Point(4,3);

    REQUIRE(cave.IsWalkable(start.x, start.y));
    REQUIRE(cave.IsWalkable(end.x, end.y));

    //pathfinding.FindPathTo()
}