#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

struct Employee {
    string name;
    int age;
    string position;
    double salary;
};

int main() {
    // Устанавливаем правильную кодировку для Windows
    SetConsoleCP(1251); // Кодировка ввода
    SetConsoleOutputCP(1251); // Кодировка вывода

    int n;
    cout << "Введите количество сотрудников: ";
    cin >> n;

    Employee* employees = new Employee[n];
    double totalSalary = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nВведите данные о сотруднике " << i + 1 << ":" << endl;

        cout << "Введите имя сотрудника: ";
        cin >> employees[i].name;

        cout << "Введите возраст сотрудника: ";
        cin >> employees[i].age;

        cout << "Введите должность сотрудника: ";
        cin >> employees[i].position;

        cout << "Введите зарплату сотрудника: ";
        cin >> employees[i].salary;

        totalSalary += employees[i].salary;
    }

    // Поиск самого молодого и самого старшего сотрудника
    int youngestIndex = 0;
    int oldestIndex = 0;

    for (int i = 1; i < n; i++) {
        if (employees[i].age < employees[youngestIndex].age) {
            youngestIndex = i;
        }
        if (employees[i].age > employees[oldestIndex].age) {
            oldestIndex = i;
        }
    }

    // Вывод результатов
    cout << "\n=== Результаты ===" << endl;

    cout << "Самый молодой сотрудник: "
        << employees[youngestIndex].name
        << ", возраст: " << employees[youngestIndex].age
        << ", должность: " << employees[youngestIndex].position
        << ", зарплата: " << employees[youngestIndex].salary << endl;

    cout << "Самый старший сотрудник: "
        << employees[oldestIndex].name
        << ", возраст: " << employees[oldestIndex].age
        << ", должность: " << employees[oldestIndex].position
        << ", зарплата: " << employees[oldestIndex].salary << endl;

    cout << "Средняя зарплата всех сотрудников: "
        << totalSalary / n << endl;

    delete[] employees;

    system("pause"); // Чтобы окно не закрылось сразу
    return 0;
}