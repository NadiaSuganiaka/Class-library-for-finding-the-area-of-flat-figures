#include "../include/Triangle.h"

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw invalid_argument("Сторони трикутника мають бути додатніми");
    if (a + b <= c || a + c <= b || b + c <= a)
        throw invalid_argument("Порушена нерівність трикутника");
}

double Triangle::area() const {
    // Формула Герона
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::getInscribedCircle() const {
    // r = S / p
    double p = perimeter() / 2.0;
    return area() / p;
}

double Triangle::getCircumscribedCircle() const {
    // R = a*b*c / (4*S)
    return (a * b * c) / (4.0 * area());
}

string Triangle::getDiagonals() const {
    return "Трикутник не має діагоналей";
}

string Triangle::toString() const {
    return "Трикутник: a=" + fmt(a) + ", b=" + fmt(b) + ", c=" + fmt(c)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  r вписаного = " + fmt(getInscribedCircle())
        + "\n  R описаного = " + fmt(getCircumscribedCircle());
}

string Triangle::serialize() const {
    return "{\"type\":\"Triangle\","
           "\"params\":{\"a\":" + fmt(a) + ",\"b\":" + fmt(b) + ",\"c\":" + fmt(c) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
