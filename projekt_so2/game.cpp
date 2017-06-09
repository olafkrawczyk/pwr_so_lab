#include "ball.h"
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include <thread>


int main(){
    Ball* ball = new Ball();
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    resizeterm(20, 80);
    std::thread t1(&Ball::animate, ball);
    
    while((ch = getch()) != KEY_F(2))
        continue;
    
    ball->destroy();
    t1.join();

    endwin();
    return 0;

}