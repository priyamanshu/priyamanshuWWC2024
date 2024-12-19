#include <iostream>
using namespace std;

int main() {
    int n;

    // Input a number
    cout << "Enter a positive integer: ";
    cin >> n;

    // Numbers less than 2 are not prime
    if (n <= 1) {
        cout << n << " is not a prime number." << endl;
        return 0;
    }

    // Check for divisors
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            cout << n << " is not a prime number." << endl;
            return 0; // Exit if a divisor is found
        }
    }

    // If no divisors are found
    cout << n << " is a prime number." << endl;

    return 0;
}
