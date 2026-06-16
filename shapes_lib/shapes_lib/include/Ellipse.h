#pragma once
#include "Shape.h"

class Ellipse : public Shape {
private:
    double semiA, semiB; // велика і мала піввісі

public:
    Ellipse(double a, double b);

    double area() const override;
    double perimeter() const override;  // формула Рамануджана
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string toString() const override;
    string serialize() const override;
};
