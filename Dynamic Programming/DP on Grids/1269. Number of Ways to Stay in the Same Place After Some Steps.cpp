/*------------------------------------------------
Method 1: Memoization
  Time Complexity: O(arrLen * steps)
  Space Complexity: O(arrLen * steps) + O(steps)
--------------------------------------------------*/

class Solution {
public:
    int num(int x, int steps, int arrLen, vector<vector<int>> &dp){
        if(x == 0 && steps == 0) return 1;
        if(steps == 0) return 0;

        if(dp[x][steps] != -1) return dp[x][steps];

        long left = 0, right = 0, stay = 0;
        if(x - 1 >= 0) left = num(x - 1, steps - 1, arrLen, dp);
        if(x + 1 < arrLen) right = num(x + 1, steps - 1, arrLen, dp);
        stay = num(x, steps - 1, arrLen, dp);
        return dp[x][steps] = (left + right + stay) % (1000000007);
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps, vector<int> (steps + 1, -1));
        return num(0, steps, arrLen, dp);
    }
};

/*----------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(arrLen * steps)
  Space Complexity: O(arrLen * steps)
-------------------------------------------------------*/

class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(arrLen, vector<int> (steps + 1, 0));

        dp[0][0] = 1;
        for(int i = 1; i <= arrLen - 1; i++) dp[i][0] = 0;

        for(int step = 1; step <= steps; step++) {
            for(int i = arrLen - 1; i >= 0; i--) {
                long left = (i - 1 >= 0) ? dp[i - 1][step - 1] : 0;
                long right = (i + 1 < arrLen) ? dp[i + 1][step - 1] : 0;
                long stay = dp[i][step - 1];
                dp[i][step] = (left + right + stay) % 1000000007;
            }
        } 
        return dp[0][steps];
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
Author: M.R.Naganathan
*/
