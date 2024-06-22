/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
------------------------------------*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int max_depth = 1;
        for(auto node : root -> children) max_depth = max(max_depth, 1 + maxDepth(node));
        return max_depth;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Author: M.R.Naganathan
*/
