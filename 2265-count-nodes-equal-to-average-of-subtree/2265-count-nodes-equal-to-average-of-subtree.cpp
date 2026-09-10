/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function returns a pair: {sum_of_nodes, count_of_nodes}
    pair<int, int> dfs(TreeNode* root, int& count) {
        if (!root) return {0, 0};
        
        pair<int, int> left = dfs(root->left, count);
        pair<int, int> right = dfs(root->right, count);
        
        int current_sum = left.first + right.first + root->val;
        int current_count = left.second + right.second + 1;
        
        // Integer division perfectly matches LeetCode's "rounded down" requirement
        if (current_sum / current_count == root->val) {
            ++count;
        }
        
        return {current_sum, current_count};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};
