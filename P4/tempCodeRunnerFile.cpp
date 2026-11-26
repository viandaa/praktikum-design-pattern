#include <iostream>

using namespace std;

// ======================================================
// ABSTRACT CLASS
// ======================================================

// Shape adalah abstract class karena memiliki pure virtual function
class Shape {
public:
    // ABSTRACT FUNCTION / PURE VIRTUAL FUNCTION
    // Fungsi ini wajib diimplementasikan oleh class turunannya
    virtual void Draw() = 0;

    // ABSTRACT FUNCTION / PURE VIRTUAL FUNCTION
    // Fungsi ini wajib diimplementasikan oleh class turunannya
    virtual float GetArea() = 0;
};


// ======================================================
// CLASS TURUNAN 1: CIRCLE
// ======================================================

class Circle : public Shape {
private:
    float r;

public:
    Circle(float radius) : r(radius) {}

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak Draw() dari Shape
    void Draw() override {
        cout << "Drawing Circle" << endl;
    }

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak GetArea() dari Shape
    float GetArea() override {
        return 3.14f * r * r;
    }
};


// ======================================================
// CLASS TURUNAN 2: RECTANGLE
// ======================================================

class Rectangle : public Shape {
private:
    float p, l;

public:
    Rectangle(float panjang, float lebar)
        : p(panjang), l(lebar) {}

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak Draw() dari Shape
    void Draw() override {
        cout << "Drawing Rectangle" << endl;
    }

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak GetArea() dari Shape
    float GetArea() override {
        return p * l;
    }
};


// ======================================================
// CLASS TURUNAN 3: TRIANGLE
// ======================================================

class Triangle : public Shape {
private:
    float alas, tinggi;

public:
    // Constructor untuk mengisi alas dan tinggi
    Triangle(float a, float t)
        : alas(a), tinggi(t) {}

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak Draw() dari Shape
    void Draw() override {
        cout << "Drawing Triangle" << endl;
    }

    // OVERRIDE
    // Mengimplementasikan fungsi abstrak GetArea() dari Shape
    float GetArea() override {
        return 0.5f * alas * tinggi;
    }
};


// ======================================================
// MAIN PROGRAM
// ======================================================

int main() {

    // ARRAY POINTER SHAPE*
    // Dapat menyimpan object dari Circle, Rectangle, dan Triangle
    Shape* shapes[3];

    // Membuat object Circle
    shapes[0] = new Circle(5);

    // Membuat object Rectangle
    shapes[1] = new Rectangle(8, 5);

    // Membuat object Triangle
    shapes[2] = new Triangle(6, 4);


    // Menampilkan seluruh bentuk menggunakan array Shape*
    for (int i = 0; i < 3; i++) {

        // Memanggil fungsi Draw() sesuai object sebenarnya
        shapes[i]->Draw();

        // Memanggil fungsi GetArea() sesuai object sebenarnya
        cout << "Area = " << shapes[i]->GetArea() << endl;

        cout << endl;
    }


    // Menghapus object yang dibuat dengan new
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}