class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minindex = 0;
        int maxindex = 0;
        
        // Find the indices of the minimum and maximum elements
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[minindex]) minindex = i;
            if(nums[i] > nums[maxindex]) maxindex = i;
        }
        
        int low = min(minindex, maxindex);
        int high = max(minindex, maxindex);
        
        // Option 1: Delete both from the front
        int fromfront = high + 1;
        
        // Option 2: Delete both from the back
        int fromback = n - low;
        
        // Option 3: Delete one from the front and one from the back
        int frontback = (low + 1) + (n - high);
        
        return min(fromfront, min(fromback, frontback));
    }
};
