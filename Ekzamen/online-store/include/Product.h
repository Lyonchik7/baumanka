#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <memory>

class Product {
private:
    int productId;
    std::string name;
    double price;
    int stockQuantity;

public:
    Product(int id, const std::string& n, double p, int qty);
    
    int getProductId() const { return productId; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }
    
    void setName(const std::string& n) { name = n; }
    void setPrice(double p) { price = p; }
    void setStockQuantity(int qty) { stockQuantity = qty; }
    
    bool decreaseStock(int amount);
    void increaseStock(int amount);
    void display() const;
};

#endif
