#include <vector>

using namespace std;

class Solution {
private:
    void generateSubsets(int ind, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        // Base case: add the current subset copy to the answer
        if (ind == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Include the current element
        current.push_back(nums[ind]);
        generateSubsets(ind + 1, nums, current, ans);
        
        // Backtrack: Remove the element to try the next choice
        current.pop_back();

        // Choice 2: Exclude the current element
        generateSubsets(ind + 1, nums, current, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        generateSubsets(0, nums, current, ans);
        return ans;
    }
};

