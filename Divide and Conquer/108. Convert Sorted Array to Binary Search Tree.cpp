/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    TreeNode* constructTree(vector<int> &nums, int low, int high){
        if(low > high) return NULL;

        int mid = low + (high - low) / 2;
        TreeNode* newNode= new TreeNode(nums[mid]);

        newNode -> left = constructTree(nums, low, mid - 1);
        newNode -> right = constructTree(nums, mid + 1, high);
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size() - 1);
    }
};

/*
Question Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Author: M.R.Naganathan
*/
