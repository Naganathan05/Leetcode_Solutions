/*-------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int currMissing = arr[mid] - (mid + 1);
            if(currMissing >= k) high = mid - 1;
            else low = mid + 1;
        }
        if (high == -1) return k;
        int moreNum = k - (arr[high] - (high + 1));
        return arr[high] + moreNum;
    }
};

/*
Question Link: https://leetcode.com/problems/kth-missing-positive-number/
Author: M.R.Naganathan
*/
