class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minelement=*min_element(nums.begin(),nums.end());
        int maxelement=*max_element(nums.begin(),nums.end());
        vector<bool>exists(maxelement-minelement+1);
        for(int& i:nums)exists[i-minelement]=true;
        vector<int>ans;
        for(int i=0;i<maxelement-minelement;i++){
            if(!exists[i]){
                ans.push_back(i+minelement);
            }
        }
         return ans;

    }
};