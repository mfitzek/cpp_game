#pragma once
#include "../utils/utils.h"



class Line{
    public:
        double x1, y1, x2, y2;
        Line(double x1, double y1, double x2, double y2);
        bool CheckCollision(const Line& other) const;
        bool IsVertical();
        bool IsHorizontal();
};