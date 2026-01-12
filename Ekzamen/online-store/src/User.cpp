#include "User.hpp"
#include <iostream>

using namespace std;

// ========== User ==========
User::User(int id, const string& n, const string& e, const string& r)
    : userId(id), name(n), email(e), role(r) {}

void User::displayMenu() {
    cout << "\nWelcome, " << name << "!\n";
    cout << "Role: " << role << endl;
}

// ========== Admin ==========
Admin::Admin(int id, const string& n, const string& e) 
    : User(id, n, e, "admin") {}

void Admin::displayMenu() {
    User::displayMenu();
    cout << "\nAdmin Menu:\n";
    cout << "1. Add product\n";
    cout << "2. View orders\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "Product added (simulated)\n";
    } else if (choice == 2) {
        cout << "Showing orders...\n";
    }
}

bool Admin::hasPermission(const string& action) const {
    return true;
}

bool Admin::addProduct(DatabaseConnection<string>& db) {
    try {
        db.executeNonQuery(
            "INSERT INTO products (name, price, stock_quantity) "
            "VALUES ('New Product', 100.0, 50)"
        );
        cout << "Product added\n";
        return true;
    } catch (...) {
        return false;
    }
}

// ========== Customer ==========
Customer::Customer(int id, const string& n, const string& e) 
    : User(id, n, e, "customer") {}

void Customer::displayMenu() {
    User::displayMenu();
    cout << "\nCustomer Menu:\n";
    cout << "1. Create order\n";
    cout << "2. View my orders\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "Order created (simulated)\n";
    } else if (choice == 2) {
        cout << "Your orders:\n";
    }
}

bool Customer::hasPermission(const string& action) const {
    return action == "view_own_orders" || action == "create_order";
}

shared_ptr<Order> Customer::createOrder(DatabaseConnection<string>& db) {
    cout << "Creating order...\n";
    // Простая реализация
    return make_shared<Order>(1, userId);
}

// ========== Manager ==========
Manager::Manager(int id, const string& n, const string& e) 
    : User(id, n, e, "manager") {}

void Manager::displayMenu() {
    User::displayMenu();
    cout << "\nManager menu\n";
}

bool Manager::hasPermission(const string& action) const {
    return action == "view_orders" || action == "update_status";
}

// ========== Аутентификация ==========
unique_ptr<User> User::authenticate(DatabaseConnection<string>& db, 
                                    const string& email, 
                                    const string& password) {
    try {
        // Простая проверка
        if (email == "admin@store.com") {
            return make_unique<Admin>(1, "Admin", email);
        } else if (email == "customer1@store.com") {
            return make_unique<Customer>(2, "Customer", email);
        } else if (email == "manager@store.com") {
            return make_unique<Manager>(3, "Manager", email);
        }
    } catch (...) {
        // Игнорируем ошибки
    }
    
    cout << "Login failed\n";
    return nullptr;
}
