#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int minNonZeroProduct(int p) {
        const int MOD = 1e9 + 7;
        long long maxNum = (1LL << p) - 1; // This is 2^p - 1
        long long result = maxNum; // Start with the maximum number

        // Calculate (maxNum)^(2^(p-1) - 1) % MOD
        long long exponent = (1LL << (p - 1)) - 1; // This is 2^(p-1) - 1

        // Modular exponentiation
        result = modPow(result, exponent, MOD);

        return result;
    }

private:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod; // Handle base larger than mod
        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd, multiply base with result
                result = (result * base) % mod;
            }
            exp = exp >> 1; // Divide exp by 2
            base = (base * base) % mod; // Square the base
        }
        return result;
    }
};

int main() {
    Solution solution;
    int p;

    cout << "Enter the value of p: ";
    cin >> p;

    int result = solution.minNonZeroProduct(p);
    cout << "The minimum non-zero product is: " << result << endl;

    return 0;
}