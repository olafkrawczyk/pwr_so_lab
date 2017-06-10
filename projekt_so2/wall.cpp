#include "wall.h"
#include <string>


Wall::Wall(int cols, int rows){
    this->bricks_cols = cols;
    this->bricks_rows = rows;
    this->gap = 1;
}

void Wall::draw(){
    int start_x; 
    int start_y;
    start_y = 1;
    
    for(int i = 0; i < this->bricks_rows; i++){
        start_x = 1;
        for(int k = 0; k < this->bricks_cols; k++){
            this->bricks.push_back(new Brick(start_x, start_y));
            start_x += this->gap + 6; // 4 = brick width
        }
        start_y += gap + 2; //2 = brick height
    }
    
    std::string data = "Bricks: " + std::to_string(this->bricks.size());
    printw(data.c_str());

    for (auto brick : this->bricks){
        brick->draw();
    }
	refresh();

}