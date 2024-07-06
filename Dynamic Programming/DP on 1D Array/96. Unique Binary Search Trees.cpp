/*-------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
----------------------------------*/

class Solution {
public:
    int DP(int n, vector<int> &dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int count = 0;
        for(int i = 1; i <= n; i++){
            count += (DP(i - 1, dp) * DP(n - i, dp));
        }
        return dp[n] = count;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return DP(n, dp);
    }
};

/*----------------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-------------------------------------*/

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};

/*
Question Link: https://leetcode.com/problems/unique-binary-search-trees/description/
Author: M.R.Naganathan
*/
