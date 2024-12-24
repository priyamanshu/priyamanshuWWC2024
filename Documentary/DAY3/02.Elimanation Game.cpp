#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1; // Fill the array with numbers from 1 to n
    }

    bool leftToRight = true; // Start with left to right
    while (arr.size() > 1) {
        vector<int> newArr;
        if (leftToRight) {
            // Remove the first number and every other number from left to right
            for (int i = 1; i < arr.size(); i += 2) {
                newArr.push_back(arr[i]);
            }
        } else {
            // Remove the rightmost number and every other number from right to left
            for (int i = arr.size() - 2; i >= 0; i -= 2) {
                newArr.push_back(arr[i]);
            }
        }
        arr = newArr; // Update arr to the new array
        leftToRight = !leftToRight; // Alternate direction
    }

    return arr[0]; // The last remaining number
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = lastRemaining(n);
    cout << "The last remaining number is: " << result << endl;

    return 0;
}