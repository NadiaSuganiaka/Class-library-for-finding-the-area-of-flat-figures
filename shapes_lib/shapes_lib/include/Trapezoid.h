#pragma once
#include "Shape.h"

class Trapezoid : public Shape {
private:
    double a, b, height; // a, b — основи; height — висота

public:
    Trapezoid(double a, double b, double h);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string toString() const override;
    string serialize() const override;
};
