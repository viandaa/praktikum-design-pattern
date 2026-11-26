#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() {
        return 0;
    }

    virtual string getName() {
        return "Shape";
    }

    virtual ~Shape() {}
};

class Square : public Shape {
    float side;

public:
    Square(float s) {
        side = s;
    }

    float getArea() override {
        return side * side;
    }

    string getName() override {
        return "Square";
    }
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float getArea() override {
        return 3.14f * radius * radius;
    }

    string getName() override {
        return "Circle";
    }
};

class Triangle : public Shape {
    float base, height;

public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }

    float getArea() override {
        return 0.5f * base * height;
    }

    string getName() override {
        return "Triangle";
    }
};

int main() {
    Shape* s1 = new Square(5);
    Shape* s2 = new Circle(3);
    Shape* s3 = new Triangle(4, 6);

    cout << "=== Area Calculator ===" << endl;

    cout << s1->getName()
         << " area = "
         << s1->getArea()
         << endl;

    cout << s2->getName()
         << " area = "
         << s2->getArea()
         << endl;

    cout << s3->getName()
         << " area = "
         << s3->getArea()
         << endl;

    delete s1;
    delete s2;
    delete s3;

    return 0;
}