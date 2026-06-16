#pragma once
#include "Shape.h"

class RegularPolygon : public Shape {
private:
    int n;        // кількість сторін (>= 3)
    double side;  // довжина кожної сторони

public:
    RegularPolygon(int n, double side);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string toString() const override;
    string serialize() const override;
};
