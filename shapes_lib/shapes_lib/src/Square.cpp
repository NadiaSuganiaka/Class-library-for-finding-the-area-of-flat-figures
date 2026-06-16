#include "../include/Square.h"
#include <cmath>

Square::Square(double side) : Rectangle(side, side), side(side) {
    if (side <= 0)
        throw invalid_argument("Сторона квадрата має бути додатньою");
}

double Square::getInscribedCircle() const {
    return side / 2.0;
}

double Square::getCircumscribedCircle() const {
    return side * sqrt(2.0) / 2.0;
}

string Square::getDiagonals() const {
    return "d=" + fmt(side * sqrt(2.0));
}

string Square::toString() const {
    return "Квадрат: side=" + fmt(side)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  Діагональ  = " + getDiagonals()
        + "\n  r вписаного = " + fmt(getInscribedCircle())
        + "\n  R описаного = " + fmt(getCircumscribedCircle());
}

string Square::serialize() const {
    return "{\"type\":\"Square\","
           "\"params\":{\"side\":" + fmt(side) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
