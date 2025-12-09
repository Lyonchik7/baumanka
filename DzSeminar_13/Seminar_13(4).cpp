#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;  
    double width;  

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

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
    Rectangle rect(5.5, 3.2);

    cout << "Информация о прямоугольнике:" << endl;
    rect.displayInfo();

    return 0;
}