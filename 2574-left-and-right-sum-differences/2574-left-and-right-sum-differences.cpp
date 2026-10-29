class Solution { 
public: 
    vector<int> leftRightDifference(vector<int>& nums) { 
        int n = nums.size(); 
        int s = 0; 
        vector<int> ans(n), rgt(n, 0); 
        
        // Fixed: Changed i++ to i--
        for(int i = n - 2; i >= 0; i--) { 
            rgt[i] = rgt[i+1] + nums[i+1]; 
        } 
        
        for(int i = 1; i < n; i++) { 
            s += nums[i-1]; 
            ans[i] = abs(s - rgt[i]); 
        } 
        
        ans[0] = rgt[0]; 
        return ans; 
    } 
};
