#include <iostream>
#include <string>
using namespace std;

// Function to validate if a string is numeric
bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;  // Return false if any character is not a digit
        }
    }
    return true;
}

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

        // Validate phone number (should be 10 digits)
        if (phone.size() != 10 || !isNumeric(phone)) {
            cout << "Invalid phone number. Please enter a valid 10-digit number.\n";
            return false;
        }

        cout << "Phone number entered: " << phone << endl;
        return true;
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

        // Validate UPI ID format (a very basic check for simplicity)
        size_t atPos = upiID.find('@');
        size_t dotPos = upiID.find('.');
        if (atPos == string::npos || dotPos == string::npos || upiID.size() < 5) {
            cout << "Invalid UPI ID format. Please enter a valid UPI ID.\n";
            return false;
        }

        cout << "UPI ID entered: " << upiID << endl;
        return true;
    }

    void makePayment() override {
        cout << "Payment successful using UPI.\n";
    }
};

class CreditCard : public PaymentMethod {
public:
    bool getDetails() override {
        string cardNumber, expiryDate, cvv;

        cout << "Enter Credit Card details:\n";
        cout << "Card Number (16 digits): ";
        cin >> cardNumber;
        if (cardNumber.size() != 16 || !isNumeric(cardNumber)) {
            cout << "Invalid Card Number. Please enter a 16-digit number.\n";
            return false;
        }

        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        if (expiryDate.size() != 5 || expiryDate[2] != '/' || !isNumeric(expiryDate.substr(0, 2)) || !isNumeric(expiryDate.substr(3, 2))) {
            cout << "Invalid Expiry Date format. Please use MM/YY format.\n";
            return false;
        }

        cout << "CVV (3 digits): ";
        cin >> cvv;
        if (cvv.size() != 3 || !isNumeric(cvv)) {
            cout << "Invalid CVV. Please enter a 3-digit number.\n";
            return false;
        }

        cout << "Credit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
        return true;
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
        cout << "Card Number (16 digits): ";
        cin >> cardNumber;
        if (cardNumber.size() != 16 || !isNumeric(cardNumber)) {
            cout << "Invalid Card Number. Please enter a 16-digit number.\n";
            return false;
        }

        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        if (expiryDate.size() != 5 || expiryDate[2] != '/' || !isNumeric(expiryDate.substr(0, 2)) || !isNumeric(expiryDate.substr(3, 2))) {
            cout << "Invalid Expiry Date format. Please use MM/YY format.\n";
            return false;
        }

        cout << "CVV (3 digits): ";
        cin >> cvv;
        if (cvv.size() != 3 || !isNumeric(cvv)) {
            cout << "Invalid CVV. Please enter a 3-digit number.\n";
            return false;
        }

        cout << "Debit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
        return true;
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
        if(flag) {
            provider->processPayment();  
            method->makePayment();  
            cout << "Payment of Rs." << amount << " completed successfully.\n";
        } else {
            cout << "Payment details are invalid. Transaction failed.\n";
        }
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
