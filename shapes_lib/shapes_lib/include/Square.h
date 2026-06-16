#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
private:
    double side;

public:
    Square(double side);

    double getInscribedCircle() const override;
    double getCircumscribedCircle() const override;
    string getDiagonals() const;
    string toString() const override;
    string serialize() const override;
};
