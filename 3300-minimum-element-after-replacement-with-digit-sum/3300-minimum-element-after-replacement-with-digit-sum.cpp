class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int sum=0;
            while(x){
                int rem=x%10;
                sum+=rem;
                x/=10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};