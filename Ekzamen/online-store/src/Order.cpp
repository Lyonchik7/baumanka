#include "Order.hpp"
#include <iostream>

// OrderItem
OrderItem::OrderItem(int itemId, int oid, shared_ptr<Product> p, int qty, double pr)
    : orderItemId(itemId), orderId(oid), product(p), quantity(qty), price(pr) {}

void OrderItem::displayInfo() const {
    if (product) {
        cout << "  " << product->getName() << " x" << quantity 
             << " = " << (quantity * price) << endl;
    }
}

// Order
Order::Order(int id, int uid, const string& stat, double total)
    : orderId(id), userId(uid), status(stat), totalPrice(total) {}

Order::~Order() {
    // Автоматически очищается
}

bool Order::addItem(shared_ptr<Product> product, int quantity) {
    if (!product || quantity <= 0) return false;
    
    items.push_back(make_unique<OrderItem>(
        items.size() + 1, orderId, product, quantity, product->getPrice()
    ));
    
    totalPrice += quantity * product->getPrice();
    return true;
}

void Order::displayOrderDetails() const {
    cout << "\nOrder #" << orderId << endl;
    cout << "Status: " << status << endl;
    cout << "Total: " << totalPrice << endl;
    cout << "Items:" << endl;
    
    for (const auto& item : items) {
        item->displayInfo();
    }
}

vector<OrderItem*> Order::getItems() const {
    vector<OrderItem*> result;
    for (const auto& item : items) {
        result.push_back(item.get());
    }
    return result;
}
