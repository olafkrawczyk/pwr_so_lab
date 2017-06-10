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
        usleep(250000);
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
    if (this->posX + this->dX >= 80 || this->posX + this->dX == -1)
        dX *= -1;
    if (this->posY + this->dY == -1)
        dY *= -1;
    else if (this->posY == 18 && this->posX >= this->paddle->getPosX() && this->posX <= this->paddle->getSize() + this->paddle->getPosX() )
        dY *= -1;
    else if (this->posY > 18) {
        this->posX = 40;
        this->posY = 10;
        this->dX = -1;
        this->dY = 1;
    }
}

void Ball::move_ball(){
    this->posX += this->dX;
    this->posY += this->dY;    
}

void Ball::draw_ball(){
    mvaddch(this->posY, this->posX, 'O');
}
void Ball::setPaddle(Paddle* paddle){
    this->paddle = paddle;
}