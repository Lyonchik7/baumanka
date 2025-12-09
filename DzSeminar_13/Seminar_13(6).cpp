#include <iostream>
using namespace std;

class Shape {
protected:
    double length;

public:
    Shape(double l) {
        length = l;
    }

    virtual void displayInfo() {
        cout << "Длина: " << length << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;  

public:
    Rectangle(double l, double w) : Shape(l) {
        width = w;
    }

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayInfo() override {
        cout << "Длина: " << length
            << ", Ширина: " << width
            << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Rectangle rect(8.5, 4.2);

    cout << "Информация о прямоугольнике:" << endl;
    rect.displayInfo();

    return 0;
}