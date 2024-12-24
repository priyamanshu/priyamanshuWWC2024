#include <iostream>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        // The winner's position in a 0-indexed system
        int winner = 0; // Base case: when there's only one person, they are the winner

        // Iterate from 2 to n to find the winner's position
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i; // Update the winner's position
        }

        // Convert to 1-indexed system
        return winner + 1;
    }
};

int main() {
    Solution solution;
    int n, k;

    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the count (k): ";
    cin >> k;

    int winner = solution.findTheWinner(n, k);
    cout << "The winner of the game is friend number: " << winner << endl;

    return 0;
}