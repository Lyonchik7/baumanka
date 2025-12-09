#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    setlocale(LC_ALL,"RU");
    
    int N;

    cout << "Введите количество секунд: ";
    cin >> N;

    cout << "Таймер обратного отсчёта запущен!" << endl;

    for (int i = N; i > 0; i--) {
        // Правильное склонение слова "секунда"
        if (i == 1) {
            cout << "Осталось: " << i << " секунда" << endl;
        }
        else if (i >= 2 && i <= 4) {
            cout << "Осталось: " << i << " секунды" << endl;
        }
        else {
            cout << "Осталось: " << i << " секунд" << endl;
        }

        // Пауза на 1 секунду
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Время вышло!" << endl;

    return 0;
}