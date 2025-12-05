#include <iostream>
#include <queue>
#include <string>
#include <windows.h>  
using namespace std;

// Добавляет событие в очередь
void addEvent(queue<string>& eventQueue, const string& event) {
    eventQueue.push(event);
    cout << "Событие добавлено: " << event << endl;
}

// Обрабатывает события из очереди
void processEvents(queue<string>& eventQueue) {
    if (eventQueue.empty()) {
        cout << "Очередь событий пуста." << endl;
        return;
    }

    cout << "\nОбработка событий:" << endl;
    int count = 0;

    while (!eventQueue.empty()) {
        count++;
        cout << count << ". Обрабатывается: " << eventQueue.front() << endl;
        eventQueue.pop();
    }

    cout << "Обработано событий: " << count << endl;
}

int main() {
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251); 

    queue<string> events;

    // Пример использования
    cout << "=== Сетевое приложение ===" << endl;

    addEvent(events, "Запрос от клиента 192.168.1.10: GET /index.html");
    addEvent(events, "Запрос от клиента 192.168.1.20: POST /login");
    addEvent(events, "Запрос от клиента 192.168.1.30: GET /api/data");

    processEvents(events);

    processEvents(events);

  
    system("pause");

    return 0;
}