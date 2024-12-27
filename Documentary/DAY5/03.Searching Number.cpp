#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(int k, const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == k) {
            return i + 1; 
        }
    }
    return -1;
}

int main() {
    int k1 = 16;
    int arr1_raw[] = {9, 7, 16, 16, 4};
    vector<int> arr1(arr1_raw, arr1_raw + sizeof(arr1_raw) / sizeof(arr1_raw[0]));
    cout << firstOccurrence(k1, arr1) << endl; 

    int k2 = 98;
    int arr2_raw[] = {1, 22, 57, 47, 34, 18, 66};
    vector<int> arr2(arr2_raw, arr2_raw + sizeof(arr2_raw) / sizeof(arr2_raw[0]));
    cout << firstOccurrence(k2, arr2) << endl; 

    return 0;
}