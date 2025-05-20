class Solution {
public:
    const int MOD = 1e9 + 7;
 
    long long power(long long base, long long exp, int mod) {
        if (exp == 0)
            return 1;

        base %= mod;

        long long half = power(base, exp / 2, mod);
        long long result = (half * half) % mod;

        if (exp % 2 == 1)
            result = (result * base) % mod;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long good_strings = (power(5, even_positions, MOD) * power(4, odd_positions, MOD)) % MOD;

        return static_cast<int>(good_strings);
    }
};
