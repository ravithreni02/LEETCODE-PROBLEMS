class Solution {
public:
    int countPrimes(int n) {
        // Base case: There are no primes strictly less than 2
        if (n <= 2) return 0;
        
        // Create a boolean vector initialized to true
        // prime[i] will track if number 'i' is prime
        vector<bool> isPrime(n, true);
        
        // 0 and 1 are not prime numbers
        isPrime[0] = isPrime[1] = false;
        
        // Loop from 2 up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i starting from i*i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count how many numbers are still marked as prime
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};
