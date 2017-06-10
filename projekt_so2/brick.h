#include <ncurses.h>

class Brick{
    public:
        Brick(int, int);
        Brick( const Brick &);
        ~Brick();
        void draw();
        void clear();
        Brick& operator=(const Brick& that);

    private:
        int posX;
        int posY;
        int width;
        int height;
};