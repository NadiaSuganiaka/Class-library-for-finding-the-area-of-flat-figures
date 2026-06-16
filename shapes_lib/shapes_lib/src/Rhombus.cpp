#include "../include/Rhombus.h"
#include <cmath>

static const double PI = 3.14159265358979323846;

// Ромб задається діагоналями.
// Сторона ромба: side = sqrt((d1/2)^2 + (d2/2)^2)
// Кут між сторонами: alpha = 2 * atan(d2 / d1) (у градусах) — передаємо у Parallelogram
static double calcAngle(double d1, double d2) {
    return 2.0 * atan2(d2, d1) * 180.0 / PI;
}

static double calcSide(double d1, double d2) {
    return sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
}

Rhombus::Rhombus(double d1, double d2)
    : Parallelogram(calcSide(d1, d2), calcSide(d1, d2), calcAngle(d1, d2)),
      d1(d1), d2(d2)
{
    if (d1 <= 0 || d2 <= 0)
        throw invalid_argument("Діагоналі ромба мають бути додатніми");
}

double Rhombus::area() const {
    return d1 * d2 / 2.0;
}

double Rhombus::perimeter() const {
    double side = sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
    return 4.0 * side;
}

double Rhombus::getInscribedCircle() const {
    // r = S / (P/2)
    double p = perimeter() / 2.0;
    return area() / p;
}

double Rhombus::getCircumscribedCircle() const {
    // Для загального ромба описане коло не існує (тільки для квадрата)
    return -1.0;
}

string Rhombus::getDiagonals() const {
    return "d1=" + fmt(d1) + ", d2=" + fmt(d2);
}

string Rhombus::toString() const {
    double side = sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
    return "Ромб: d1=" + fmt(d1) + ", d2=" + fmt(d2)
        + "\n  Сторона     = " + fmt(side)
        + "\n  Площа       = " + fmt(area())
        + "\n  Периметр    = " + fmt(perimeter())
        + "\n  r вписаного  = " + fmt(getInscribedCircle());
}

string Rhombus::serialize() const {
    return "{\"type\":\"Rhombus\","
           "\"params\":{\"d1\":" + fmt(d1) + ",\"d2\":" + fmt(d2) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
