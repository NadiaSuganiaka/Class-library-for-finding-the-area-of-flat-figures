#include "../include/Trapezoid.h"

Trapezoid::Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {
    if (a <= 0 || b <= 0 || h <= 0)
        throw invalid_argument("Всі параметри трапеції мають бути додатніми");
    if (a == b)
        throw invalid_argument("Основи трапеції не можуть бути рівними (це паралелограм)");
}

double Trapezoid::area() const {
    return (a + b) / 2.0 * height;
}

double Trapezoid::perimeter() const {
    // Бічні сторони для рівнобічної трапеції: c = sqrt(h^2 + ((a-b)/2)^2)
    double leg = sqrt(height * height + ((a - b) / 2.0) * ((a - b) / 2.0));
    return a + b + 2.0 * leg;
}

double Trapezoid::getInscribedCircle() const {
    // r = S / p; для рівнобічної трапеції вписане коло існує коли a + b = 2*leg
    double p = perimeter() / 2.0;
    return area() / p;
}

double Trapezoid::getCircumscribedCircle() const {
    // Для загальної трапеції описане коло не визначене
    return -1.0;
}

string Trapezoid::toString() const {
    return "Трапеція: a=" + fmt(a) + ", b=" + fmt(b) + ", h=" + fmt(height)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  r вписаного = " + fmt(getInscribedCircle());
}

string Trapezoid::serialize() const {
    return "{\"type\":\"Trapezoid\","
           "\"params\":{\"a\":" + fmt(a) + ",\"b\":" + fmt(b) + ",\"height\":" + fmt(height) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
