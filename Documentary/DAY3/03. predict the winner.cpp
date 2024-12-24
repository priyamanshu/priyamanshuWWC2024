#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: when there's only one number, the player takes it
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill the dp table
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1; // End index
                // Player 1's score if they take nums[i] or nums[j]
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        // If the score of player 1 is greater than or equal to 0, they can win
        return dp[0][n - 1] >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Example input
    cout << "Enter the numbers in the array (end with -1): ";
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }

    bool result = solution.PredictTheWinner(nums);
    if (result) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 2 can win!" << endl;
    }

    return 0;
}