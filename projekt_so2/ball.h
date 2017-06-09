#include <ncurses.h>

class Ball {
    public:
        Ball();
        int getX();
        int getY();
        void animate();
        void destroy();
        void check_collisions();
        void clear_ball();
        void draw_ball();
        void move_ball();
        void run();
    
    private:
        int posX;
        int posY;
        int dX;
        int dY;
        bool running;     
};