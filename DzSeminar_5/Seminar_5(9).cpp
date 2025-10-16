#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 20;
    vector<int> power(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение вектора случайными мощностями
    for (int i = 0; i < n; ++i) {
        power[i] = rand() % 201 - 50;  // Диапазон от -50 до 150
    }

    // 1) Удаление всех значений меньше 0
    auto condition = [](int x) {
        return x < 0;
        };

    power.erase(remove_if(power.begin(), power.end(), condition), power.end());

    cout << "Мощности двигателя:" << endl;
    for_each(power.begin(), power.end(), [](int powers) {
        cout << powers << " ";
        });
    cout << endl;

    
    // 2) Поиск минимальной, максимальной и средней мощности
    auto max = max_element(power.begin(), power.end());
    auto min = min_element(power.begin(), power.end());
    cout << "\nМаксимальная мощность: " << *max << endl;
    cout << "Минимальная мощность: " << *min << endl;

    double sum = static_cast<double>(accumulate(power.begin(), power.end(), 0)) / power.size();
    cout << "Средняя мощность: " << sum << endl;

    // 3) Проверка работал ли двигатель всё время в пределах от 10 до 90 кВт
    auto out_diapazon = find_if(power.begin(), power.end(),
        [](auto x) { return x < 10 || x > 90; });

    cout << "\nПроверка работы в пределах 10-90 кВт: ";
    if (out_diapazon == power.end()) {
        cout << "ДА - двигатель работал в нормальном диапазоне" << endl;
    }
    else {
        cout << "НЕТ - были выходы за пределы диапазона" << endl;
        cout << "Первое недопустимое значение: " << *out_diapazon << " кВт" << endl;
    }

    // 4) Отсортировать значения по возрастанию и вывести медиану
    vector<int> sorted_power = power;
    sort(sorted_power.begin(), sorted_power.end());

    cout << "\nОтсортированный вектор мощностей:" << endl;
    for_each(sorted_power.begin(), sorted_power.end(), [](int powers) {
        cout << powers << "  ";
        });
    cout << endl;

    // Исправлено вычисление медианы
    double median = 0.0;
    int size = sorted_power.size();  // Используем реальный размер вектора
        
    double middle1 = sorted_power[size / 2 - 1];
    double middle2 = sorted_power[size / 2];
    median = (middle1 + middle2) / 2.0;
    
    cout << "\nМедиана: " << median << endl;

    return 0;
}