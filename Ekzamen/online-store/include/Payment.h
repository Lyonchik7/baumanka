#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <memory>

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual bool pay(double amount) = 0;
    virtual std::string getMethodName() const = 0;
};

class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;
public:
    CreditCardPayment(const std::string& card);
    bool pay(double amount) override;
    std::string getMethodName() const override;
};

class WalletPayment : public PaymentStrategy {
private:
    std::string walletId;
public:
    WalletPayment(const std::string& wallet);
    bool pay(double amount) override;
    std::string getMethodName() const override;
};

class Payment {
private:
    int paymentId;
    int orderId;
    double amount;
    std::unique_ptr<PaymentStrategy> strategy;
public:
    Payment(int id, int oid, double amt, std::unique_ptr<PaymentStrategy> strat);
    bool process();
    void showInfo() const;
};

#endif
