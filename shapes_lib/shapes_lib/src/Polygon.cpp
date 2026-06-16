#include "../include/Polygon.h"

Polygon::Polygon(const vector<Point>& pts) : vertices(pts) {
    if (pts.size() < 3)
        throw invalid_argument("Многокутник має мати не менше 3 вершин");
    if (fabs(gaussArea()) < 1e-10)
        throw invalid_argument("Вершини многокутника утворюють виродженого многокутника (площа = 0)");
}

// Формула Гаусса (формула шнурівки)
double Polygon::gaussArea() const {
    double sum = 0.0;
    int n = (int)vertices.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += vertices[i].x * vertices[j].y;
        sum -= vertices[j].x * vertices[i].y;
    }
    return sum / 2.0;
}

double Polygon::area() const {
    return fabs(gaussArea());
}

double Polygon::perimeter() const {
    double p = 0.0;
    int n = (int)vertices.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double dx = vertices[j].x - vertices[i].x;
        double dy = vertices[j].y - vertices[i].y;
        p += sqrt(dx*dx + dy*dy);
    }
    return p;
}

double Polygon::getInscribedCircle() const {
    // Наближення: r = S / p (точне для опуклих фігур)
    double p = perimeter() / 2.0;
    return area() / p;
}

double Polygon::getCircumscribedCircle() const {
    // Для довільного многокутника не визначено
    return -1.0;
}

string Polygon::toString() const {
    string s = "Многокутник (" + to_string(vertices.size()) + " вершини):\n  Вершини: ";
    for (int i = 0; i < (int)vertices.size(); i++) {
        s += "(" + fmt(vertices[i].x) + "," + fmt(vertices[i].y) + ")";
        if (i + 1 < (int)vertices.size()) s += " ";
    }
    s += "\n  Площа      = " + fmt(area());
    s += "\n  Периметр   = " + fmt(perimeter());
    return s;
}

string Polygon::serialize() const {
    string s = "{\"type\":\"Polygon\",\"params\":{\"vertices\":[";
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (i > 0) s += ",";
        s += "{\"x\":" + fmt(vertices[i].x) + ",\"y\":" + fmt(vertices[i].y) + "}";
    }
    s += "]},\"area\":" + fmt(area()) + ",\"perimeter\":" + fmt(perimeter()) + "}";
    return s;
}
