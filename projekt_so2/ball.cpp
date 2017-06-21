#include "ball.h"
#include <thread>
#include <unistd.h>

Ball::Ball(std::mutex* ball_mutex){
    this->posX = 40;
    this->posY = 10;
    this->dX = -1;
    this->dY = 1;
    this->running = true;
    this->ball_lost = false;
    this->ball_mutex = ball_mutex;
}

int Ball::getX(){
    return posX;
}

int Ball::getY(){
    return posY;
}

void Ball::run(){
    
}

void Ball::animate(std::mutex * m_lock){
    while(this->running){
        if (! this->ball_lost && this->ball_mutex->try_lock()){
            this->ball_mutex->unlock();
            usleep(250000);
            this->check_collisions();
            m_lock->lock();
            this->clear_ball();
            this->move_ball();
            this->draw_ball();
            m_lock->unlock();
        }
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
        this->ball_lost = true;
    }

    for(int i = 0; i < this->wall->bricks.size(); i++){
            if (this->posX >= this->wall->bricks[i]->getPosX() && this->posX <= this->wall->bricks[i]->getPosX() + this->wall->bricks[i]->getWidth())
                if (this->posY >= this->wall->bricks[i]->getPosY() && this->posY <= this->wall->bricks[i]->getPosY() + this->wall->bricks[i]->getHeight()){
                    if (this->posY == this->wall->bricks[i]->getPosY() || this->posY == this->wall->bricks[i]->getPosY() + this->wall->bricks[i]->getHeight())
                        this->dY *= -1;
                    else
                        this->dX *= -1;
                    wall->remove_ball(i);
                    this->ball_mutex->lock();
                    break;
                } 
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

void Ball::setWall(Wall* wall){
    this->wall = wall;
}