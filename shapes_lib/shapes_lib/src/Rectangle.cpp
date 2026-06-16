#include "../include/Rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    if (w <= 0 || h <= 0)
        throw invalid_argument("Сторони прямокутника мають бути додатніми");
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2.0 * (width + height);
}

double Rectangle::getInscribedCircle() const {
    // r = min(w, h) / 2
    return min(width, height) / 2.0;
}

double Rectangle::getCircumscribedCircle() const {
    // R = sqrt(w^2 + h^2) / 2
    return sqrt(width * width + height * height) / 2.0;
}

string Rectangle::getDiagonals() const {
    double d = sqrt(width * width + height * height);
    return "d=" + fmt(d);
}

string Rectangle::toString() const {
    return "Прямокутник: width=" + fmt(width) + ", height=" + fmt(height)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  Діагональ  = " + getDiagonals()
        + "\n  r вписаного = " + fmt(getInscribedCircle())
        + "\n  R описаного = " + fmt(getCircumscribedCircle());
}

string Rectangle::serialize() const {
    return "{\"type\":\"Rectangle\","
           "\"params\":{\"width\":" + fmt(width) + ",\"height\":" + fmt(height) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
