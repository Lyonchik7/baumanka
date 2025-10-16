#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    srand(time(nullptr)); // при каждом запуске комбинация меняется

    // Создаем вектор из 10 случайных чисел от -50 до 50
    vector<int> numbers;
    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 101 - 50; // от -50 до 50
        numbers.push_back(random_num);
    }

    // Выводим исходный вектор
    cout << "Исходный вектор: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        cout << num << " ";
    }
        cout << endl;

    // Удаляем все отрицательные числа с помощью std::remove_if и лямбды
    numbers.erase(
        remove_if(numbers.begin(), numbers.end(),
            [](int n) {
                return n < 0; // условие: true для отрицательных чисел
            }),
        numbers.end()
    );

    // Выводим результат
    cout << "После удаления отрицательных: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        cout << num << " ";
    }
    cout << endl;

    return 0;
}