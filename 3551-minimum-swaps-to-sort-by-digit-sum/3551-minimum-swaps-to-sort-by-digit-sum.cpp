class Solution {
public:
    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> aftersorted(nums);
        auto lambda=[&](int num1,int num2){
            int num1DigitSum=getDigitSum(num1);
            int num2DigitSum=getDigitSum(num2);
            if(num1DigitSum!=num2DigitSum){
                return num1DigitSum<num2DigitSum;
            }
            return num1<num2;
        };
        sort(begin(aftersorted),end(aftersorted),lambda);
        unordered_map<int,int>valToIdx;
        for(int i=0;i<n;i++){
            valToIdx[nums[i]]=i;
        }
        int swapCount=0;
        for(int i=0;i<n;i++){
            int expectedval=aftersorted[i];
            int currval=nums[i];
            if(expectedval==currval)continue;
            int idx=valToIdx[expectedval];
            nums[i]=expectedval;
            nums[idx]=currval;
            valToIdx[expectedval]=i;
            valToIdx[currval]=idx;
            swapCount++;
        }
        return swapCount;
    }
};