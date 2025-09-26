#include <iostream>
#include <cmath>


using namespace std;

// Функция для вычисления расстояния между точками
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    
    setlocale(LC_ALL, "RU");
    
    const int N = 4; 
    double x[N], y[N];

    cout << "Введите координаты " << N << " вершин прямоугольника:" << endl;
    cout << "Вводите вершины последовательно (по часовой или против часовой стрелки):" << endl;

    // Ввод координат вершин
    for (int i = 0; i < N; i++) {
        cout << "Вершина " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }

    // Находим две противоположные вершины (диагональ)
    double diagonal1 = distance(x[0], y[0], x[2], y[2]);
    double diagonal2 = distance(x[1], y[1], x[3], y[3]);

    double diagonal = diagonal1;

    cout << "Длина диагонали (между вершинами 1 и 3): " << diagonal1 << endl;
    cout << "Длина диагонали (между вершинами 2 и 4): " << diagonal2 << endl;
    cout << "Длина диагоналей прямоугольника: " << diagonal << endl;

    return 0;
}