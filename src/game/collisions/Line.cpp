#include "Line.h"



Line::Line(double x1, double y1, double x2, double y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

bool Line::CheckCollision(const Line& other) const{
    double uA = ((other.x2-other.x1)*(y1-other.y1) - (other.y2-other.y1)*(x1-other.x1)) / ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));
    double uB = ((x2-x1)*(y1-other.y1) - (y2-y1)*(x1-other.x1)) / ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));
    return (uA >= 0.0 && uA <= 1.0 && uB >= 0.0 && uB <= 1.0);
}

bool Line::IsHorizontal(){
    return CompareDouble(y1, y2);
}

bool Line::IsVertical(){
    return CompareDouble(x1, x2);
}
