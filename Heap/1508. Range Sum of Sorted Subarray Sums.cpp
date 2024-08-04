/*----------------------------------
  Time Complexity: O(n * n * logn)
  Space Complexity: O(right - left)
-------------------------------------*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        priority_queue<int> maxHeap;
        
        for (int i = 0; i < n; ++i) {
            int currSum = 0;
            for (int j = i; j < n; ++j) {
                currSum += nums[j];
                maxHeap.push(currSum);
                if (maxHeap.size() > right) maxHeap.pop();
            }
        }

        int reqSum = 0;
        for (int i = 0; i < right - left + 1; i++) {
            reqSum = (reqSum + maxHeap.top()) % mod;
            maxHeap.pop();
        }
        return reqSum;
    }
};

/*
Question Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
Author: M.R.Naganathan
*/
