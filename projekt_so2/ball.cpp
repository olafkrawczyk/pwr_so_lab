#include "ball.h"
#include <thread>
#include <unistd.h>

Ball::Ball(){
    this->posX = 40;
    this->posY = 10;
    this->dX = -1;
    this->dY = 1;
    this->running = true;
}

int Ball::getX(){
    return posX;
}

int Ball::getY(){
    return posY;
}

void Ball::run(){
    
}

void Ball::animate(){
    while(this->running){
        usleep(500000);
        this->clear_ball();
        this->check_collisions();
        this->move_ball();
        this->draw_ball();
        refresh();
    }
}

void Ball::destroy(){
    this->running = false;
}

void Ball::clear_ball(){
    mvaddch(this->posY, this->posX, ' ');
}

void Ball::check_collisions(){
    if (this->posX + this->dX >= 80 || this->posX + this-> dY <= 0)
        dX *= -1;
    if (this->posY + this->dY >= 20 || this->posY + this-> dY <= 0)
        dY *= -1;
}

void Ball::move_ball(){
    this->posX += this->dX;
    this->posY += this->dY;    
}

void Ball::draw_ball(){
    mvaddch(this->posY, this->posX, 'O');
}