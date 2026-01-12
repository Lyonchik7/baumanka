#include "Order.h"
#include <iostream>
#include <iomanip>

using namespace std;

// OrderItem
OrderItem::OrderItem(int id, int oid, shared_ptr<Product> p, int qty, double pr)
    : itemId(id), orderId(oid), product(p), quantity(qty), price(pr) {}

double OrderItem::getSubtotal() const {
    return quantity * price;
}

void OrderItem::display() const {
    if (product) {
        cout << "  " << product->getName() << " x" << quantity 
             << " @ " << price << " = " << getSubtotal() << endl;
    }
}

// Order
Order::Order(int id, int uid) 
    : orderId(id), userId(uid), status("pending"), totalPrice(0) {}

Order::~Order() {
    // unique_ptr автоматически очистит память
}

bool Order::addItem(shared_ptr<Product> product, int quantity) {
    if (!product || quantity <= 0) {
        return false;
    }
    
    items.push_back(make_unique<OrderItem>(
        items.size() + 1, orderId, product, quantity, product->getPrice()
    ));
    
    totalPrice += quantity * product->getPrice();
    return true;
}

void Order::showDetails() const {
    cout << "\n=== ORDER #" << orderId << " ===\n";
    cout << "User ID: " << userId << endl;
    cout << "Status: " << status << endl;
    cout << "Total: " << fixed << setprecision(2) << totalPrice << endl;
    
    if (!items.empty()) {
        cout << "Items:\n";
        for (const auto& item : items) {
            item->display();
        }
    }
}
