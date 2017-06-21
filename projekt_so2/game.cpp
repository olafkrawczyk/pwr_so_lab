#include "ball.h"
#include "wall.h"
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include <thread>


void refresh_game(bool *, Wall *);
std::mutex screen_write_mutex;

int main(){
    Paddle* paddle = new Paddle();
    Ball* ball = new Ball();
    Wall* wall = new Wall(11, 2);
    ball->setPaddle(paddle);
    ball->setWall(wall);
    int ch;
    bool game_running = true;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    resizeterm(20, 80);
    std::thread ref_t(refresh_game, &game_running, wall);

    
    wall->setBall(ball);
    wall->draw();

    std::thread t_ball(&Ball::animate, ball, &screen_write_mutex);
    //std::thread t_wall(&Wall::cleanup, wall);
    
    paddle->draw();
     while((ch = getch()) != KEY_F(2)){
        paddle->move(ch);
     }

    game_running = false;
    ball->destroy();
    //wall->stop_cleanup();
    //t_wall.join();
    t_ball.join();
    ref_t.join();

    endwin();
    return 0;

}

void refresh_game(bool * game_ptr, Wall* wall){
    while(*game_ptr != false){
        usleep(50000);
        screen_write_mutex.lock();
        wall->print_bricks_count();
        screen_write_mutex.unlock();
        refresh();
    }
}