/*--------------------------
  Time Complexity: O(n * n)  
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    TreeNode* Construct(vector<int> &nums, int i, int j){
        if(i > j) return NULL;
        int maxVal = nums[i], maxInd = i;
        for(int ind = i; ind <= j; ind++){
            if(maxVal < nums[ind]){
                maxVal = nums[ind];
                maxInd = ind;
            }
        }
        TreeNode* newNode = new TreeNode(maxVal);
        newNode -> left = Construct(nums, i, maxInd - 1);
        newNode -> right = Construct(nums, maxInd + 1, j);
        return newNode;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Construct(nums, 0, nums.size() - 1);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-binary-tree/
Author: M.R.Naganathan
*/
