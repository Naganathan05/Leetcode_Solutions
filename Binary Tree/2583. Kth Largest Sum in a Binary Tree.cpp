/*-----------------------------
  Time Complexity: O(n * logh)
  Space Complexity: O(h)
-------------------------------*/

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> fifo;
        fifo.push(root);
        while(!fifo.empty()){
            long long currSum = 0;
            int size = fifo.size();
            for(int i = 0; i <= size - 1; i++){
                TreeNode* currNode = fifo.front();
                fifo.pop();

                if(currNode -> left) fifo.push(currNode -> left);
                if(currNode -> right) fifo.push(currNode -> right);
                currSum += currNode -> val;
            }
            minHeap.push(currSum);
            if(minHeap.size() > k) minHeap.pop();
        }
        if(minHeap.size() < k) return -1;
        return minHeap.top();
    }
};

/*
Question Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
Author: M.R.Naganathan
*/
