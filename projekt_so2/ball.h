#include <ncurses.h>
#include "paddle.h"
#include "wall.h"

class Ball {
    public:
        Ball(std::mutex*);
        int getX();
        int getY();
        void animate(std::mutex *);
        void destroy();
        void check_collisions();
        void clear_ball();
        void draw_ball();
        void move_ball();
        void run();
        void setPaddle(Paddle* pd);
        void setWall(Wall* wall);
        bool ball_lost;
    
    private:
        int posX;
        int posY;
        int dX;
        int dY;
        bool running;
        std::mutex* ball_mutex;
        Paddle* paddle;
        Wall* wall;   
};