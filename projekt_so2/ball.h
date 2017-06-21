#include <ncurses.h>
#include "paddle.h"
#include "wall.h"

class Ball {
    public:
        Ball();
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
    
    private:
        int posX;
        int posY;
        int dX;
        int dY;
        bool running;
        Paddle* paddle;
        Wall* wall;   
};