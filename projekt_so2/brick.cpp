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
    refresh();
}

void Brick::clear(){
    for (int i = 0; i < this->height; i++)
        mvhline(this->posY + i, this->posX, ' ', this->width);
    refresh();        
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