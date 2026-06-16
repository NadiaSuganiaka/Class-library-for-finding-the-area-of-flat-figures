#include "../include/Circle.h"

static const double PI = 3.14159265358979323846;

Circle::Circle(double radius) : radius(radius) {
    if (radius <= 0)
        throw invalid_argument("Радіус кола має бути додатнім");
}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2.0 * PI * radius;
}

double Circle::getInscribedCircle() const {
    // Коло вписане в себе
    return radius;
}

double Circle::getCircumscribedCircle() const {
    // Коло описане навколо себе
    return radius;
}

string Circle::toString() const {
    return "Коло: radius=" + fmt(radius)
        + "\n  Площа         = " + fmt(area())
        + "\n  Довжина кола  = " + fmt(perimeter());
}

string Circle::serialize() const {
    return "{\"type\":\"Circle\","
           "\"params\":{\"radius\":" + fmt(radius) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
