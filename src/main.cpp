#include "libtcod/libtcod.hpp"
#include "CaveGenerator.h"
#include "Cave.h"
#include "Entity.h"
#include "MovementEngine.h"
#include "PlacementEngine.h"
#include "DisplayComponent.h"
#include "EnemyEngine.h"

#include <memory>
#include <iostream>

#ifndef UNIT_TESTING
int main()
{
    MovementEngine movementEngine;
    PlacementEngine placementEngine;
    EnemyEngine enemyEngine;

    Entity player = Entity();

    std::shared_ptr<DisplayComponent> playerDisplay = std::make_shared<DisplayComponent>('@');
    
    player.AddComponent(playerDisplay);

    Entity enemy;
    enemy.AddComponent(std::make_shared<DisplayComponent>('g'));
    enemy.AddComponent(std::make_shared<StrategyComponent>());


    TCODConsole::initRoot(80,55,"libtcod test", false);


    CaveGenerator caveGen = CaveGenerator();
    Cave cave = caveGen.Generate(50, 50);

    placementEngine.PlaceInRandomSpace(player, cave);
    placementEngine.PlaceInRandomSpace(enemy, cave);


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
        auto dc = player.GetComponent<DisplayComponent>();

        enemyEngine.ConsiderStrategy(enemy, cave);

        auto enemyStrategyComponent = enemy.GetComponent<StrategyComponent>();
        if (enemyStrategyComponent->HasGoal && !enemyStrategyComponent->Path.empty())
        {
            auto next = enemyStrategyComponent->Path.top();

            movementEngine.Move(&enemy, next, &cave);

            enemyStrategyComponent->Path.pop();
            delete next;

        }
        

        TCODConsole::root->putChar(playerPos.x, playerPos.y, dc->DisplayChar);
        TCODConsole::root->putChar(enemy.GetX(), enemy.GetY(), enemy.GetComponent<DisplayComponent>()->DisplayChar);


        TCODConsole::flush();
    }
    return 0;
}
#endif