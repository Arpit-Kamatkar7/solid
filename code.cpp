#include <iostream>
#include <string>
using namespace std;

class PaymentProvider {
public:
    virtual void processPayment() = 0; 
};

class Paytm : public PaymentProvider {
public:
    void processPayment() override { cout << "Payment processed via Paytm.\n"; }
};

class AmazonPay : public PaymentProvider {
public:
    void processPayment() override { cout << "Payment processed via Amazon Pay.\n"; }
};

class PhonePe : public PaymentProvider {
public:
    void processPayment() override { cout << "Payment processed via PhonePe.\n"; }
};

class PaymentMethod {
public:
    virtual bool getDetails() = 0; 
    virtual void makePayment() = 0; 
};

class Wallet : public PaymentMethod {
public:
    bool getDetails() override {
        string phone;
        cout << "Enter Phone number for Wallet: ";
        cin >> phone;
        cout << "Phone number entered: " << phone << endl;

        if(phone.size()!=10){
            return false;
        }else{
            return true;
        }
    }

    

    void makePayment() override {
        cout << "Payment successful using Wallet.\n";
    }
};

class UPI : public PaymentMethod {
public:
    bool getDetails() override {
        string upiID;
        cout << "Enter UPI ID for UPI payment: ";
        cin >> upiID;
        cout << "UPI ID entered: " << upiID << endl;
        if(upiID.size()!=10){
          return false;
        }else{
            return true;
        }
    }
    void makePayment() override {
        cout << "Payment successful using UPI.\nb";
    }
};

class CreditCard : public PaymentMethod {
public:
    bool getDetails() override {
        string cardNumber, expiryDate, cvv;
        cout << "Enter Credit Card details:\n";
        cout << "Card Number: ";
        cin >> cardNumber;
        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        cout << "CVV: ";
        cin >> cvv;
        cout << "Credit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
    }
    void makePayment() override {
        cout << "Payment successful using Credit Card.\n";
    }
};

class DebitCard : public PaymentMethod {
public:
    bool getDetails() override {
        string cardNumber, expiryDate, cvv;
        cout << "Enter Debit Card details:\n";
        cout << "Card Number: ";
        cin >> cardNumber;
        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        cout << "CVV: ";
        cin >> cvv;
        cout << "Debit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
    }
    void makePayment() override {
        cout << "Payment successful using Debit Card.\n";
    }
};

class PaymentProcess {
private:
    PaymentProvider* provider;  
    PaymentMethod* method;      

public:
    void choosePaymentProvider() {
        int choice;
        cout << "Choose Payment Provider:\n1. Paytm\n2. Amazon Pay\n3. PhonePe\n";
        cin >> choice;

        if (choice == 1) provider = new Paytm();
        else if (choice == 2) provider = new AmazonPay();
        else if (choice == 3) provider = new PhonePe();
        else cout << "Invalid choice.\n";
    }

    void choosePaymentMethod() {
        int choice;
        cout << "Choose Payment Method:\n1. Wallet\n2. UPI\n3. Credit Card\n4. Debit Card\n";
        cin >> choice;

        if (choice == 1) method = new Wallet();
        else if (choice == 2) method = new UPI();
        else if (choice == 3) method = new CreditCard();
        else if (choice == 4) method = new DebitCard();
        else cout << "Invalid choice.\n";
    }

    void processPayment() {
        float amount;
        cout << "Enter the amount to pay: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Amount should be greater than zero.\n";
            return;
        }
        
        
        bool flag = method->getDetails(); 
        if(flag){
            cout<<"True\n";
            provider->processPayment();  
            method->makePayment();  
            cout << "Payment of Rs." << amount << " completed successfully.\n";

        }else{
            cout<<"false";
        }

        // provider->processPayment();  
        // method->makePayment();  
        // cout << "Payment of Rs." << amount << " completed successfully.\n";
    }

    ~PaymentProcess() { 
        delete provider;
        delete method;
    }
};

int main() {
    PaymentProcess payment; 

    payment.choosePaymentProvider();  
    payment.choosePaymentMethod();    
    payment.processPayment();         

    return 0;  
}
