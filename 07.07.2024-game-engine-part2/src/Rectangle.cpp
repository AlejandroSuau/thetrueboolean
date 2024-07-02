#include "Rectangle.h"

Rectangle::Rectangle(float position_x, float position_y, float width, float height)
    : x(position_x), y(position_y), w(width), h(height) {}

Rectangle::Rectangle()
    : x(0.f), y(0.f), w(0.f), h(0.f) {}

bool Rectangle::IsCollidingWith(const Rectangle& other) const {
    return (x < other.x + other.w && // El lado izquierdo de este rectángulo está a la izquierda del lado derecho del otro
            x + w > other.x && // El lado derecho de este rectángulo está a la derecha del lado izquierdo del otro
            y < other.y + other.h && // El lado superior de este rectángulo está por encima del lado inferior del otro
            y + h > other.y); // El lado inferior de este rectángulo está por debajo del lado superior del otro
}
