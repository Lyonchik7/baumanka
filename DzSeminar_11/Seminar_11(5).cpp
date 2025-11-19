#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main() {
    setlocale(LC_ALL, "RU");

    Student students[] = {
        {1, "Иван Петров", 20, 4.5},
        {2, "Мария Сидорова", 19, 4.8},
        {3, "Алексей Иванов", 21, 4.2}
    };

    // Запись в файл
    ofstream out("students.dat", ios::binary);
    for (int i = 0; i < 3; i++) {
        out.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    out.close();

    // Чтение из файла
    ifstream in("students.dat", ios::binary);
    in.seekg(0, ios::end);
    int count = in.tellg() / sizeof(Student);
    in.seekg(0, ios::beg);

    Student read_students[10];
    in.read(reinterpret_cast<char*>(read_students), count * sizeof(Student));
    in.close();

    // Вывод результатов
    cout << "Всего студентов: " << count << endl;
    cout << "Список студентов:" << endl;

    Student best = read_students[0];
    for (int i = 0; i < count; i++) {
        cout << read_students[i].id << ". " << read_students[i].name
            << " - " << read_students[i].average_grade << endl;

        if (read_students[i].average_grade > best.average_grade) {
            best = read_students[i];
        }
    }

    cout << "Лучший студент: " << best.name << " (балл: " << best.average_grade << ")" << endl;

    return 0;
}