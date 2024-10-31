/*----------------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m) + O(n)
-------------------------------------*/

class Solution {
public:
    long long Repair(vector<int>& robot, vector<vector<int>>& factory, int i, int j, vector<vector<long long>>& dp) {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return LLONG_MAX;
        
        if (dp[i][j] != -1) return dp[i][j];

        long long minCost = Repair(robot, factory, i, j + 1, dp);
        long long currCost = 0;
        
        for (int k = 0; k < factory[j][1] && i + k < robot.size(); k++) {
            currCost += abs(robot[i + k] - factory[j][0]);
            long long nextCost = Repair(robot, factory, i + k + 1, j + 1, dp);
            if (nextCost != LLONG_MAX) minCost = min(minCost, currCost + nextCost);
        }
        return dp[i][j] = minCost;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(robot.size(), vector<long long>(factory.size(), -1));
        return Repair(robot, factory, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-total-distance-traveled/
Author: M.R.Naganathan
*/
