#include "paddle.h"

Paddle::Paddle(){
    this->size = 6;
    this->posX = 37;
    this->draw();
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