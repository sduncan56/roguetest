#include "libtcod/libtcod.hpp"
#include "CaveGenerator.h"
#include "Cave.h"


int main()
{
    int playerx=40, playery=25;

    TCODConsole::initRoot(80,55,"libtcod test", false);


    CaveGenerator caveGen = CaveGenerator();
    Cave cave = caveGen.Generate(50, 50);

    while(!TCODConsole::isWindowClosed())
    {

         TCOD_key_t key;
        TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS
        ,&key, NULL);

        switch(key.vk)
        {
            case TCODK_UP: playery--; break;
            case TCODK_DOWN: playery++; break;
            case TCODK_LEFT: playerx--; break;
            case TCODK_RIGHT: playerx++; break;
            default: break;
        }

        TCODConsole::root->clear();

        for (int x = 0; x < cave.getWidth(); x++)
        {
            for (int y = 0; y < cave.getHeight(); y++)
            {
                if (cave.at(x, y) == 'X')
                    TCODConsole::root->setCharBackground(x, y, TCODColor::brass);
                //TCODConsole::root->putChar(x, y, cave.at(x, y));

            }
        }

        TCODConsole::root->putChar(playerx, playery, '@');


        TCODConsole::flush();
    }
    return 0;
}