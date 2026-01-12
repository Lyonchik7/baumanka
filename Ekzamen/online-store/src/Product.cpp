#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

Product::Product(int id, const string& n, double p, int qty)
    : productId(id), name(n), price(p), stockQuantity(qty) {}

void Product::display() const {
    cout << "ID: " << productId << " | " << name 
         << " | Price: " << fixed << setprecision(2) << price
         << " | Stock: " << stockQuantity << endl;
}

bool Product::reduceStock(int amount) {
    if (amount <= stockQuantity) {
        stockQuantity -= amount;
        return true;
    }
    return false;
}

void Product::increaseStock(int amount) {
    stockQuantity += amount;
}
