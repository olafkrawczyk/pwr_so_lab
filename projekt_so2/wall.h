#include <ncurses.h>
#include <vector>
#pragma once
#include "brick.h"
#include <mutex>

class Ball;
class Wall{
    public:
        Wall(int, int);
        void draw();
        void setBall(Ball *);
        void cleanup();
        void stop_cleanup();
        void print_bricks_count();
        void remove_ball(int);
        std::vector<Brick*> bricks;
        std::mutex wall_mutex;

    private:
        int bricks_rows;
        int bricks_cols;
        int gap;
        Ball* ball;
        bool stop;
};