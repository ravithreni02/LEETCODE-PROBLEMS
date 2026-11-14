class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int best = INT_MAX;

        for (int size = l; size <= r; size++) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += nums[i];
                
                // Shrink the window once it exceeds the current target size
                if (i >= size) {
                    total -= nums[i - size];
                }
                
                // Check valid window size and ensure the sum is strictly positive
                if (i >= size - 1 && total > 0) {
                    best = min(best, total);
                }
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};
