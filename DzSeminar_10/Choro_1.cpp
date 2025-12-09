#include <iostream>
#include <chrono>

using namespace std;

// Функция вычисления суммы чисел от 1 до N
long long calculateSum(int N) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "Введите N: ";
    cin >> N;

    // Засекаем время начала
    auto start = chrono::high_resolution_clock::now();

    // Выполняем вычисление
    long long result = calculateSum(N);

    // Засекаем время окончания
    auto end = chrono::high_resolution_clock::now();

    // Вычисляем разницу в миллисекундах
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Выводим результаты
    cout << "Сумма чисел от 1 до " << N << " = " << result << endl;
    cout << "Время выполнения: " << duration.count() << " миллисекунд" << endl;

    return 0;
}