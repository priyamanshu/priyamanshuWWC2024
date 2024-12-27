#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> indices;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            indices.push_back(i);
        }
    }
    
    return indices;
}

int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(2);
    nums1.push_back(3);

    int target1 = 2;
    vector<int> result1 = targetIndices(nums1, target1);
    
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(2);
    nums2.push_back(3);

    int target2 = 3;
    vector<int> result2 = targetIndices(nums2, target2);
    
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    vector<int> nums3;
    nums3.push_back(1);
    nums3.push_back(2);
    nums3.push_back(5);
    nums3.push_back(2);
    nums3.push_back(3);

    int target3 = 5;
    vector<int> result3 = targetIndices(nums3, target3);
    
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}