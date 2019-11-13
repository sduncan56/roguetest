
#pragma once

#include <vector>

class Cave
{
    private:
        std::vector<char> _layout;

        int max_width;
        int max_height;

    public:
        Cave(int width, int height);
        Cave(const Cave&);

        char at(int x, int y);
        void set(int x, int y, char c);

        int getWidth();
        int getHeight();

        std::vector<char> getLayout();
        



};