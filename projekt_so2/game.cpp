#include "ball.h"
#include "wall.h"
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include <thread>


void refresh_game();

int main(){
    Paddle* paddle = new Paddle();
    Ball* ball = new Ball();
    ball->setPaddle(paddle);
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    resizeterm(20, 80);
    std::thread ref_t(refresh_game);

    Wall* wall = new Wall(11, 2);
    wall->setBall(ball);
    wall->draw();

    std::thread t_ball(&Ball::animate, ball);
    std::thread t_wall(&Wall::cleanup, wall);
    
    paddle->draw();
     while((ch = getch()) != KEY_F(2)){
        paddle->move(ch);
     }    

    ball->destroy();
    wall->stop_cleanup();
    t_wall.join();
    t_ball.join();

    endwin();
    return 0;

}

void refresh_game(){
    while(true){
        usleep(50000);
        refresh();
    }
}