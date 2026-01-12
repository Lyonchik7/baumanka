#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "DatabaseConnection.h"
#include "User.h"

using namespace std;

int main() {
    try {
        // Подключение к базе данных
        auto db = make_unique<DatabaseConnection<string>>(
            "host=localhost dbname=online_store user=Leonid08=1234"
        );
        
        cout << "ONLINE STORE SYSTEM\n";
        cout << "===================\n";
        
        bool running = true;
        while (running) {
            cout << "\n1. Login as Admin\n";
            cout << "2. Login as Customer\n";
            cout << "3. Exit\n";
            cout << "Select: ";
            
            int choice;
            cin >> choice;
            
            if (choice == 3) break;
            
            // Авторизация
            string email;
            if (choice == 1) email = "admin@store.com";
            else email = "customer1@store.com";
            
            auto user = User::authenticate(*db, email, "123");
            
            if (user) {
                cout << "\nWelcome, " << user->getName() << "!\n";
                user->showMenu();
            }
        }
        
        cout << "Goodbye!\n";
        return 0;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
