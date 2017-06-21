#include "paddle.h"

Paddle::Paddle(){
    this->size = 6;
    this->posX = 37;
    this->draw();
}

void Paddle::move(int ch){
    switch(ch){
        case KEY_LEFT:
            this->clear();
            --posX;
            this->draw();
            break;
        case KEY_RIGHT:
            this->clear();
            ++posX;
            this->draw();
            break;
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