#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    // Input the value of n
    cout << "Enter a positive integer: ";
    cin >> n;

    // Calculate the sum of natural numbers up to n
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Display the result
    cout << "The sum of natural numbers up to " << n << " is: " << sum << endl;

    return 0;
}
