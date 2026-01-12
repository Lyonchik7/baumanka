#ifndef USER_H
#define USER_H

#include <memory>
#include <string>
#include <vector>
#include "DatabaseConnection.h"

class Order;

class User {
protected:
    int userId;
    std::string name;
    std::string email;
    std::string role;
    std::vector<std::shared_ptr<Order>> orders;

public:
    User(int id, const std::string& n, const std::string& e, const std::string& r);
    virtual ~User() = default;
    
    virtual void showMenu() = 0;
    virtual bool hasPermission(const std::string& action) const = 0;
    
    std::shared_ptr<Order> createOrder(DatabaseConnection& db);
    std::string viewOrderStatus(int orderId, DatabaseConnection& db);
    bool cancelOrder(int orderId, DatabaseConnection& db);
    
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getRole() const { return role; }
    
    void addOrder(std::shared_ptr<Order> order);
    std::vector<std::shared_ptr<Order>> getOrders() const;
    
    static std::unique_ptr<User> authenticate(DatabaseConnection& db, 
                                             const std::string& email, 
                                             const std::string& password);
};

class Admin : public User {
public:
    Admin(int id, const std::string& n, const std::string& e);
    
    void showMenu() override;
    bool hasPermission(const std::string& action) const override;
    
    bool addProduct(DatabaseConnection& db, const std::string& name, 
                   double price, int quantity);
    void viewAllOrders(DatabaseConnection& db);
    bool updateOrderStatus(DatabaseConnection& db, int orderId, 
                          const std::string& newStatus);
    void viewAuditLog(DatabaseConnection& db);
};

class Customer : public User {
public:
    Customer(int id, const std::string& n, const std::string& e);
    
    void showMenu() override;
    bool hasPermission(const std::string& action) const override;
    
    bool addToOrder(DatabaseConnection& db, int orderId, 
                   int productId, int quantity);
    void viewMyOrders(DatabaseConnection& db);
    bool makePayment(DatabaseConnection& db, int orderId, 
                    const std::string& method);
};

class Manager : public User {
public:
    Manager(int id, const std::string& n, const std::string& e);
    
    void showMenu() override;
    bool hasPermission(const std::string& action) const override;
};

#endif
