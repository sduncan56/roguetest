
#pragma once

#include "Cave.h"

class CaveGenerator
{
    private:
        int chanceToStartEmpty = 6; //out of 10
        int removeWallThreshold = 3;
        int addWallThreshold = 4;
        int numberOfSteps = 6;  

        void DebugDraw(Cave cave, int curX, int curY);
 

    public:
        CaveGenerator();
        Cave Generate(int width, int height);
        Cave DoAutomataStep(Cave cave);
        int CountWallsAroundPoint(Cave cave, int x, int y);
};