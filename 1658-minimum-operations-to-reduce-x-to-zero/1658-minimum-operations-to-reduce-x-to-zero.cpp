class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Target sum for the middle subarray
        int target = total_sum - x;
        
        // If target is negative, it's impossible to reduce x to 0
        if (target < 0) return -1;
        // If target is 0, we need to remove all elements
        if (target == 0) return nums.size();
        
        int src_sum = 0;
        int left = 0;
        int max_len = -1;
        int n = nums.size();
        
        // Sliding window to find the longest subarray summing to 'target'
        for (int right = 0; right < n; right++) {
            src_sum += nums[right];
            
            // Shrink the window from the left if the sum exceeds target
            while (src_sum > target && left <= right) {
                src_sum -= nums[left];
                left++;
            }
            
            // Check if we found a valid window
            if (src_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // If no valid subarray was found, return -1. 
        // Otherwise, the operations needed = total elements - max subarray length.
        return max_len == -1 ? -1 : n - max_len;
    }
};
