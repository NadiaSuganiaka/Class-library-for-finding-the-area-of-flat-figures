#include <iostream>
#include "../include/Shapes.h"

using namespace std;

// --- Демо-тести для кожної фігури ---

void testTriangle() {
    cout << "=== Трикутник ===" << endl;
    Triangle t(3, 4, 5);
    cout << t.toString() << endl;
    cout << "JSON: " << t.serialize() << endl;

    // Десеріалізація
    Shape* t2 = Shape::deserialize(t.serialize());
    cout << "Відновлено: площа=" << t2->area() << endl;
    delete t2;
    cout << endl;
}

void testRectangle() {
    cout << "=== Прямокутник ===" << endl;
    Rectangle r(6, 4);
    cout << r.toString() << endl;
    cout << "JSON: " << r.serialize() << endl << endl;
}

void testSquare() {
    cout << "=== Квадрат ===" << endl;
    Square s(5);
    cout << s.toString() << endl;
    cout << "JSON: " << s.serialize() << endl << endl;
}

void testCircle() {
    cout << "=== Коло ===" << endl;
    Circle c(7);
    cout << c.toString() << endl;
    cout << "JSON: " << c.serialize() << endl << endl;
}

void testEllipse() {
    cout << "=== Еліпс ===" << endl;
    Ellipse e(5, 3);
    cout << e.toString() << endl;
    cout << "JSON: " << e.serialize() << endl << endl;
}

void testParallelogram() {
    cout << "=== Паралелограм ===" << endl;
    Parallelogram p(8, 5, 60);
    cout << p.toString() << endl;
    cout << "JSON: " << p.serialize() << endl << endl;
}

void testRhombus() {
    cout << "=== Ромб ===" << endl;
    Rhombus r(6, 8);
    cout << r.toString() << endl;
    cout << "JSON: " << r.serialize() << endl << endl;
}

void testTrapezoid() {
    cout << "=== Трапеція ===" << endl;
    Trapezoid t(10, 6, 4);
    cout << t.toString() << endl;
    cout << "JSON: " << t.serialize() << endl << endl;
}

void testRegularPolygon() {
    cout << "=== Правильний шестикутник ===" << endl;
    RegularPolygon rp(6, 4);
    cout << rp.toString() << endl;
    cout << "JSON: " << rp.serialize() << endl << endl;
}

void testPolygon() {
    cout << "=== Довільний многокутник ===" << endl;
    vector<Point> pts = {
        Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3)
    };
    Polygon poly(pts);
    cout << poly.toString() << endl;
    cout << "JSON: " << poly.serialize() << endl << endl;
}

void testValidation() {
    cout << "=== Перевірка некоректних даних ===" << endl;

    try {
        Triangle t(1, 2, 10); // порушення нерівності трикутника
    } catch (const exception& e) {
        cout << "Очікувана помилка: " << e.what() << endl;
    }

    try {
        Circle c(-5); // від'ємний радіус
    } catch (const exception& e) {
        cout << "Очікувана помилка: " << e.what() << endl;
    }

    try {
        Trapezoid trap(5, 5, 3); // рівні основи
    } catch (const exception& e) {
        cout << "Очікувана помилка: " << e.what() << endl;
    }

    try {
        RegularPolygon rp(2, 5); // менше 3 сторін
    } catch (const exception& e) {
        cout << "Очікувана помилка: " << e.what() << endl;
    }

    cout << endl;
}

void testPolymorphism() {
    cout << "=== Поліморфізм: масив фігур ===" << endl;
    vector<Shape*> shapes = {
        new Triangle(3, 4, 5),
        new Rectangle(6, 4),
        new Square(5),
        new Circle(7),
        new Ellipse(5, 3),
        new Parallelogram(8, 5, 60),
        new Rhombus(6, 8),
        new Trapezoid(10, 6, 4),
        new RegularPolygon(6, 4),
        new Polygon({{0,0},{4,0},{4,3},{0,3}})
    };

    for (Shape* s : shapes) {
        cout << s->toString() << endl;
        cout << "---" << endl;
        delete s;
    }
}

int main() {
    testTriangle();
    testRectangle();
    testSquare();
    testCircle();
    testEllipse();
    testParallelogram();
    testRhombus();
    testTrapezoid();
    testRegularPolygon();
    testPolygon();
    testValidation();
    testPolymorphism();

    return 0;
}
