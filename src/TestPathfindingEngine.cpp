
#ifdef UNIT_TESTING //this sucks and we should write a makefile to exclude tests from build
#define CATCH_CONFIG_MAIN

#include "extern/catch.hpp"
#include <iostream>

#include "PathfindingEngine.h"
#include "Cave.h"

#define DEBUG_DRAW false


namespace PathfindingTests
{
    const int size = 11;
    const char *narrowmap = 
                       "11111111111"
                       "10001111111"
                       "10000000111"
                       "11101110111"
                       "11101110011"
                       "11101111011"
                       "11100011011"
                       "11111011001"
                       "11111111111"
                       "11111111111"
                       "11111111111";

    const char* openmap =
                      "00100000000"
                      "00110101000"
                      "00001001000"
                      "00000001000"
                      "00001111110"
                      "00010000000"
                      "00010011000"
                      "00001000100"
                      "00000100010"
                      "00010011110"
                      "00010000000"
                      "00100000000";


    Cave* LoadCaveFromText(const char* text)
    {
        REQUIRE(true);
        Cave* cave = new Cave(size, size);

        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                cave->SetWall(x, y, (*(text + (y * size + x)) != '0'));
            }
        }

        return cave;
    }

    void debugDraw(Cave* cave, std::stack<Point*>& path, Point& start, Point& end)
    {
       std::vector<std::vector<char> > drawMap; 

        for (int i = 0; i < cave->getWidth(); i++)
        {
            std::vector<char> v;
            
            for (int j = 0; j < cave->getHeight(); j++)
            {
                v.push_back(cave->IsWall(j, i) ? 'X' : 'O');
            }
            drawMap.push_back(v);
        }

        while (!path.empty())
        {
            Point* p = path.top();
            path.pop();
            
            REQUIRE(cave->IsWalkable(p->x, p->y));

            drawMap[p->y][p->x] = 'P';
            delete p;
        }
        drawMap[start.y][start.x] = 'S';
        drawMap[end.y][end.x] = 'E';

        for (int i = 0; i < cave->getWidth(); i++)
        {            
            for (int j = 0; j < cave->getHeight(); j++)
            {
                std::cout << drawMap[i][j];
            }
            std::cout << std::endl;
        }
  
    }
    void checkWalkable(std::stack<Point*> path, Cave* cave)
    {
        Point* current = path.top();
        while (!path.empty())
        {
            REQUIRE(cave->IsWalkable(current->x, current->y));
            Point* del = current;
            path.pop();
            if (path.empty())
                break;

            current = path.top();

            delete del;

        }
        delete cave;
    }


    TEST_CASE("Complex Map", "[findspath]")
    {
        Cave* cave = LoadCaveFromText(openmap);

        PathfindingEngine pathfinding;
        Point start = Point(3, 0);
        Point end = Point(3, 8);

        REQUIRE(cave->IsWalkable(start.x, start.y));
        REQUIRE(cave->IsWalkable(end.x, end.y));


        std::stack<Point *> path = pathfinding.FindPathTo(start, end, *cave);

        REQUIRE(path.size() == 16);

        #if DEBUG_DRAW
        debugDraw(cave, path, start, end);
        #else
        checkWalkable(path, cave);
        #endif

    }

    TEST_CASE("Finds path", "[findspath]")
    {
        Cave* cave = LoadCaveFromText(narrowmap); 

        PathfindingEngine pathfinding;

        Point start = Point(1, 1);
        Point end = Point(5, 7);

        REQUIRE(cave->IsWalkable(start.x, start.y));
        REQUIRE(cave->IsWalkable(end.x, end.y));

        std::stack<Point *> path = pathfinding.FindPathTo(start, end, *cave);

        REQUIRE(!path.empty());
        REQUIRE(path.size() == 10);

        Point *current = path.top();

        REQUIRE(*current != start);

        checkWalkable(path, cave);


        
    }
} // namespace PathfindingTests

#endif
