#include <iostream>
using namespace std;

class Rectangle {
public:
    double length;
    double width;

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayInfo() {
        cout << "Длина: " << length
            << ", Ширина: " << width
            << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Rectangle rect;

    rect.length = 5;
    rect.width = 3;

    cout << "Информация о прямоугольнике:" << endl;
    rect.displayInfo();

    return 0;
}