class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0,sum=0;
        for(auto u:nums){
            mx=max(mx,u);
            sum+=u;
        }
        return mx*nums.size()-sum;
    }
};