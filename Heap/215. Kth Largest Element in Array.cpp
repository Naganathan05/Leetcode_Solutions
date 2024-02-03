/*---------------------------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> queue;
        int cnt = 0;
        for(int i : nums){
            queue.push(i);
        }
        while(true){
            int ele = queue.top();
            queue.pop();
            cnt += 1;
            if(cnt == k) return ele;
        }
    }
};

/*
Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
Author: M.R.Naganathan
*/
