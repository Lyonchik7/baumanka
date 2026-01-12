#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <memory>
#include <string>
#include <vector>
#include <pqxx/pqxx>

class DatabaseConnection {
private:
    std::unique_ptr<pqxx::connection> conn;

public:
    DatabaseConnection(const std::string& connectionString);
    ~DatabaseConnection();
    
    std::vector<std::vector<std::string>> executeQuery(const std::string& sql);
    void executeNonQuery(const std::string& sql);
    
    bool isConnected() const;
};

#endif
