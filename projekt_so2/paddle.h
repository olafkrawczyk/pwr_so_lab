#include <ncurses>

class Paddle {
    public:
        Paddle(Ball*);
        void move();
        void clear();
        void draw();


    private:
        inty posX, size;
};