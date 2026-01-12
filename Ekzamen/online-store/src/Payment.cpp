#include "Payment.h"
#include <iostream>

using namespace std;

// Стратегия оплаты картой
CreditCardPayment::CreditCardPayment(const string& card) : cardNumber(card) {}

bool CreditCardPayment::pay(double amount) {
    cout << "Processing credit card payment: " << amount << endl;
    cout << "Card: **** **** **** " << cardNumber.substr(cardNumber.length() - 4) << endl;
    // В реальном приложении здесь был бы вызов платежного шлюза
    return true;
}

// Стратегия оплаты электронным кошельком
WalletPayment::WalletPayment(const string& wallet) : walletId(wallet) {}

bool WalletPayment::pay(double amount) {
    cout << "Processing wallet payment: " << amount << endl;
    cout << "Wallet: " << walletId << endl;
    return true;
}

// Основной класс Payment
Payment::Payment(int id, int oid, double amt, unique_ptr<PaymentStrategy> strat)
    : paymentId(id), orderId(oid), amount(amt), strategy(move(strat)) {}

bool Payment::process() {
    if (!strategy) {
        cout << "No payment method selected\n";
        return false;
    }
    
    cout << "\nProcessing payment for order #" << orderId << endl;
    bool success = strategy->pay(amount);
    
    if (success) {
        cout << "Payment successful!\n";
    }
    
    return success;
}

void Payment::showInfo() const {
    cout << "Payment #" << paymentId << " | Order #" << orderId 
         << " | Amount: " << amount << endl;
}
