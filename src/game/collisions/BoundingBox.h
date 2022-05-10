#pragma once



#include "Line.h"



class BoundingBox {

    public:

        double x1, y1, x2, y2;

        BoundingBox(double x, double y, double width, double height);
        bool CheckCollision(const Line& line) const;
        bool CheckCollision(const BoundingBox& other) const;


};