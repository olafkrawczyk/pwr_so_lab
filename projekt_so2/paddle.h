#include <ncurses.h>
#pragma once
#include <mutex>

class Paddle {
    public:
        Paddle(std::mutex*);
        void move(int ch);
        void clear();
        void draw();
        int getPosX();
        int getSize();

    private:
        int posX, size;
        std::mutex *ball_mutex;
};