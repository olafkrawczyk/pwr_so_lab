#include <ncurses.h>

class Paddle {
    public:
        Paddle();
        void move(int ch);
        void clear();
        void draw();
        int getPosX();
        int getSize();


    private:
        int posX, size;
};