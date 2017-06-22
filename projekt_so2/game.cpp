#include "ball.h"
#include "wall.h"
#include <thread>
#include <ncurses.h>
#include <unistd.h>
#include <thread>


void refresh_game(bool *, Wall *);
void game_timer(bool *);
std::mutex screen_write_mutex;
std::mutex ball_mutex;

int main(){
    Paddle* paddle = new Paddle(&ball_mutex);
    Ball* ball = new Ball(&ball_mutex);
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
    std::thread timer_g(game_timer, &game_running);
    
    paddle->draw();
     while((ch = getch()) != KEY_F(2)){
        paddle->move(ch);
        if (ball->ball_lost){
            clear();
            mvprintw(10, 20, "YOU LOSE!");
            refresh();
            break;
        }
        else if(wall->bricks.size() == 0){
            clear();
            mvprintw(10, 20, "YOU WIN!");
            refresh();
            break;
        }
     }
    game_running = false;
    getch();
    ball->destroy();
    t_ball.join();
    ref_t.join();
    timer_g.join();

    endwin();
    return 0;
}

void refresh_game(bool * game_ptr, Wall* wall){
    while(*game_ptr != false){
        usleep(50000);
        screen_write_mutex.lock();
        wall->print_bricks_count();
        refresh();
        screen_write_mutex.unlock();
    }
}

void game_timer(bool* game_running){
    int time = 0;
    while(*game_running != false){
        std::string data = "Game time: " + std::to_string(time);
        mvprintw(0, 30, "                 ");
        mvprintw(0, 30, data.c_str());
        usleep(1000000);
        time++;
    }
}