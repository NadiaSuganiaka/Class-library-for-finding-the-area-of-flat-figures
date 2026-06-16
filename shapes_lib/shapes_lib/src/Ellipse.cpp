#include "../include/Ellipse.h"

static const double PI = 3.14159265358979323846;

Ellipse::Ellipse(double a, double b) : semiA(a), semiB(b) {
    if (a <= 0 || b <= 0)
        throw invalid_argument("Піввісі еліпса мають бути додатніми");
}

double Ellipse::area() const {
    return PI * semiA * semiB;
}

double Ellipse::perimeter() const {
    // Формула Рамануджана (наближення)
    double h = ((semiA - semiB) * (semiA - semiB)) / ((semiA + semiB) * (semiA + semiB));
    return PI * (semiA + semiB) * (1.0 + (3.0 * h) / (10.0 + sqrt(4.0 - 3.0 * h)));
}

double Ellipse::getInscribedCircle() const {
    return min(semiA, semiB);
}

double Ellipse::getCircumscribedCircle() const {
    return max(semiA, semiB);
}

string Ellipse::toString() const {
    return "Еліпс: a=" + fmt(semiA) + ", b=" + fmt(semiB)
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  r вписаного = " + fmt(getInscribedCircle())
        + "\n  R описаного = " + fmt(getCircumscribedCircle());
}

string Ellipse::serialize() const {
    return "{\"type\":\"Ellipse\","
           "\"params\":{\"semiA\":" + fmt(semiA) + ",\"semiB\":" + fmt(semiB) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
