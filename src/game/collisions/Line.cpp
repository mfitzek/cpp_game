#include "Line.h"



Line::Line(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

bool Line::CheckCollision(const Line& other) const{

    int s10_x = this->x2 - this->x1;
    int s10_y = this->y2 - this->y1;
    int s32_x = other.x2 - other.x1; 
    int s32_y = other.y2 - other.y1; 

    int denom = s10_x * s32_y - s32_x * s10_y;

    if (denom == 0)
        return false;

    bool denom_is_positive = denom > 0;

    int s02_x = this->x1 - other.x1;
    int s02_y = this->y1 - other.y1;


    int s_numer = s10_x * s02_y - s10_y * s02_x;

    if ((s_numer < 0) == denom_is_positive)
        return false;

    int t_numer = s32_x * s02_y - s32_y * s02_x;

    if ((t_numer < 0) == denom_is_positive)
        return false;

    if ((s_numer > denom) == denom_is_positive or (t_numer > denom) == denom_is_positive)
        return false;
    
    return true;

}