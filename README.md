<h1> Solid Task Details</h1>

<div>

<h3>1. Single Responsibility Principle (SRP)</h3>

How it follows:

    Each class has a single responsibility.
        PaymentProvider is responsible for processing payments. Each specific provider (like Paytm, AmazonPay, and PhonePe) implements the processPayment method.
        PaymentMethod is responsible for collecting payment details and making payments. Each specific payment method (like Wallet, UPI, CreditCard, and DebitCard) handles its own input validation and payment logic.

Example:

    The Wallet class handles only the details of wallet payment input (phone number validation) and making payments using the wallet.
    The Paytm class only processes the payment via Paytm, without involving any other responsibilities.

<h3>2. Open/Closed Principle (OCP)</h3>

How it follows:

    The system is open for extension but closed for modification.
        You can add new PaymentProvider or PaymentMethod classes without changing existing code. This allows for easy addition of new payment options, but existing code remains untouched.

Example:

    To add a new provider (e.g., GooglePay), you can create a new class GooglePay that extends PaymentProvider and implements the processPayment method. Similarly, a new payment method (e.g., NetBanking) can be added by creating a new class that implements PaymentMethod.
    The main PaymentProcess class doesn't need to be modified. It can use the newly added providers or methods by updating only the user input logic (such as new options in the menus).

<h3>3. Liskov Substitution Principle (LSP)</h3>

How it follows:

    Derived classes can replace base classes without affecting the program's functionality.
        Any subclass of PaymentProvider (like Paytm, AmazonPay, or PhonePe) can be substituted for PaymentProvider, and any subclass of PaymentMethod (like Wallet, UPI, CreditCard, or DebitCard) can be substituted for PaymentMethod in the PaymentProcess class.

Example:

    You could replace Paytm with GooglePay in the PaymentProcess class and the program would still function correctly.
    The processPayment() method of PaymentProvider works the same way for any derived class, and the makePayment() method of PaymentMethod works similarly for any payment method.

<h3>4. Interface Segregation Principle</h3>



    The interfaces are specific to the functionality required for each task.
        The PaymentProvider interface defines a single method processPayment(), which only handles payment processing.
        The PaymentMethod interface defines getDetails() and makePayment() methods, which are specific to gathering user details and processing payments for a particular method.


<h3>5. Dependency Inversion Principle </h3>

How it follows:

    The high-level modules (PaymentProcess) do not depend on low-level modules (Paytm, Wallet, CreditCard), but rather on abstractions (PaymentProvider and PaymentMethod).
        PaymentProcess depends on the abstract PaymentProvider and PaymentMethod interfaces, not on their concrete implementations. This allows PaymentProcess to interact with any payment provider or method without knowing the details of the specific implementation.



</div>