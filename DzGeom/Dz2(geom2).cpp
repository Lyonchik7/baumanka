#include <iostream>
#include <cmath>


using namespace std;

// Задача 2
int main() {

    setlocale(LC_ALL, "RU");
    const int N = 4;
    double x[N], y[N];

    cout <<"Введите координаты"<< N <<"вершин четырехугольника"<< endl;
    cout <<"Введите вершины последовательно(по или против часовой стрелки)"<< endl;

    for (int i = 0; i < N; i++) {
        cout << "Вершина" << i + 1 <<"(x,y):";
        cin >> x[i] >> y[i];
    }

    double perimetr = 0.0;

    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;
        double dx = x[next] - x[i];
        double dy = y[next] - y[i];
        double distance = sqrt(dx * dx + dy * dy);
        perimetr += distance;
    }
    
    cout << "Периметр четырёхугольника" << perimetr << endl;

    return 0;
}






