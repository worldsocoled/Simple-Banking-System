#include <iostream>
#include <vector>
using namespace std;

//class to represent a bank account
class BankAccount {
private:
    string owner;
    int accountNumber;
    double balance;

public:
    //constructor
    BankAccount(string owner, int accNum, double initialBalance) {
    this->owner = owner;
    this->accountNumber = accNum;
    this->balance = initialBalance;
    }

//deposit function
void deposit(double amount){
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! New balance: $" <<balance <<endl;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

//withdrawal function
void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
       balance -= amount;
       cout <<"Withdrawal successful! New balance: $" << balance << endl;
  } else {
       cout<< "Invalid withdrawal amount or insufficient funds!" << endl;
    }
}

//function to display account details
void display() const {
    cout << "Account Number: " << accountNumber 
    << "\nOwner: " << owner << "\nBalance: $"
    << balance << "\n";
    }

    //get account number (for searching)
    int getAccountNumber() const {
        return accountNumber;
    }
};

//Function to find an account by number
BankAccount* findAccount(vector<BankAccount>& accounts,
int accNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNum)
           return &acc;
    }
    return nullptr;
}

int main() {
    vector <BankAccount> accounts;
    int choice;

    cout << "Welcome to the Simple Banking Systems!"  << endl ;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
           string name;
           int accNum;
           double initialDeposit;
           cout << "Enter account holder name: ";
           cin.ignore();
           getline(cin, name);
           cout << "Enter account number: ";
           cin >> accNum;
           cout << "Enter initial deposit amount: ";
           cin >> initialDeposit;

           accounts.emplace_back(name, accNum, initialDeposit);
           cout << "Account created successfully!" <<endl;

         } else if (choice == 2) {
             int accNum;
             double amount;
             cout << "Enter account number: ";
             cin >> accNum;
             BankAccount* acc = findAccount(accounts, accNum);
             if (acc) {
                 cout << "Enter deposit amount: ";
                 cin >> amount;
                 acc->deposit(amount);
             } else {
                 cout << "Account not found!" <<endl;
             }
             
         } else if (choice == 3) {  // Withdraw Money
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;  // Read account number

            BankAccount* acc = findAccount(accounts, accNum);  // Search for account
            if (acc) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc->withdraw(amount);  // Perform withdrawal
          } else {
              cout << "Error: Account not found! Please check the account number.\n";
    }

             
         }  else if (choice == 4) {
             int accNum;
             cout << "Enter account number: ";
             cin >> accNum;
             BankAccount* acc = findAccount(accounts, accNum);
             if (acc) {
                 acc->display();
             } else {
                 cout << "Account not found! " <<endl;
             }
         } else if (choice == 5) {
             cout << "Thank you for using the system. Goodbye!" << endl;
         }
     }
     return 0;
}