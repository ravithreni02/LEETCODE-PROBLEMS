class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int maxSI=1,maxSD=1,IncCount=1,DecCount=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                IncCount++;
                DecCount=1;
            }else if(nums[i]<nums[i-1]){
                DecCount++;
                IncCount=1;
            }else{
                IncCount=1;
                DecCount=1;
            }
            maxSI=max(maxSI,IncCount);
            maxSD=max(maxSD,DecCount);
        }
        return max(maxSI,maxSD);
    }
};