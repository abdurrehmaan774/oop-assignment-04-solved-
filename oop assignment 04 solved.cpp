#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        cout << "Constructor called\n";
        if (b < 0) {
            throw "Invalid account creation: Negative balance!";
        }
        name = n;
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw "Withdrawal failed: Insufficient balance!";
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }

    ~BankAccount() {
        cout << "Destructor called\n";
    }
};

int main() {
    BankAccount* acc = nullptr;

    try {
        acc = new BankAccount("Ali", 1000);
        acc->withdraw(1500);
        delete acc;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
        delete acc;
    }

    cout << "Program continues normally...\n";
    return 0;
}
