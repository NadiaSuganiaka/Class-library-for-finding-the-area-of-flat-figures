#include "../include/Shapes.h"
#include <stdexcept>

// Проста допоміжна функція: витягує числове значення з JSON-рядка за ключем
static double jsonDouble(const string& json, const string& key) {
    string search = "\"" + key + "\":";
    size_t pos = json.find(search);
    if (pos == string::npos)
        throw runtime_error("Ключ '" + key + "' не знайдено у JSON");
    pos += search.size();
    return stod(json.substr(pos));
}

static int jsonInt(const string& json, const string& key) {
    return (int)jsonDouble(json, key);
}

// Витягує тип фігури з поля "type":"..."
static string jsonType(const string& json) {
    string search = "\"type\":\"";
    size_t pos = json.find(search);
    if (pos == string::npos)
        throw runtime_error("Поле 'type' не знайдено у JSON");
    pos += search.size();
    size_t end = json.find('"', pos);
    return json.substr(pos, end - pos);
}

// Серіалізація у файл
void saveToFile(const Shape* shape, const string& filename) {
    ofstream f(filename);
    if (!f.is_open())
        throw runtime_error("Не вдалося відкрити файл для запису: " + filename);
    f << shape->serialize();
    f.close();
}

// Завантаження з файлу
string loadFromFile(const string& filename) {
    ifstream f(filename);
    if (!f.is_open())
        throw runtime_error("Не вдалося відкрити файл для читання: " + filename);
    string json, line;
    while (getline(f, line)) json += line;
    return json;
}

Shape* Shape::deserialize(const string& json) {
    string type = jsonType(json);

    if (type == "Triangle") {
        double a = jsonDouble(json, "a");
        double b = jsonDouble(json, "b");
        double c = jsonDouble(json, "c");
        return new Triangle(a, b, c);
    }
    if (type == "Rectangle") {
        double w = jsonDouble(json, "width");
        double h = jsonDouble(json, "height");
        return new Rectangle(w, h);
    }
    if (type == "Square") {
        double s = jsonDouble(json, "side");
        return new Square(s);
    }
    if (type == "Circle") {
        double r = jsonDouble(json, "radius");
        return new Circle(r);
    }
    if (type == "Ellipse") {
        double a = jsonDouble(json, "semiA");
        double b = jsonDouble(json, "semiB");
        return new Ellipse(a, b);
    }
    if (type == "Parallelogram") {
        double a = jsonDouble(json, "a");
        double b = jsonDouble(json, "b");
        double angle = jsonDouble(json, "angle");
        return new Parallelogram(a, b, angle);
    }
    if (type == "Rhombus") {
        double d1 = jsonDouble(json, "d1");
        double d2 = jsonDouble(json, "d2");
        return new Rhombus(d1, d2);
    }
    if (type == "Trapezoid") {
        double a = jsonDouble(json, "a");
        double b = jsonDouble(json, "b");
        double h = jsonDouble(json, "height");
        return new Trapezoid(a, b, h);
    }
    if (type == "RegularPolygon") {
        int n = jsonInt(json, "n");
        double side = jsonDouble(json, "side");
        return new RegularPolygon(n, side);
    }
    if (type == "Polygon") {
        // Витягуємо масив вершин вручну
        vector<Point> pts;
        size_t pos = json.find("\"vertices\":[");
        if (pos == string::npos)
            throw runtime_error("Вершини не знайдено у JSON");
        pos += 12;
        while (true) {
            size_t xp = json.find("\"x\":", pos);
            if (xp == string::npos) break;
            double x = stod(json.substr(xp + 4));
            size_t yp = json.find("\"y\":", xp);
            double y = stod(json.substr(yp + 4));
            pts.push_back(Point(x, y));
            pos = json.find('}', yp) + 1;
            if (pos >= json.size() || json[pos] == ']') break;
        }
        return new Polygon(pts);
    }

    throw runtime_error("Невідомий тип фігури: " + type);
}
