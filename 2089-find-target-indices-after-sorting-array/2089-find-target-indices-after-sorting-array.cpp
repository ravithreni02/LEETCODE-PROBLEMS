class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count1=0;
        int count2=0;
        for(int &num:nums){
            if(num<target)
                count1++;
            else if(num==target)
                count2++;
        }
        vector<int>result;
        for(int index=count1;index<count1+count2;index++){
            result.push_back(index);

        }
        return result;
    }
};