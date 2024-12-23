#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // Base case: no elements to form a tree

        int mid = left + (right - left) / 2; // Find the middle element
        TreeNode* root = new TreeNode(nums[mid]); // Create the root node

        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root; // Return the root of the tree
    }
};

// Helper function to print the tree in-order (for testing purposes)
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9}; // Example input

    TreeNode* root = solution.sortedArrayToBST(nums);

    // Print the in-order traversal of the BST
    cout << "In-order traversal of the BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
