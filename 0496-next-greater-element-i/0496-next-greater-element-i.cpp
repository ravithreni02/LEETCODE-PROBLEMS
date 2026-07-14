class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater; // Added to map element -> next greater
        
        int n = nums2.size(); // Changed from nums1.size() to nums2.size()
        for(int i = n - 1; i >= 0; i--){ // Changed i > 0 to i >= 0 to include index 0
            while(!st.empty() && st.top() <= nums2[i]){ // Changed nums1[i] to nums2[i]
                st.pop();
            }
            if(st.empty()) {
                next_greater[nums2[i]] = -1; // Changed nums2[i] mapping to -1
            } else {
                next_greater[nums2[i]] = st.top(); // Fixed typo nums2[1] to next_greater mapping
            }
            st.push(nums2[i]); // Changed nums1[i] to nums2[i]
        }

        // Map the results back to nums1 to create the final answer
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(next_greater[nums1[i]]);
        }
        return ans; // Changed from returning nums2 to returning ans
    }
};
