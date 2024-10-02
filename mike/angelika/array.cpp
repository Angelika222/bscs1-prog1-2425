#include <iostream>
#include <string>

using namespace std;

int main() {
  // Declare an array of strings with 5 elements
  string names[5];

  // Get input from the user and store it in the array
  for (int i = 0; i < 5; i++) {
    cout << "Enter a name: ";
    getline(cin, names[i]); // Use getline to read entire lines
  }

  // Print the entered names
  cout << "You entered these names:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << names[i] << endl;
  }

  return 0;
}
