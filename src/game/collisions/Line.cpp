#include "Line.h"



Line::Line(double x1, double y1, double x2, double y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

// bool Line::CheckCollision(const Line& other) const{

//     double s10_x = this->x2 - this->x1;
//     double s10_y = this->y2 - this->y1;
//     double s32_x = other.x2 - other.x1; 
//     double s32_y = other.y2 - other.y1; 

//     double denom = s10_x * s32_y - s32_x * s10_y;

//     if (denom == 0)
//         return false;

//     bool denom_is_positive = denom > 0;

//     double s02_x = this->x1 - other.x1;
//     double s02_y = this->y1 - other.y1;


//     double s_numer = s10_x * s02_y - s10_y * s02_x;

//     if ((s_numer < 0) == denom_is_positive)
//         return false;

//     double t_numer = s32_x * s02_y - s32_y * s02_x;

//     if ((t_numer < 0) == denom_is_positive)
//         return false;

//     if ((s_numer > denom) == denom_is_positive or (t_numer > denom) == denom_is_positive)
//         return false;
    
//     return true;

// }

bool Line::CheckCollision(const Line& other) const{

    double uA = ((other.x2-other.x1)*(y1-other.y1) - (other.y2-other.y1)*(x1-other.x1)) / ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));
    double uB = ((x2-x1)*(y1-other.y1) - (y2-y1)*(x1-other.x1)) / ((other.y2-other.y1)*(x2-x1) - (other.x2-other.x1)*(y2-y1));
    return (uA >= 0.0 && uA <= 1.0 && uB >= 0.0 && uB <= 1.0);

    // double denominator = ((x2 - x1) * (other.y2 - other.y1)) - ((y2 - y1) * (other.x2 - other.x1));
    // double numerator1 = ((y1 - other.y1) * (other.x2 - other.x1)) - ((x1 - other.x1) * (other.y2 - other.y1));
    // double numerator2 = ((y1 - other.y1) * (x2 - x1)) - ((x1 - other.x1) * (y2 - y1));

    // // Detect coincident lines (has a problem, read below)
    // if (denominator == 0) return numerator1 == 0 && numerator2 == 0;
    
    // double r = numerator1 / denominator;
    // double s = numerator2 / denominator;

    // return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
}