#include "DatabaseConnection.h"
#include <iostream>

using namespace std;

// Конструктор - подключение к БД
DatabaseConnection<string>::DatabaseConnection(const string& connStr) {
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
DatabaseConnection<string>::~DatabaseConnection() {
    if (conn && conn->is_open()) {
        conn->close();
    }
}

// Выполнить запрос с результатом
vector<vector<string>> DatabaseConnection<string>::executeQuery(const string& sql) {
    vector<vector<string>> result;
    
    try {
        pqxx::nontransaction ntx(*conn);
        pqxx::result res = ntx.exec(sql);
        
        for (const auto& row : res) {
            vector<string> rowData;
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

// Выполнить команду без результата
void DatabaseConnection<string>::executeNonQuery(const string& sql) {
    try {
        pqxx::work w(*conn);
        w.exec(sql);
        w.commit();
    } catch (const exception& e) {
        throw runtime_error(string("Command error: ") + e.what());
    }
}

// Начать транзакцию
void DatabaseConnection<string>::beginTransaction() {
    try {
        if (transaction) {
            transaction->abort();
        }
        transaction = make_unique<pqxx::work>(*conn);
    } catch (...) {
        cerr << "Transaction begin error\n";
    }
}

// Завершить транзакцию
void DatabaseConnection<string>::commitTransaction() {
    try {
        if (transaction) {
            transaction->commit();
            transaction.reset();
        }
    } catch (...) {
        cerr << "Transaction commit error\n";
    }
}

// Откатить транзакцию
void DatabaseConnection<string>::rollbackTransaction() {
    try {
        if (transaction) {
            transaction->abort();
            transaction.reset();
        }
    } catch (...) {
        cerr << "Transaction rollback error\n";
    }
}

// Проверить подключение
bool DatabaseConnection<string>::isConnected() const {
    return conn && conn->is_open();
}
