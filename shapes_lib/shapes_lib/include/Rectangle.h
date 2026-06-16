#pragma once
#include "Shape.h"

class Rectangle : public Shape {
protected:
    double width, height;

public:
    Rectangle(double w, double h);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string getDiagonals() const;
    string toString() const override;
    string serialize() const override;
};
