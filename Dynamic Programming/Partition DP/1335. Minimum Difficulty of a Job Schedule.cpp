/*----------------------------------
  Time Complexity: O(n * n * d)
  Space Complexity: O(n * d) + O(d)
------------------------------------*/

class Solution {
public:
    int scheduleJob(vector<int> &jobDifficulty, int i, int day, int d, vector<vector<int>> &dp){
        if(i == jobDifficulty.size() && day < d) return 1e9;
        if(i == jobDifficulty.size() && day == d) return 0;
        if(day > d) return 1e9;

        if(dp[i][day] != -1) return dp[i][day];

        int currMax = -1e9, minDifficulty = 1e9;
        for(int j = i; j <= jobDifficulty.size() - 1; j++){
            currMax = max(currMax, jobDifficulty[j]);
            int scheduleDifficulty = currMax + scheduleJob(jobDifficulty, j + 1, day + 1, d, dp);
            minDifficulty = min(scheduleDifficulty, minDifficulty);
        }
        return dp[i][day] = minDifficulty;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size(), vector<int> (d + 1, -1));
        int scheduleDifficulty = scheduleJob(jobDifficulty, 0, 0, d, dp);
        if(scheduleDifficulty >= 1e9) return -1;
        return scheduleDifficulty;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
Author: M.R.Naganathan
*/
