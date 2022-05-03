#pragma once



#include "Line.h"



class BoundingBox {

    public:

        int x1, y1, x2, y2;

        BoundingBox(int x, int y, int width, int height);
        bool CheckCollision(const Line& line) const;
        bool CheckCollision(const BoundingBox& other) const;


};