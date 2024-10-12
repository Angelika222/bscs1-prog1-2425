#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
    double balance;
};

int main() {
    vector<User> users;
    int choice;
    bool loggedIn = false;
    int loggedInUserIndex = -1;

    while (true) {
        if (!loggedIn) {
            cout << "\n--- Welcome to the Banking System ---" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                // Register
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                users.push_back({username, password, 0.0});
                cout << "Registration successful!" << endl;
            } else if (choice == 2) {
                // Login
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                for (int i = 0; i < users.size(); i++) {
                    if (users[i].username == username && users[i].password == password) {
                        loggedIn = true;
                        loggedInUserIndex = i;
                        cout << "Login successful!" << endl;
                        break;
                    }
                }
                if (!loggedIn) {
                    cout << "Invalid username or password!" << endl;
                }
            } else if (choice == 3) {
                // Exit
                cout << "Exiting program..." << endl;
                break;
            } else {
                cout << "Invalid choice!" << endl;
            }
        } else {
            // Logged in user actions
            cout << "\n--- Banking Actions ---" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                // Deposit
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                users[loggedInUserIndex].balance += amount;
                cout << "Deposited $" << amount << "." << endl;
            } else if (choice == 2) {
                // Withdraw
                double amount;
                cout << "Enter withdraw amount: ";
                cin >> amount;
                if (amount <= users[loggedInUserIndex].balance) {
                    users[loggedInUserIndex].balance -= amount;
                    cout << "Withdrew $" << amount << "." << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
            } else if (choice == 3) {
                // Check Balance
                cout << "Your balance is: $" << users[loggedInUserIndex].balance << endl;
            } else if (choice == 4) {
                // Logout
                loggedIn = false;
                loggedInUserIndex = -1;
                cout << "Logged out successfully!" << endl;
            } else {
                cout << "Invalid choice!" << endl;
            }
        }
    }
    return 0;
}
