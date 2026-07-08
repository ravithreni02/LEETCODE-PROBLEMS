#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;
        int noOfb = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                noOfb += (cnt / k);
                cnt = 0; // Reset consecutive streak
            }
        }
        noOfb += (cnt / k); // Catch trailing streaks
        return noOfb >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        // 1. Explicitly store size as a long long to prevent unsigned mismatch bugs
        long long n = arr.size(); 
        long long totalFlowersNeeded = (long long)m * k;
        
        if (n < totalFlowersNeeded) return -1;

        // 2. Fetch correct bounds safely
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (possible(arr, mid, m, k)) {
                ans = mid;      // Valid day found, look for an earlier day
                high = mid - 1;
            } else {
                low = mid + 1;  // Not enough bouquets, increase the day count
            }
        }
        return ans;
    }
};
