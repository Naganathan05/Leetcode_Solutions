/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    bool Jump(vector<int> &arr, int i, vector<int> &dp) {
        if (i < 0 || i >= arr.size() || arr[i] == -1) return false;
        if (arr[i] == 0) return true;

        if (dp[i] != -1) return dp[i];

        int temp = arr[i];
        arr[i] = -1;
        bool jumpForward = Jump(arr, i + temp, dp);
        bool jumpBackward = Jump(arr, i - temp, dp);
        arr[i] = temp;
        
        return dp[i] = (jumpForward || jumpBackward);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(), -1);
        return Jump(arr, start, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game-iii/
Author: M.R.Naganathan
*/
