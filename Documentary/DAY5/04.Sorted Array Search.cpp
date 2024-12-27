#include <iostream>
#include <vector>
using namespace std;

bool isPresent(const vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            return true;
        }
        if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(6);
    
    int k1 = 6;
    cout << boolalpha << isPresent(arr1, k1) << endl; // Output: true

    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);
    
    int k2 = 3;
    cout << boolalpha << isPresent(arr2, k2) << endl; // Output: false

    vector<int> arr3;
    arr3.push_back(2);
    arr3.push_back(3);
    arr3.push_back(5);
    arr3.push_back(6);
    
    int k3 = 1;
    cout << boolalpha << isPresent(arr3, k3) << endl; // Output: false

    return 0;
}