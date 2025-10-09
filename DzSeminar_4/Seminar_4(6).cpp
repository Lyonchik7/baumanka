#include <iostream>

using namespace std;

// Функция для вычисления определителя матрицы 2x2
double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

int main() {
    setlocale(LC_ALL, "RU");

    /*
    Система уравнений:
    // 2x + 3y = 13
    // 5x - y = 9
    */
    cout << "Решение системы методом Крамера:" << endl;
    cout << "2x + 3y = 13" << endl;
    cout << "5x - y = 9" << endl;
    cout << endl;

    // Основной определитель
    double det = determinant(2, 3, 5, -1);
    cout << "Основной определитель:" << endl;
    cout << "|2   3|" << endl;
    cout << "|5  -1| = 2*(-1) - 3*5 = " << 2 * (-1) << " - " << 3 * 5 << " = " << det << endl;
    cout << endl;

    // Определитель для x (замена первый столбец)
    double det_x = determinant(13, 3, 9, -1);
    cout << "Определитель для x:" << endl;
    cout << "|13   3|" << endl;
    cout << "|9   -1| = 13*(-1) - 3*9 = " << 13 * (-1) << " - " << 3 * 9 << " = " << det_x << endl;
    cout << endl;

    // Определитель для y (замена второй столбец)
    double det_y = determinant(2, 13, 5, 9);
    cout << "Определитель для y:" << endl;
    cout << "|2  13|" << endl;
    cout << "|5   9| = 2*9 - 13*5 = " << 2 * 9 << " - " << 13 * 5 << " = " << det_y << endl;
    cout << endl;

    // Проверяем, имеет ли система решение
    if (det != 0) {
        double x = det_x / det;
        double y = det_y / det;

        cout << "Решение:" << endl;
        cout << "x = det_x / det = " << det_x << " / " << det << " = " << x << endl;
        cout << "y = det_y / det = " << det_y << " / " << det << " = " << y << endl;
        cout << endl;
    }
    else {
        cout << "Система не имеет единственного решения (определитель = 0)" << endl;
    }

    return 0;
}