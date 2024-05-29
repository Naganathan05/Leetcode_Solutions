/*------------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
---------------------------------------------*/

class Solution {
public:
    double soup(int a, int b, vector<vector<double>> &dp){
        if(a > 0 && b <= 0) return 0;
        if(a <= 0 && b > 0) return 1;
        if(a <= 0 && b <= 0) return 0.5;

        if(dp[a][b] != -1) return dp[a][b];

        double option1 = 0.25 * soup(a - 100, b, dp);
        double option2 = 0.25 * soup(a -75, b - 25, dp);
        double option3 = 0.25 * soup(a - 50, b - 50, dp);
        double option4 = 0.25 * soup(a - 25, b - 75, dp);
        return dp[a][b] = option1 + option2 + option3 + option4;
    }

    double soupServings(int n) {
        if(n > 5e3) return 1;
        vector<vector<double>> dp(n + 1, vector<double> (n + 1, -1));
        return soup(n, n, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/soup-servings/
Author: M.R.Naganathan
*/
