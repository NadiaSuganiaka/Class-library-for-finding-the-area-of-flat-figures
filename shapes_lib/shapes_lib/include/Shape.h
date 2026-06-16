#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

// Структура точки для многокутника
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Абстрактний базовий клас
class Shape {
public:
    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual double getInscribedCircle() const = 0;
    virtual double getCircumscribedCircle() const = 0;
    virtual string toString() const = 0;
    virtual string serialize() const = 0;

    // Статичний метод десеріалізації — реалізований в Shape.cpp
    static Shape* deserialize(const string& json);

protected:
    // Допоміжна функція: округлення до 6 знаків після коми
    static string fmt(double v) {
        ostringstream ss;
        ss << fixed << setprecision(6) << v;
        return ss.str();
    }
};
