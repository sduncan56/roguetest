
#pragma once

#include "Component.h"

struct DisplayComponent : Component
{
    char DisplayChar;

    DisplayComponent(char displayChar)
    {
        DisplayChar = displayChar;
    }

};