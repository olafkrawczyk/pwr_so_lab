#include "brick.h"

Brick::Brick(int x, int y){
    this->posX = x;
    this->posY = y;
    this->width = 6;
    this->height = 2;
}

Brick::Brick( const Brick & brick ){
    this->posX = brick.posX;
    this->posY = brick.posY;
    this->width = 6;
    this->height = 2;
}


void Brick::draw(){
    for (int i = 0; i < this->height; i++){
        mvhline(this->posY + i, this->posX, '|', this->width);
    }
}

void Brick::clear(){
    for (int i = 0; i < this->height; i++)
        for (int k = 0; k < this->width; k++){
            mvaddch(posY + i, posX + k, ' ');
        }
}

Brick::~Brick(){
    this->clear();
}

Brick& Brick::operator=(const Brick& brick)
{
    this->posX = brick.posX;
    this->posY = brick.posY;
    this->width = 6;
    this->height = 2;

    return *this;
}

int Brick::getPosX(){
    return this->posX;
}


int Brick::getPosY(){
    return this->posY;
}

int Brick::getHeight(){
    return this->height;
}

int Brick::getWidth(){
    return this->width;
}