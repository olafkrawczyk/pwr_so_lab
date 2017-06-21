#include "paddle.h"

Paddle::Paddle(std::mutex* ball_mutex){
    this->size = 6;
    this->posX = 37;
    this->draw();
    this->ball_mutex = ball_mutex;
}

void Paddle::move(int ch){
    if (this->posX >= 1 && ch == KEY_LEFT){
        this->clear();
        --posX;
        this->draw();
    }
    else if (this->posX <= 73 && ch == KEY_RIGHT){
        this->clear();
        ++posX;
        this->draw();
    }
    this->ball_mutex->unlock();
}

void Paddle::clear(){
    mvhline(19, this->posX, ' ', this->size);
}

void Paddle::draw(){
    mvhline(19, this->posX, '=', this->size);
}

int Paddle::getPosX(){
    return this->posX;
}

int Paddle::getSize(){
    return this->size;
}