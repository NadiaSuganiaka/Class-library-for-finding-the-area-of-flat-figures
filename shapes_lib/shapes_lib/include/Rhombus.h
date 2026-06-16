#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram {
private:
    double d1, d2;

public:
    Rhombus(double d1, double d2);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string getDiagonals() const;
    string toString() const override;
    string serialize() const override;
};
