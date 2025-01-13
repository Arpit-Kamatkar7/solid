#include <iostream>
#include <string>
#include <regex>
using namespace std;

class PaymentProvider {
public:
    virtual void processPayment() = 0;
};

class Paytm : public PaymentProvider {
public:
    void processPayment()   { cout << "Payment processed via Paytm.\n"; }
};

class AmazonPay : public PaymentProvider {
public:
    void processPayment()   { cout << "Payment processed via Amazon Pay.\n"; }
};

class PhonePe : public PaymentProvider {
public:
    void processPayment()   { cout << "Payment processed via PhonePe.\n"; }
};

class PaymentMethod {
public:
    virtual void getDetails() = 0;
    virtual void makePayment() = 0;
};

class Wallet : public PaymentMethod {
public:
    void getDetails()   {
        string phone;
        bool valid = false;
        while (!valid) {
            cout << "Enter Phone number for Wallet: ";
            cin >> phone;
            // Validate Phone number (10 digits)
            if (phone.length() == 10 && all_of(phone.begin(), phone.end(), ::isdigit)) {
                cout << "Phone number entered: " << phone << endl;
                valid = true;
            } else {
                cout << "Invalid phone number. Please enter a 10-digit number.\n";
            }
        }
    }

    void makePayment()   {
        cout << "Payment successful using Wallet.\n";
    }
};

class UPI : public PaymentMethod {
public:
    void getDetails()   {
        string upiID;
        bool valid = false;
        while (!valid) {
            cout << "Enter UPI ID for UPI payment: ";
            cin >> upiID;
            // Validate UPI ID (simple format check)
            regex upiPattern("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9.-]+$");
            if (regex_match(upiID, upiPattern)) {
                cout << "UPI ID entered: " << upiID << endl;
                valid = true;
            } else {
                cout << "Invalid UPI ID format. Please try again.\n";
            }
        }
    }

    void makePayment()   {
        cout << "Payment successful using UPI.\n";
    }
};

class CreditCard : public PaymentMethod {
public:
    void getDetails()   {
        string cardNumber, expiryDate, cvv;
        bool valid = false;

        while (!valid) {
            cout << "Enter Credit Card details:\n";
            cout << "Card Number: ";
            cin >> cardNumber;
            // Validate Card Number (16 digits)
            if (cardNumber.length() == 16 && all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
                cout << "Expiry Date (MM/YY): ";
                cin >> expiryDate;
                // Validate Expiry Date (MM/YY format)
                if (expiryDate.length() == 5 && expiryDate[2] == '/' && isdigit(expiryDate[0]) && isdigit(expiryDate[1]) && isdigit(expiryDate[3]) && isdigit(expiryDate[4])) {
                    cout << "CVV: ";
                    cin >> cvv;
                    // Validate CVV (3 digits)
                    if (cvv.length() == 3 && all_of(cvv.begin(), cvv.end(), ::isdigit)) {
                        cout << "Credit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
                        valid = true;
                    } else {
                        cout << "Invalid CVV. Please enter a 3-digit number.\n";
                    }
                } else {
                    cout << "Invalid Expiry Date format. Please use MM/YY format.\n";
                }
            } else {
                cout << "Invalid Card Number. Please enter a 16-digit number.\n";
            }
        }
    }

    void makePayment()   {
        cout << "Payment successful using Credit Card.\n";
    }
};

class DebitCard : public PaymentMethod {
public:
    void getDetails()   {
        string cardNumber, expiryDate, cvv;
        bool valid = false;

        while (!valid) {
            cout << "Enter Debit Card details:\n";
            cout << "Card Number: ";
            cin >> cardNumber;
            // Validate Card Number (16 digits)
            if (cardNumber.length() == 16 && all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
                cout << "Expiry Date (MM/YY): ";
                cin >> expiryDate;
                // Validate Expiry Date (MM/YY format)
                if (expiryDate.length() == 5 && expiryDate[2] == '/' && isdigit(expiryDate[0]) && isdigit(expiryDate[1]) && isdigit(expiryDate[3]) && isdigit(expiryDate[4])) {
                    cout << "CVV: ";
                    cin >> cvv;
                    // Validate CVV (3 digits)
                    if (cvv.length() == 3 && all_of(cvv.begin(), cvv.end(), ::isdigit)) {
                        cout << "Debit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
                        valid = true;
                    } else {
                        cout << "Invalid CVV. Please enter a 3-digit number.\n";
                    }
                } else {
                    cout << "Invalid Expiry Date format. Please use MM/YY format.\n";
                }
            } else {
                cout << "Invalid Card Number. Please enter a 16-digit number.\n";
            }
        }
    }

    void makePayment()   {
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

        method->getDetails();
        provider->processPayment();
        method->makePayment();
        cout << "Payment of Rs." << amount << " completed successfully.\n";
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
