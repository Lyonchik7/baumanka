#include <iostream>
using namespace std;


union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    };
};

int main() {
    DateTime dt;

    cout << "Введите год: ";
    cin >> dt.year;

    cout << "Введите месяц: ";
    cin >> dt.month;

    cout << "Введите день: ";
    cin >> dt.day;

    cout << "Введите час: ";
    cin >> dt.hour;

    cout << "Введите минуту: ";
    cin >> dt.minute;

    cout << "Введите секунду: ";
    cin >> dt.second;

    cout << "\nДата и время: ";
    cout << dt.year << "-" << dt.month << "-" << dt.day << " ";
    cout << dt.hour << ":" << dt.minute << ":" << dt.second << endl;

    return 0;
}