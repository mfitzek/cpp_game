#include "BoundingBox.h"



BoundingBox::BoundingBox(double x, double y, double width, double height){
    this->x1 = x;
    this->y1 = y;
    this->x2 = x + width;
    this->y2 = y + height;
}



bool BoundingBox::CheckCollision(const BoundingBox& other) const{
    return this->x1 < other.x2 &&
           this->x2 > other.x1 &&
           this->y1 < other.y2 &&
           this->y2 > other.y1;
}

bool BoundingBox::CheckCollision(const Line& line) const{
    bool left = line.CheckCollision(Line(x1, y1, x1, y2));
    bool right = line.CheckCollision(Line(x2, y1, x2, y2));
    bool top = line.CheckCollision(Line(x1, y1, x2, y1));
    bool bottom = line.CheckCollision(Line(x1, y2, x2, y2));

    return (left | right | top | bottom);
}