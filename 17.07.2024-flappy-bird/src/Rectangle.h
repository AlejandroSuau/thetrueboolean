#pragma once

class Rectangle {
public:
    Rectangle(float position_x, float position_y, float width, float height);
    Rectangle();

    bool IsCollidingWith(const Rectangle& other) const;

    float x, y, w, h;
};
