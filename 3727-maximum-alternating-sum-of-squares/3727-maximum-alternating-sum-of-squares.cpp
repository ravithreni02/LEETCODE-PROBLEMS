class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int&x:nums)x*=x;
        sort(nums.begin(),nums.end());
        int half=nums.size()/2;
        long long ans=0;
        for(int i=0;i<(int)nums.size();++i)
            ans+=i<half?-(long long)nums[i]:nums[i];
        return ans;
    }
};