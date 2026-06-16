#pragma once
#include "Shape.h"
#include <vector>

class Polygon : public Shape {
private:
    vector<Point> vertices;

    double gaussArea() const; // формула Гаусса (внутрішня)

public:
    Polygon(const vector<Point>& pts);

    double area() const override;
    double perimeter() const override;
    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string toString() const override;
    string serialize() const override;
};
