#ifndef ORDER_H
#define ORDER_H

#include <memory>
#include <vector>
#include <string>
#include "Product.h"

class OrderItem {
private:
    int itemId;
    int orderId;
    std::shared_ptr<Product> product;
    int quantity;
    double price;

public:
    OrderItem(int id, int oid, std::shared_ptr<Product> p, int qty, double pr);
    
    int getItemId() const { return itemId; }
    int getOrderId() const { return orderId; }
    std::shared_ptr<Product> getProduct() const { return product; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    double getSubtotal() const { return quantity * price; }
    
    void display() const;
};

class Order {
private:
    int orderId;
    int userId;
    std::string status;
    double totalPrice;
    std::vector<std::unique_ptr<OrderItem>> items;

public:
    Order(int id, int uid, const std::string& stat = "pending", double total = 0);
    ~Order();
    
    int getOrderId() const { return orderId; }
    int getUserId() const { return userId; }
    std::string getStatus() const { return status; }
    double getTotalPrice() const { return totalPrice; }
    
    void setStatus(const std::string& s) { status = s; }
    void setTotalPrice(double price) { totalPrice = price; }
    
    bool addItem(std::shared_ptr<Product> product, int quantity);
    void showDetails() const;
    std::vector<OrderItem*> getItems() const;
};

#endif
