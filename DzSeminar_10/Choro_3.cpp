#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL,"RU");
    int total_seconds;

    cout << "Введите количество секунд: ";
    cin >> total_seconds;

    // Вычисляем часы, минуты и секунды
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    // Выводим результат
    cout << "\nРезультат: ";

    if (hours > 0) {
        if (hours == 1) cout << hours << " час ";
        else if (hours >= 2 && hours <= 4) cout << hours << " часа ";
        else cout << hours << " часов ";
    }

    if (minutes > 0) {
        if (minutes == 1) cout << minutes << " минута ";
        else if (minutes >= 2 && minutes <= 4) cout << minutes << " минуты ";
        else cout << minutes << " минут ";
    }

    if (seconds > 0 || (hours == 0 && minutes == 0)) {
        if (seconds == 1) cout << seconds << " секунда";
        else if (seconds >= 2 && seconds <= 4) cout << seconds << " секунды";
        else cout << seconds << " секунд";
    }

    cout << endl;

    return 0;
}