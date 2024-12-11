/*--------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long completeRows = (long long)mid * (mid + 1) / 2;
            if(completeRows <= n){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/arranging-coins/
Author: M.R.Naganathan
*/
