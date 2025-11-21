#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string title;
    int priority;
    string deadline;
};

// Функция для записи в output.txt
void log(const string& message) {
    ofstream output("output.txt", ios::app);
    output << message << endl;
}

// Чтение задач из файла
vector<Task> readTasks() {
    vector<Task> tasks;
    ifstream file("tasks.txt");

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            Task task;
            task.title = line.substr(0, pos1);
            task.priority = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            task.deadline = line.substr(pos2 + 1);
            tasks.push_back(task);
        }
    }
    file.close();

    return tasks;
}

// Запись задач в файл
void writeTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.title << "|" << task.priority << "|" << task.deadline << endl;
    }
    file.close();
}

// 1. Создание задач
void createTasks() {
    vector<Task> tasks;

    cout << "Создание задач (пустое название для выхода):" << endl;
    log("Создание задач");

    while (true) {
        Task task;

        cout << "Название: ";
        getline(cin, task.title);
        if (task.title.empty()) break;

        cout << "Приоритет (1-10): ";
        cin >> task.priority;
        cin.ignore();

        cout << "Срок (ДД.ММ.ГГГГ): ";
        getline(cin, task.deadline);

        tasks.push_back(task);
        cout << "Задача добавлена!\n" << endl;
    }

    writeTasks(tasks);
    cout << "Задачи сохранены!" << endl;
}

// 2. Поиск задачи
void searchTask() {
    string name;
    cout << "Поиск задачи: ";
    getline(cin, name);

    log("Поиск: " + name);

    vector<Task> tasks = readTasks();
    bool found = false;

    for (const auto& task : tasks) {
        if (task.title.find(name) != string::npos) {
            cout << "Найдено: " << task.title << " | Приоритет: "
                << task.priority << " | Срок: " << task.deadline << endl;
            log("Найдено: " + task.title);
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
}

// 3. Сортировка задач
void sortTasks() {
    cout << "Сортировка: 1-по приоритету, 2-по сроку: ";
    int choice;
    cin >> choice;
    cin.ignore();

    vector<Task> tasks = readTasks();

    if (choice == 1) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.priority < b.priority;
            });
        log("Сортировка по приоритету");
    }
    else if (choice == 2) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.deadline < b.deadline;
            });
        log("Сортировка по сроку");
    }

    writeTasks(tasks);
    cout << "Отсортировано!" << endl;
}

// 4. Добавление задачи
void addTask() {
    Task task;

    cout << "Добавление задачи:" << endl;
    cout << "Название: ";
    getline(cin, task.title);

    cout << "Приоритет: ";
    cin >> task.priority;
    cin.ignore();

    cout << "Срок: ";
    getline(cin, task.deadline);

    vector<Task> tasks = readTasks();
    tasks.push_back(task);
    writeTasks(tasks);

    cout << "Задача добавлена!" << endl;
    log("Добавлена: " + task.title);
}

// 5. Задачи по приоритету
void tasksByPriority() {
    int priority;
    cout << "Максимальный приоритет: ";
    cin >> priority;
    cin.ignore();

    log("Задачи с приоритетом <= " + to_string(priority));

    vector<Task> tasks = readTasks();
    bool found = false;

    for (const auto& task : tasks) {
        if (task.priority <= priority) {
            cout << task.title << " | " << task.priority << " | " << task.deadline << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет задач!" << endl;
    }
}

// 6. Показать все задачи
void showAllTasks() {
    vector<Task> tasks = readTasks();

    cout << "Все задачи:" << endl;
    for (const auto& task : tasks) {
        cout << task.title << " | " << task.priority << " | " << task.deadline << endl;
    }
}

// Главное меню
int main() {
    // Очистка лога
    ofstream output("output.txt");
    output.close();

    while (true) {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1 - Создать задачи" << endl;
        cout << "2 - Найти задачу" << endl;
        cout << "3 - Сортировать" << endl;
        cout << "4 - Добавить задачу" << endl;
        cout << "5 - Задачи по приоритету" << endl;
        cout << "6 - Показать все" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выбор: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: createTasks(); break;
        case 2: searchTask(); break;
        case 3: sortTasks(); break;
        case 4: addTask(); break;
        case 5: tasksByPriority(); break;
        case 6: showAllTasks(); break;
        case 0:
            cout << "Выход!" << endl;
            return 0;
        default:
            cout << "Неверный выбор!" << endl;
        }
    }
}