#include <iostream>
#include <cmath>

using namespace std;


double triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Функция для подсчета площади в 1 задаче
    double squaire = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return squaire;
}



int main()
{
    setlocale(LC_ALL, "RU");

    // задача 1

    double coord[3][2];

    cout << "Введите координаты вершин треугольника" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Вершина" << i + 1 << "(x, y)";
        cin >> coord[i][0] >> coord[i][1];
    }

    double x1 = coord[0][0], y1 = coord[0][1];
    double x2 = coord[1][0], y2 = coord[1][1];
    double x3 = coord[2][0], y3 = coord[2][1];

    double squaire = triangle(x1, x2, x3, y1, y2, y3);
    cout << " Площадь: " << squaire << endl;


    //задача 3

    double centr[3][2];

    cout << "Введите координаты вершин треугольника" << endl;

    for (int j = 0; j < 3; j++) {
        cout << "Вершина" << j + 1 << "(x, y)";
        cin >> centr[j][0] >> centr[j][1];
    }

    double x4 = centr[0][0], y4 = centr[0][1];
    double x5 = centr[1][0], y5 = centr[1][1];
    double x6 = centr[2][0], y6 = centr[2][1];

    double c_x = (x4 + x5 + x6) / 3;
    double c_y = (y4 + y5 + y6) / 3;

    cout << "координаты центра масс: (" << c_x << "," << c_y << ")" << endl;


    return 0;
}

