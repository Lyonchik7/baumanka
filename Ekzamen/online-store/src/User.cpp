#include "User.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// ==================== Базовый класс User ====================

User::User(int id, const string& n, const string& e, const string& r)
    : userId(id), name(n), email(e), role(r) {}

void User::showMenu() {
    cout << "\n=== MENU ===\n";
    cout << "1. View orders\n";
    cout << "2. Create order\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "Your orders:\n";
        // Здесь будет вызов БД
    }
}

shared_ptr<Order> User::createOrder(DatabaseConnection<string>& db) {
    try {
        string sql = "INSERT INTO orders (user_id, status) VALUES (" + 
                     to_string(userId) + ", 'pending') RETURNING order_id";
        
        auto result = db.executeQuery(sql);
        if (!result.empty()) {
            int orderId = stoi(result[0][0]);
            auto order = make_shared<Order>(orderId, userId);
            orders.push_back(order);
            cout << "Order #" << orderId << " created\n";
            return order;
        }
    } catch (...) {}
    
    return nullptr;
}

string User::viewOrderStatus(int orderId, DatabaseConnection<string>& db) {
    try {
        string sql = "SELECT status FROM orders WHERE order_id = " + to_string(orderId);
        auto result = db.executeQuery(sql);
        if (!result.empty()) {
            return result[0][0];
        }
    } catch (...) {}
    
    return "Unknown";
}

// Аутентификация пользователя
unique_ptr<User> User::authenticate(DatabaseConnection<string>& db, 
                                    const string& email, 
                                    const string& pass) {
    try {
        // Простая проверка - в реальном приложении нужно проверять пароль
        if (email == "admin@store.com") {
            return make_unique<Admin>(1, "Admin", email);
        } else if (email == "customer1@store.com") {
            return make_unique<Customer>(2, "Customer", email);
        }
    } catch (...) {}
    
    return nullptr;
}

// ==================== Администратор ====================

Admin::Admin(int id, const string& n, const string& e) 
    : User(id, n, e, "admin") {}

void Admin::showMenu() {
    User::showMenu(); // Базовое меню
    cout << "4. Add product (Admin only)\n";
    cout << "5. View all orders (Admin only)\n";
}

bool Admin::hasPermission(const string& action) const {
    // Админ может всё
    return true;
}

bool Admin::addProduct(DatabaseConnection<string>& db, 
                      const string& name, 
                      double price, 
                      int quantity) {
    try {
        string sql = "INSERT INTO products (name, price, stock_quantity) VALUES ('" +
                     name + "', " + to_string(price) + ", " + to_string(quantity) + ")";
        
        db.executeNonQuery(sql);
        cout << "Product added: " << name << endl;
        return true;
    } catch (...) {
        return false;
    }
}

// ==================== Покупатель ====================

Customer::Customer(int id, const string& n, const string& e) 
    : User(id, n, e, "customer") {}

bool Customer::hasPermission(const string& action) const {
    // Покупатель может только просматривать и создавать заказы
    return action == "view_orders" || action == "create_order";
}

bool Customer::addToOrder(DatabaseConnection<string>& db, int orderId, 
                         int productId, int quantity) {
    try {
        // Получаем цену товара
        string priceSql = "SELECT price FROM products WHERE product_id = " + 
                         to_string(productId);
        auto priceResult = db.executeQuery(priceSql);
        
        if (priceResult.empty()) {
            cout << "Product not found\n";
            return false;
        }
        
        double price = stod(priceResult[0][0]);
        
        // Добавляем товар в заказ
        string sql = "INSERT INTO order_items (order_id, product_id, quantity, price) VALUES (" +
                     to_string(orderId) + ", " + to_string(productId) + ", " +
                     to_string(quantity) + ", " + to_string(price) + ")";
        
        db.executeNonQuery(sql);
        cout << "Product added to order\n";
        return true;
    } catch (...) {
        return false;
    }
}

// ==================== Менеджер ====================

Manager::Manager(int id, const string& n, const string& e) 
    : User(id, n, e, "manager") {}

bool Manager::hasPermission(const string& action) const {
    return action == "view_orders" || action == "update_status";
}
