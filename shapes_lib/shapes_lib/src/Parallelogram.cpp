#include "../include/Parallelogram.h"

static const double PI = 3.14159265358979323846;

Parallelogram::Parallelogram(double a, double b, double angle)
    : a(a), b(b), angle(angle)
{
    if (a <= 0 || b <= 0)
        throw invalid_argument("Сторони паралелограма мають бути додатніми");
    if (angle <= 0 || angle >= 180)
        throw invalid_argument("Кут паралелограма має бути в інтервалі (0, 180)");
}

double Parallelogram::area() const {
    double rad = angle * PI / 180.0;
    return a * b * sin(rad);
}

double Parallelogram::perimeter() const {
    return 2.0 * (a + b);
}

double Parallelogram::getInscribedCircle() const {
    // r = S / (a + b) — для паралелограма з вписаним колом a==b (ромб), але загальна формула
    double rad = angle * PI / 180.0;
    // r = a * sin(кут) / 2 (висота / 2 якщо a==b, інакше — наближення через висоту)
    double h = b * sin(rad); // висота відносно сторони a
    return h / 2.0;
}

double Parallelogram::getCircumscribedCircle() const {
    // Для загального паралелограма описане коло не існує
    return -1.0;
}

string Parallelogram::getDiagonals() const {
    double rad = angle * PI / 180.0;
    // Теорема косинусів
    double d1 = sqrt(a*a + b*b - 2*a*b*cos(rad));
    double d2 = sqrt(a*a + b*b - 2*a*b*cos(PI - rad));
    return "d1=" + fmt(d1) + ", d2=" + fmt(d2);
}

string Parallelogram::toString() const {
    return "Паралелограм: a=" + fmt(a) + ", b=" + fmt(b) + ", angle=" + fmt(angle) + "°"
        + "\n  Площа      = " + fmt(area())
        + "\n  Периметр   = " + fmt(perimeter())
        + "\n  Діагоналі  : " + getDiagonals()
        + "\n  r вписаного = " + fmt(getInscribedCircle());
}

string Parallelogram::serialize() const {
    return "{\"type\":\"Parallelogram\","
           "\"params\":{\"a\":" + fmt(a) + ",\"b\":" + fmt(b) + ",\"angle\":" + fmt(angle) + "},"
           "\"area\":" + fmt(area()) + ","
           "\"perimeter\":" + fmt(perimeter()) + "}";
}
