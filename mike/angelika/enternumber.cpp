#include <iostream>

using namespace std;

int main() {
    int n[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter number[" << i + 1 << "]: ";
        cin >> n[i];
    }

    cout << endl;

    cout << "The entered numbers are: ";
    for (int i = 0; i < 5; i++) {
        cout << n[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << ".";

    cout << endl;

    return 0;
}