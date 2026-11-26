#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float getArea() { //fungsi virtual
        return 0;
    }

    virtual string getName() {
        return "Shape";
    }

    virtual ~Shape() {} //destructor visual agar aman jika pakai delete
};

class Square : public Shape {
    float side;
public:
    Square(float s) { side = s; }

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
    Circle(float r) { radius = r; }

    float getArea() override {
        return 3.14f * radius * radius;
    }

    string getName() override {
        return "Circle";
    }
};

int main() {
    //membuat pointer ke kelas dasar
    Shape* s1 = new Square(5);
    Shape* s2 = new Circle(3);

    cout << "=== Area Calculator ===" << endl;
    cout << s1->getName() << " area: " << s1->getArea() << endl;
    cout << s2->getName() << " area: " << s2->getArea() << endl;

    delete s1;
    delete s2;
}