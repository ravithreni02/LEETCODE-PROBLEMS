#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int total_hrs(vector<int>& arr, int mid) {
        int n = arr.size();
        long long totalhrs = 0; // Use long long to avoid integer overflow
        for(int i = 0; i < n; i++) {
            // Fix integer division issue by casting to double before ceil
            totalhrs += ceil((double)arr[i] / mid);
        }
        // Return a large number if it exceeds INT_MAX to prevent overflow issues in calling function
        return totalhrs > INT_MAX ? INT_MAX : totalhrs;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        // 1. Fixed max_element syntax with iterators and dereferencing
        int low = 1, high = *max_element(arr.begin(), arr.end()), ans = high;
        
        // 2. Fixed the assignment typo 'while=' to 'while'
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential (low + high) integer overflow
            
            // 3. Fixed function name from 'func' to 'total_hrs'
            int hrs = total_hrs(arr, mid);
            
            if (hrs <= h) {
                ans = mid;       // Found a valid speed, try to find a smaller one
                high = mid - 1;
            }
            else {
                low = mid + 1;   // Speed is too slow, increase it
            }
        }
        return ans; // 4. Added missing return statement
    }
};
