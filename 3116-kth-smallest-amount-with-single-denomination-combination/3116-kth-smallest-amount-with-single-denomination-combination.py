class Solution:
    def findKthSmallest(self, coins, k):
        n = len(coins)
        
        # Simple Euclidean Algorithm for GCD (compatible with all Python versions)
        def get_gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        # Helper function to count unique multiples <= M using PIE
        def count_multiples(M):
            total = 0
            for i in range(1, 1 << n):
                lcm_val = 1
                bits_count = 0
                
                for j in range(n):
                    if (i >> j) & 1:
                        bits_count += 1
                        # Calculate LCM manually using our local get_gcd
                        lcm_val = (lcm_val * coins[j]) // get_gcd(lcm_val, coins[j])
                        if lcm_val > M:
                            break
                
                if lcm_val <= M:
                    if bits_count % 2 == 1:
                        total += M // lcm_val
                    else:
                        total -= M // lcm_val
            return total

        # Binary search boundaries
        low = min(coins)
        high = min(coins) * k
        ans = high
        
        while low <= high:
            mid = (low + high) // 2
            if count_multiples(mid) >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans

