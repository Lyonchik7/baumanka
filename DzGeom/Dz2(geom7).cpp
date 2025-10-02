#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n = 0;
	cout << "Количество вершин:";
	cin >> n;

	double x[100], y[100];

	for (int i = 0; i < n; i++) {
		cout << "Вершина" << i + 1 << "(x y):" << endl;
		cin >> x[i] >> y[i];
	}

	double px, py;
	cout << "Точка (x y):";
	cin >> px >> py;

	int count = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;

		// Прверяем пересечение горизонтального луча с отрезком
		if ((y[i] > py) != (y[j] > py)) {
			//Вычисляем точку пересечения
			double intersect = (x[j] - x[i]) * (py - y[i]) / (y[j] - y[i]) + x[i];

			if (px < intersect) {
				count++;
			}
		}
	}

	if (count % 2 == 1) {
		cout << "Точка ВНУТРИ многоугольника\n";
	}
	else {
		cout << "Точка СНАРУЖИ многоугольника\n";
	}


	return 0;
}
