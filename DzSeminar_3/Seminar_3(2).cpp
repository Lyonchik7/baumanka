#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int n = 0, count = 0;
	int* mas = new int[n];
	cout << "Введите кооличество членов последовательности:\n";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Введите элемент" << i + 1 << ":";
		cin >> mas[i];
	}


	int max = mas[0];

	for (int i = 0; i < n; i++) {
		if (mas[i] % 2 != 0) {
			if (max < mas[i]) {
				max = mas[i];
			}
		}
		else{
			count++;
		}
			
	}

	if (max % 2 == 0) {
		cout << "В последовательности только четные числа";
	}

	cout << "В последоваельности  " << count << "  четных чисел\n";
	cout << "Максимальное нечетное число последовательности:  " << max;

	delete[] mas;


	return 0;
}
