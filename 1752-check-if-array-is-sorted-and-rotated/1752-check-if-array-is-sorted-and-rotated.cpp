class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Compare current element with the next element circularly
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // If there's more than one drop, it cannot be a sorted rotated array
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};
