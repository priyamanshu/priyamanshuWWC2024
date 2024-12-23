#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle edge case for an empty array

        int uniqueCount = 1; // At least one unique element exists

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueCount] = nums[i]; // Move the unique element to the front
                uniqueCount++;
            }
        }

        return uniqueCount; // Number of unique elements
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int uniqueCount = solution.removeDuplicates(nums);

    // Print the modified array
    cout << "Modified array: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Number of unique elements: " << uniqueCount << endl;

    return 0;
}
