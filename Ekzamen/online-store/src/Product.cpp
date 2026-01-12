#include "Product.hpp"

Product::Product(int id, const string& n, double p, int qty)
    : productId(id), name(n), price(p), stockQuantity(qty) {}

void Product::displayInfo() const {
    cout << "Product: " << name << " | Price: " << price 
         << " | Stock: " << stockQuantity << endl;
}

bool Product::decreaseStock(int quantity) {
    if (quantity <= stockQuantity) {
        stockQuantity -= quantity;
        return true;
    }
    return false;
}

bool Product::increaseStock(int quantity) {
    stockQuantity += quantity;
    return true;
}
