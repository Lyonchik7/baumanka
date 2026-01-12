#include <iostream>
#include <memory>
#include "DatabaseConnection.hpp"
#include "User.hpp"

using namespace std;

int main() {
    try {
        // Подключение к базе данных
        auto db = make_unique<DatabaseConnection<string>>(
            "host=localhost dbname=online_store user=Leonid08=1234"
        );
        
        cout << "=== ONLINE STORE ===\n";
        
        // Простое меню
        while (true) {
            cout << "\n1. Admin login\n";
            cout << "2. Customer login\n";
            cout << "3. Exit\n";
            cout << "Choice: ";
            
            int choice;
            cin >> choice;
            
            if (choice == 3) break;
            
            // Авторизация
            string email = (choice == 1) ? "admin@store.com" : "customer1@store.com";
            auto user = User::authenticate(*db, email, "123");
            
            if (user) {
                user->displayMenu();
            }
        }
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
