#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 50;
    vector<int> speeds(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение вектора случайными скоростями от 0 до 180
    for (int i = 0; i < n; ++i) {
        speeds[i] = rand() % 181;  // от 0 до 180
    }

    cout << "Все скорости автомобиля:" << endl;
    for_each(speeds.begin(), speeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << endl;

    // 1) Отфильтруйте все превышения скорости > 120
    vector<int> overspeeds;
    copy_if(speeds.begin(), speeds.end(), back_inserter(overspeeds), [](int speed) {
        return speed > 120;
        });

    cout << "\nПревышения скорости (>120 км/ч):" << endl;
    for_each(overspeeds.begin(), overspeeds.end(), [](int speed) {
        cout << speed << " ";
        });
    cout << "\nКоличество превышений: " << overspeeds.size() << endl;

    // 2) Найдите среднюю скорость
    double average_speed = accumulate(speeds.begin(), speeds.end(), 0.0) / speeds.size();
    cout << "\nСредняя скорость: " << average_speed << " км/ч" << endl;

    // 3) Определите, были ли все значения больше 0 (двигался ли всегда)
    auto stopped_moment = find_if(speeds.begin(), speeds.end(), [](int speed) {
        return speed == 0;
        });

    if (stopped_moment == speeds.end()) {
        cout << "Автомобиль всегда двигался (все скорости > 0)" << endl;
    }
    else {
        cout << "Автомобиль останавливался (найдена скорость 0 км/ч)" << endl;

        // Подсчет остановок
        auto stop_count = count(speeds.begin(), speeds.end(), 0);
        cout << "Количество остановок: " << stop_count << endl;
    }

    // 4) Выведите 10 максимальных значений скорости
    vector<int> sorted_speeds = speeds;
    sort(sorted_speeds.begin(), sorted_speeds.end(), greater<int>());   // greater<int>() сортирует по убыванию

    cout << "\n10 максимальных скоростей:" << endl;
    for (int i = 0; i < 10 && i < sorted_speeds.size(); i++) {
        cout << sorted_speeds[i] << " ";
    }
    cout << endl;


    return 0;
}

