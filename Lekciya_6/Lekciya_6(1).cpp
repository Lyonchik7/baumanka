#include <iostream>
#include <queue>
#include <string>
#include <windows.h>
using namespace std;

// Функция для добавления человека в очередь
void addToQueue(queue<string>& queue, const string& person) {
    queue.push(person);
    cout << person << " добавлен в очередь." << endl;
}

// Функция для обработки человека из очереди
void processQueue(queue<string>& queue) {
    if (queue.empty()) {
        cout << "Очередь пуста." << endl;
    }
    else {
        cout << queue.front() << " обработан и удален из очереди." << endl;
        queue.pop();
    }
}

// Функция для отображения текущего состояния очереди
void displayQueue(const queue<string>& q) {
    queue<string> temp = q; // Создаем копию для отображения

    if (temp.empty()) {
        cout << "Очередь пуста." << endl;
        return;
    }

    cout << "Текущая очередь: ";
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
        if (!temp.empty()) {
            cout << " <- ";
        }
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251); 

    queue<string> supermarketQueue;
    int choice;
    string name;

    cout << "Моделирование очереди в магазине" << endl;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить человека в очередь" << endl;
        cout << "2. Обработать человека из очереди" << endl;
        cout << "3. Показать текущую очередь" << endl;
        cout << "4. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите имя человека: ";
            cin.ignore(); // Очищаем буфер
            getline(cin, name);
            addToQueue(supermarketQueue, name);
            break;

        case 2:
            processQueue(supermarketQueue);
            break;

        case 3:
            displayQueue(supermarketQueue);
            break;

        case 4:
            cout << "Программа завершена." << endl;
            return 0;

        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}
