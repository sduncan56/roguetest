#include "libtcod/libtcod.hpp"
#include "CaveGenerator.h"
#include "Cave.h"
#include "Entity.h"
#include "MovementEngine.h"


int main()
{
    MovementEngine movementEngine = MovementEngine();


    Entity player = Entity(40, 25);

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
            case TCODK_UP: 
                movementEngine.Move(&player, 0, -1, &cave); 
                break;
            case TCODK_DOWN: 
                movementEngine.Move(&player, 0, 1, &cave); 
                break;
            case TCODK_LEFT: 
                movementEngine.Move(&player, -1, 0, &cave); 
                break;
            case TCODK_RIGHT: 
                movementEngine.Move(&player, 1, 0, &cave); 
                break;
            default: break;
        }

        TCODConsole::root->clear();

        for (int x = 0; x < cave.getWidth(); x++)
        {
            for (int y = 0; y < cave.getHeight(); y++)
            {
                if (cave.IsWall(x, y))
                    TCODConsole::root->setCharBackground(x, y, TCODColor::brass);
                //TCODConsole::root->putChar(x, y, cave.at(x, y));

            }
        }

        auto playerPos = player.GetPosition();

        TCODConsole::root->putChar(playerPos.first, playerPos.second, '@');


        TCODConsole::flush();
    }
    return 0;
}