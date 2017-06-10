#include "brick.h"
#include <ncurses.h>
#include <vector>


class Ball;
class Wall{
    public:
        Wall(int, int);
        void draw();
        void setBall(Ball *);
        void cleanup();
        void stop_cleanup();

    private:
        int bricks_rows;
        int bricks_cols;
        int gap;
        std::vector<Brick*> bricks;
        Ball* ball;
        bool stop;
};