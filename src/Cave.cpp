#include "Cave.h"
#include <assert.h>
#include <algorithm>

Cave::Cave(int width, int height) : max_width(width), max_height(height) {
    _layout.resize(width*height);
}

Cave::Cave(const Cave& old_cave) : max_width(old_cave.max_width), max_height(old_cave.max_height) {
    _layout = old_cave._layout;

}

char Cave::at(int x, int y) {

    assert(x < max_width);
    assert(y < max_height);
    assert(x * max_width + y < (int)_layout.size());

    return _layout[x * max_width + y];    
} 

void Cave::set(int x, int y, char c) {
    assert(x < max_width);
    assert(y < max_height);
    assert(x * max_width + y < (int)_layout.size());
    
    _layout[x * max_width + y] = c;
}





int Cave::getWidth() {
    return max_width;
}

int Cave::getHeight() {
    return max_height;
}

std::vector<char> Cave::getLayout()
{
    return _layout;
}

