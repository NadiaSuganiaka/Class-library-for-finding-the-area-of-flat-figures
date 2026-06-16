#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string toString() const override;
    string serialize() const override;
};
