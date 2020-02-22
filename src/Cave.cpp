#include "Cave.h"
#include <assert.h>
#include <algorithm>

Cave::Cave(int width, int height) : max_width(width), max_height(height) {
    _layout.resize(width*height);
}

Cave::Cave(const Cave& old_cave) : max_width(old_cave.max_width), max_height(old_cave.max_height) {
    _layout = old_cave._layout;

}

bool Cave::IsWall(int x, int y) {
    if (x >= max_width || x <= 0) return true;
    if (y >= max_height || y <= 0) return true;

    assert(x * max_width + y < (int)_layout.size());

    return _layout[x * max_width + y];    
} 

void Cave::SetWall(int x, int y, bool isWall) {
    assert(x < max_width);
    assert(y < max_height);
    assert(x * max_width + y < (int)_layout.size());
    
    _layout[x * max_width + y] = isWall;
}

int Cave::getWidth() {
    return max_width;
}

int Cave::getHeight() {
    return max_height;
}

std::vector<bool> Cave::getLayout()
{
    return _layout;
}


bool Cave::IsWalkable(int x, int y) {
    if (x < 0 || x > max_width ||
        y < 0 || y > max_height)
            return false;

    return !IsWall(x, y);    
}
