#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct Student {
    string name;
    int age;
    double grade;
    int id;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "\nФИО: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Возраст: ";
    cin >> s.age;
    cout << "Средний балл: ";
    cin >> s.grade;
    cout << "Номер зачетки: ";
    cin >> s.id;
    students.push_back(s);
    cout << "Студент добавлен!\n";
}

void showAll() {
    if (students.empty()) {
        cout << "\nНет студентов\n";
        return;
    }

    cout << "\nСписок студентов:\n";
    for (const auto& s : students) {
        cout << s.name << ", " << s.age << " лет, "
            << "балл: " << s.grade << ", зачетка: " << s.id << endl;
    }
}

void findById() {
    int id;
    cout << "\nНомер зачетки: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Найден: " << s.name << ", " << s.age << " лет, "
                << "балл: " << s.grade << endl;
            return;
        }
    }
    cout << "Не найден\n";
}

void showAboveGrade() {
    double minGrade;
    cout << "\nМинимальный балл: ";
    cin >> minGrade;

    cout << "Студенты с баллом выше " << minGrade << ":\n";
    bool found = false;

    for (const auto& s : students) {
        if (s.grade > minGrade) {
            cout << s.name << " - " << s.grade << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Таких студентов нет\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;

    while (true) {
        cout << "\n1. Добавить\n2. Показать всех\n3. Найти\n4. Балл выше\n0. Выход\nВыбор: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: showAll(); break;
        case 3: findById(); break;
        case 4: showAboveGrade(); break;
        default: cout << "Ошибка\n";
        }
    }

    return 0;
}