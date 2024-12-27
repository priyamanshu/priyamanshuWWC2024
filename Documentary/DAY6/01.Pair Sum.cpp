#include <bits/stdc++.h>
using namespace std;

int minAbsSumPair(vector<int>& arr) {
  
    int res = arr[0] + arr[1];
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(res)) {
                res = sum;
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = { 1, 60, -10, 70, -80, 85 };
    cout << minAbsSumPair(arr);
    return 0;
}