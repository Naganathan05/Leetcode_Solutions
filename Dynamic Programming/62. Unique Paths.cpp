/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m*n)
  Space Complexity: O(m*n)
-------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(int m, int n, int i, int j, vector<vector<int>> &dp){
	    if(i == m - 1 && j == n - 1){
		    return 1;
	    }

	    if(dp[i][j] != -1) return dp[i][j];
	    int down = 0, right = 0;

	    if(i + 1 <= m - 1){
		    down = recursiveFunction(m, n, i + 1, j, dp);
	    }
	    if(j + 1 <= n - 1){
		    right = recursiveFunction(m , n, i, j + 1, dp);
	    }

	    return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return recursiveFunction(m, n, 0, 0, dp);
    }
};

/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(m*n)
  Space Complexity: O(m*n)
-----------------------------------------------------------*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(!i && !j) dp[0][0] = 1;
                else{
                    int up = 0, left = 0;
                    if(i - 1 >= 0)  up = dp[i - 1][j];
                    if(j - 1 >= 0)  left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/unique-paths/description/
Author: M.R.Naganathan
*/

