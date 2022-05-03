#include "Line.h"



Line::Line(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

bool Line::CheckCollision(const Line& other) const{
    float uA =
     ((other.x2-other.x1)*(y1-other.y1) - (other.y2-other.y1)*(x1-other.x1))
     / 
     ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));

    float uB = 
    ((x2-x1)*(y1-other.y1) - (y2-y1)*(x1-other.x1)) 
    / 
    ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));

    return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}