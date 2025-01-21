/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = 0, secondRowSum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            firstRowSum += grid[0][i];
            secondRowSum += grid[1][i];
        }

        long long firstRobotScore = -1e9, secondRobotScore = LLONG_MAX;
        long long currFirstRowScore = 0, currSecondRowScore = 0;

        for (int i = 0; i < grid[0].size(); i++) {
            currFirstRowScore += grid[0][i];
            long long topRemaining = firstRowSum - currFirstRowScore;
            long long bottomRemaining = currSecondRowScore;
            long long currSecondRobotScore = max(topRemaining, bottomRemaining);
            secondRobotScore = min(secondRobotScore, currSecondRobotScore);
            currSecondRowScore += grid[1][i];
        }
        return secondRobotScore;
    }
};

/*
Question Link: https://leetcode.com/problems/grid-game/
Author: M.R.Naganathan
*/
