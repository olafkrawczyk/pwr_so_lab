#include "paddle.h"

Paddle::Paddle(){
    
}

void Paddle::move(){
    int ch;

    while((ch = getch()) != KEY_F(2)){
        switch(ch){
            case KEY_LEFT:
				this->clear();
				--win.posX;
				this->draw();
				break;
			case KEY_RIGHT:
				this->clear();
				++win.posX;
				this->draw();
				break;
        }
        refresh();
    }
}

void Paddle::clear(){
    for(int i = this->posX; i < size; i++)
        mvaddch(19, i, ' ');
}

void Paddle::draw(){
    for(int i = this->posX; i < size; i++)
        mvaddch(19, i, '=');
}