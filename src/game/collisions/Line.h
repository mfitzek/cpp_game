#pragma once




class Line{
    public:
        int x1, y1, x2, y2;
        Line(int x1, int y1, int x2, int y2);
        bool CheckCollision(const Line& other) const;
};