#include <iostream>
#include <string>
#include <vector> // For using vectors to store user data
#include <algorithm> // For using std::find

using namespace std;

// Structure to represent a user
struct User {
    string username;
    string password;
};

int main() {
    vector<User> users; // Vector to store user data
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n--- Welcome to the Login Page! ---" << endl;
        cout << "Choose [1] Register, [2] Login, or [3] Exit: ";
        cin >> choice;

        if (cin.fail() || (choice < 1 || choice > 3)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Please choose either [1], [2], or [3]." << endl;
            continue;
        }

        if (choice == 1) {
            // Register a new user
            User newUser;
            cout << "Enter your username: ";
            cin >> newUser.username;
            cout << "Enter your password: ";
            cin >> newUser.password;
            users.push_back(newUser); // Add the new user to the vector
            cout << "Registration successful!" << endl;
        } else if (choice == 2) {
            // Login
            if (users.empty()) {
                cout << "No registered users. Please register first!" << endl;
                continue;
            }

            string enteredUsername, enteredPassword;
            cout << "Enter your username: ";
            cin >> enteredUsername;
            cout << "Enter your password: ";
            cin >> enteredPassword;

            // Find the user in the vector
            auto it = find_if(users.begin(), users.end(),
                              [&enteredUsername](const User& user) { 
                                  return user.username == enteredUsername; 
                              });

            if (it != users.end() && it->password == enteredPassword) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Login failed! Wrong Username or Password!" << endl;
            }
        } else if (choice == 3) {
            exitProgram = true;
            cout << "Exiting the program. Goodbye!" << endl;
        }
    }

    return 0;
}