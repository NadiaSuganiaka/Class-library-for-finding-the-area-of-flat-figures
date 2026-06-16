#include "../include/RegularPolygon.h"

static const double PI = 3.14159265358979323846;

RegularPolygon::RegularPolygon(int n, double side) : n(n), side(side) {
    if (n < 3)
        throw invalid_argument("Правильний многокутник має мати не менше 3 сторін");
    if (side <= 0)
        throw invalid_argument("Сторона правильного многокутника має бути додатньою");
}

double RegularPolygon::area() const {
    // S = (n * side^2 * cot(pi/n)) / 4
    return (n * side * side) / (4.0 * tan(PI / n));
}

double RegularPolygon::perimeter() const {
    return n * side;
}

double RegularPolygon::getInscribedCircle() const {
    // r = side / (2 * tan(pi/n))
    return side / (2.0 * tan(PI / n));
}

double RegularPolygon::getCircumscribedCircle() const {
    // R = side / (2 * sin(pi/n))
    return side / (2.0 * sin(PI / n));
}

string RegularPolygon::toString() const {
    return "Правильний " + to_string(n) + "-кутник: side=" + fmt(side)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  r вписаного = " + fmt(getInscribedCircle())
        + "\n  R описаного = " + fmt(getCircumscribedCircle());
}

string RegularPolygon::serialize() const {
    return "{\"type\":\"RegularPolygon\","
           "\"params\":{\"n\":" + to_string(n) + ",\"side\":" + fmt(side) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
