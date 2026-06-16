#pragma once
#include "Shape.h"

class Triangle : public Shape {
private:
    double a, b, c;

public:
    // Конструктор: три сторони, перевірка нерівності трикутника
    Triangle(double a, double b, double c);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string getDiagonals() const;
    string toString() const override;
    string serialize() const override;
};
