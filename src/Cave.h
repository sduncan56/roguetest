
#pragma once

#include <vector>

class Cave
{
    private:
        std::vector<bool> _layout;

        int max_width;
        int max_height;

    public:
        Cave(int width, int height);
        Cave(const Cave&);

        bool IsWall(int x, int y);
        void SetWall(int x, int y, bool isWall);

        int getWidth();
        int getHeight();

        std::vector<bool> getLayout();
        



};