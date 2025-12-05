#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Product {
    string name;
    int quantity;
};

struct Order {
    int id;
    string customer;
    vector<Product> products;
};

void addOrder(queue<Order>& orders, const Order& newOrder) {
    orders.push(newOrder);
    cout << "Заказ #" << newOrder.id << " добавлен." << endl;
}

void processOrder(queue<Order>& orders) {
    if (orders.empty()) {
        cout << "Очередь пуста." << endl;
        return;
    }

    Order current = orders.front();
    cout << "\nОбработка заказа #" << current.id << endl;
    cout << "Клиент: " << current.customer << endl;
    cout << "Товары:" << endl;

    for (const auto& p : current.products) {
        cout << "  " << p.name << " (x" << p.quantity << ")" << endl;
    }

    orders.pop();
    cout << "Заказ обработан." << endl;
}

int main() {
    system("chcp 1251 > nul");

    queue<Order> orders;
    int id = 1;

    // Тестовые данные
    Order o1{ id++, "Иван", {{"Ноутбук", 1}, {"Мышь", 1}} };
    Order o2{ id++, "Мария", {{"Телефон", 1}, {"Чехол", 2}} };

    addOrder(orders, o1);
    addOrder(orders, o2);

    processOrder(orders);
    processOrder(orders);
    processOrder(orders); 

    return 0;
}
