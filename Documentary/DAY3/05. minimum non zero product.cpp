#include <iostream>

const int MOD = 1e9 + 7;

long long minNonZeroProduct(int p) {
    long long maxNum = (1LL << p) - 1; // 2^p - 1
    long long maxOdd = maxNum; // The maximum odd number
    long long count = (maxNum - 1) / 2; // Count of odd numbers

    long long result = 1;
    for (long long i = 0; i < count; ++i) {
        result = (result * (maxOdd - 2 * i)) % MOD;
    }
    result = (result * maxOdd) % MOD; // Multiply by the largest odd number
    return result;
}