#include "DatabaseConnection.hpp"
#include <iostream>

using namespace std;

// Конструктор
template<typename T>
DatabaseConnection<T>::DatabaseConnection(const string& connStr) {
    try {
        conn = make_unique<pqxx::connection>(connStr);
        if (!conn->is_open()) {
            throw runtime_error("Cannot connect to database");
        }
        cout << "Connected to: " << conn->dbname() << endl;
    } catch (const exception& e) {
        throw runtime_error(string("DB error: ") + e.what());
    }
}

// Деструктор
template<typename T>
DatabaseConnection<T>::~DatabaseConnection() {
    if (conn && conn->is_open()) {
        conn->close();
    }
}

// Выполнение запроса
template<typename T>
vector<vector<T>> DatabaseConnection<T>::executeQuery(const string& query) {
    vector<vector<T>> result;
    
    try {
        pqxx::nontransaction ntx(*conn);
        pqxx::result res = ntx.exec(query);
        
        for (const auto& row : res) {
            vector<T> rowData;
            for (const auto& field : row) {
                rowData.push_back(field.c_str());
            }
            result.push_back(rowData);
        }
    } catch (const exception& e) {
        cerr << "Query error: " << e.what() << endl;
    }
    
    return result;
}

// Выполнение команды без результата
template<typename T>
void DatabaseConnection<T>::executeNonQuery(const string& query) {
    try {
        pqxx::work w(*conn);
        w.exec(query);
        w.commit();
    } catch (const exception& e) {
        throw runtime_error(string("Command error: ") + e.what());
    }
}

// Начало транзакции
template<typename T>
void DatabaseConnection<T>::beginTransaction() {
    try {
        if (transaction) {
            transaction->abort();
        }
        transaction = make_unique<pqxx::work>(*conn);
    } catch (...) {
        // Игнорируем ошибку
    }
}

// Завершение транзакции
template<typename T>
void DatabaseConnection<T>::commitTransaction() {
    try {
        if (transaction) {
            transaction->commit();
            transaction.reset();
        }
    } catch (...) {
        // Игнорируем ошибку
    }
}

// Откат транзакции
template<typename T>
void DatabaseConnection<T>::rollbackTransaction() {
    try {
        if (transaction) {
            transaction->abort();
            transaction.reset();
        }
    } catch (...) {
        // Игнорируем ошибку
    }
}

// Проверка подключения
template<typename T>
bool DatabaseConnection<T>::isConnected() const {
    return conn && conn->is_open();
}

// Явная инстанциация шаблона
template class DatabaseConnection<string>;
template class DatabaseConnection<int>;
template class DatabaseConnection<double>;
