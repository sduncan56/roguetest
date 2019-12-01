
#pragma once

#include <vector>

struct Point
{
    int x;
    int y;

    Point() {}

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point& p)
    {
        this->x = p.x;
        this->y = p.y;
    }
};

inline bool operator==(const Point &lhs, const Point &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

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

        bool IsWalkable(int x, int y);

        int getWidth();
        int getHeight();

        std::vector<bool> getLayout();
        



};