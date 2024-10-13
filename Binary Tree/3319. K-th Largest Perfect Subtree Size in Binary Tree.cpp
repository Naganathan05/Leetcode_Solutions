/*-----------------------------
  Time Complexity: O(nlogh)
  Space Complexity: O(h)
-------------------------------*/

class Solution {
public:
    pair<int, bool> perfectSubtree(TreeNode* root, int &k, priority_queue<int, vector<int>, greater<int>> &minHeap) {
        if (!root) return {0, true};

        if (!root->left && !root->right) {  
            minHeap.push(1);
            if (minHeap.size() > k) minHeap.pop();
            return {1, true};
        }

        auto leftSearch = perfectSubtree(root->left, k, minHeap);
        auto rightSearch = perfectSubtree(root->right, k, minHeap);
        
        bool isPerfect = leftSearch.second && rightSearch.second && leftSearch.first == rightSearch.first;

        if (isPerfect) {
            int subtreeSize = 1 + leftSearch.first + rightSearch.first;
            minHeap.push(subtreeSize);
            if (minHeap.size() > k) minHeap.pop();
            return {subtreeSize, true};
        }
        return {0, false};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        perfectSubtree(root, k, minHeap);
        return (minHeap.size() < k) ? -1 : minHeap.top();
    }
};

/*
Question Link: https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/
Author: M.R.Naganathan
*/
