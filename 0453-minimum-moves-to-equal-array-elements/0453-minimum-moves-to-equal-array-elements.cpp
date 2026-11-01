class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int mini=1e9;
        int n=nums.size();
        for(int i:nums){
            mini=min(mini,i);
            sum+=i;
        }
        return sum-n*mini;
        
    }
};