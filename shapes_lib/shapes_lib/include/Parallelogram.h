#pragma once
#include "Shape.h"

class Parallelogram : public Shape {
protected:
    double a, b, angle; // кут у градусах

public:
    Parallelogram(double a, double b, double angle);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string getDiagonals() const;
    string toString() const override;
    string serialize() const override;
};
