class Solution {
private:
    long long MOD = 1e9 + 7;

    // Helper function for fast modular exponentiation: (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;
        
        long long evenChoices = power(5, evenPositions);
        long long oddChoices = power(4, oddPositions);
        
        return (evenChoices * oddChoices) % MOD;
    }
};
