#include "brick.h"
#include <ncurses.h>
#include <vector>


class Wall{
    public:
        Wall(int, int);
        void draw();

    private:
        int bricks_rows;
        int bricks_cols;
        int gap;
        std::vector<Brick*> bricks;
};