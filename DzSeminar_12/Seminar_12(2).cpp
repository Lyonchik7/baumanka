#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

struct BankAccount {
    int accountNumber;
    string ownerName;
    double balance;
};

int main() {
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251); 

    const int MAX_ACCOUNTS = 100;
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice = 0;

    // Инициализируем цикл
    while (choice != 5) {
        cout << "\nВыберите действие:\n";
        cout << "1. Создать новый банковский счет\n";
        cout << "2. Пополнить счет\n";
        cout << "3. Снять деньги со счета\n";
        cout << "4. Показать информацию о счете\n";
        cout << "5. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            // Создание нового счета
            if (accountCount < MAX_ACCOUNTS) {
                cout << "Введите номер счета: ";
                cin >> accounts[accountCount].accountNumber;

                cout << "Введите имя владельца счета: ";
                cin.ignore();
                getline(cin, accounts[accountCount].ownerName);

                accounts[accountCount].balance = 0;
                accountCount++;

                cout << "Банковский счет создан.\n";
            }
            else {
                cout << "Достигнуто максимальное количество счетов.\n";
            }
        }
        else if (choice == 2) {
            // Пополнение счета
            int accNum;
            double amount;

            cout << "Введите номер счета для пополнения: ";
            cin >> accNum;
            cout << "Введите сумму для пополнения: ";
            cin >> amount;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].accountNumber == accNum) {
                    accounts[i].balance += amount;
                    cout << "Счет пополнен на " << amount << " рублей.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Счет не найден.\n";
            }
        }
        else if (choice == 3) {
            // Снятие денег
            int accNum;
            double amount;

            cout << "Введите номер счета для снятия: ";
            cin >> accNum;
            cout << "Введите сумму для снятия: ";
            cin >> amount;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].accountNumber == accNum) {
                    if (accounts[i].balance >= amount) {
                        accounts[i].balance -= amount;
                        cout << "Со счета снято " << amount << " рублей.\n";
                    }
                    else {
                        cout << "Недостаточно средств.\n";
                    }
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Счет не найден.\n";
            }
        }
        else if (choice == 4) {
            // Показать информацию
            int accNum;

            cout << "Введите номер счета для показа информации: ";
            cin >> accNum;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].accountNumber == accNum) {
                    cout << "Номер счета: " << accounts[i].accountNumber << endl;
                    cout << "Имя владельца счета: " << accounts[i].ownerName << endl;
                    cout << "Баланс: " << accounts[i].balance << " рублей\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Счет не найден.\n";
            }
        }
        else if (choice == 5) {
            cout << "Программа завершена.\n";
        }
        else {
            cout << "Неверный выбор.\n";
        }
    }

    return 0;
}