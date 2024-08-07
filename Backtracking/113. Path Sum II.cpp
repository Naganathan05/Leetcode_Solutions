/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
---------------------------*/

class Solution {
public:
    void function(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& arr) {
        if (!root) return;

        arr.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0) ans.push_back(arr);
        else {
            function(root->left, targetSum, ans, arr);
            function(root->right, targetSum, ans, arr);
        }
        arr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        function(root, targetSum, ans, arr);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/path-sum-ii/
Author: M.R.Naganathan
*/
