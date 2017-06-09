#include "ball.h"
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include "paddle.h"


int main(){
    Ball* ball = new Ball();
    Paddle* paddle = new Paddle();
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    resizeterm(20, 80);
    std::thread t_ball(&Ball::animate, ball);
    
     while((ch = getch()) != KEY_F(2)){
        paddle->move(ch);
     }    

    ball->destroy();
    t_ball.join();

    endwin();
    return 0;

}