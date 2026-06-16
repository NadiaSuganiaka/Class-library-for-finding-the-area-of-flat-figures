CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/Shape.cpp \
      src/Triangle.cpp \
      src/Rectangle.cpp \
      src/Square.cpp \
      src/Circle.cpp \
      src/Ellipse.cpp \
      src/Parallelogram.cpp \
      src/Rhombus.cpp \
      src/Trapezoid.cpp \
      src/RegularPolygon.cpp \
      src/Polygon.cpp

DEMO_SRC = demo/main.cpp
TARGET = shapes_demo

all: $(TARGET)

$(TARGET): $(SRC) $(DEMO_SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(DEMO_SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
