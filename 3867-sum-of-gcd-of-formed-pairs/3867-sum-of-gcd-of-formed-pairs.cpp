class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixgcd(n);
        int current_max=0;
        for(int i=0;i<n;i++){
            current_max=max(current_max,nums[i]);
            prefixgcd[i]=gcd(nums[i],current_max);
        }
        sort(prefixgcd.begin(), prefixgcd.end());
        long long total_sum = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            total_sum += gcd(prefixgcd[left], prefixgcd[right]);
            left++;
            right--;
        }
        
        return total_sum;

        
    }
};