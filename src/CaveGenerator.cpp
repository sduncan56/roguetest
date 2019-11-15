
#include "CaveGenerator.h"

#include "libtcod/libtcod.hpp"

#include <vector>

#include <chrono>
#include <thread>


#define DEBUG_DRAW 0

CaveGenerator::CaveGenerator()
{

}

Cave CaveGenerator::Generate(int width, int height)
{
    Cave cave = Cave(width, height);

    TCODRandom *rng = TCODRandom::getInstance();

    std::vector<std::pair<int, int>> wall_indices;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(rng->getInt(1, 10) > chanceToStartEmpty)
            {
                cave.SetWall(x, y, true);
            }
            else
                cave.SetWall(x, y, false);          
        }
    }

    for (int i = 0; i < numberOfSteps; i++)
    {
        cave = DoAutomataStep(cave);
    }

    return cave;
}
Cave CaveGenerator::DoAutomataStep(Cave cave)
{
    Cave newCave = cave;

    for (int x = 0; x < cave.getWidth(); x++)
    {
        for (int y = 0; y < cave.getHeight(); y++)
        {
            int count = CountWallsAroundPoint(cave, x, y);

            std::cout << count << std::endl;

            if (cave.IsWall(x, y))
            {
                if (count < removeWallThreshold)
                    newCave.SetWall(x, y, false);
                else
                    newCave.SetWall(x, y, true);
            }
            else
            {
                if (count > addWallThreshold)
                    newCave.SetWall(x, y, true);
                else
                    newCave.SetWall(x, y, false);
            }

            if (DEBUG_DRAW)
                DebugDraw(newCave, x, y);
        }
    }

    return newCave;
}

int CaveGenerator::CountWallsAroundPoint(Cave cave, int x, int y) {
  int count = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            int neighbourX = x + i;
            int neighbourY = y + j;

            if (i == 0 && j == 0)
                continue;

            if (neighbourX < 0 || neighbourY < 0 ||
                neighbourX >= cave.getWidth() || neighbourY >= cave.getHeight())
            {
                count++;
                continue;
            }


            if (cave.IsWall(neighbourX, neighbourY))
                count++;
        }
    }
    return count;
}

void CaveGenerator::DebugDraw(Cave cave, int curX, int curY)
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));


    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

    switch (key.vk)
    {
        case TCODK_SPACE:
            TCODConsole::root->waitForKeypress(true);
            break;
        default:
            break;
    }

    TCODConsole::root->clear();

    for (int x = 0; x < cave.getWidth(); x++)
    {
        for (int y = 0; y < cave.getHeight(); y++)
        {

            if (cave.IsWall(x, y))
                TCODConsole::root->setCharBackground(x, y, TCODColor::darkestCyan);
            if (x == curX && y == curY)
            {
                TCODConsole::root->setChar(x, y, 'o');
                TCODConsole::root->setCharForeground(x, y, TCODColor::pink);
            }
        }
    }
    TCODConsole::flush();
}
