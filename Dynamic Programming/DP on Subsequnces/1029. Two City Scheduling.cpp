/*----------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------*/

class Solution {
public:
    int Schedule(vector<vector<int>> &costs, int i, int firstCitySize, int n, vector<vector<int>> &dp){
        if(firstCitySize > n || (i - firstCitySize) > n) return 1e9;
        if(i == costs.size()) return 0;
        if(dp[i][firstCitySize] != -1) return dp[i][firstCitySize];

        int moveToCityA = costs[i][0] + Schedule(costs, i + 1, firstCitySize + 1, n, dp);
        int moveToCityB = costs[i][1] + Schedule(costs, i + 1, firstCitySize, n, dp);
        return dp[i][firstCitySize] = min(moveToCityA, moveToCityB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        n /= 2;
        vector<vector<int>> dp(costs.size(), vector<int> (n + 1, -1));
        return Schedule(costs, 0, 0, n, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/two-city-scheduling/
Author: M.R.Naganathan
*/
