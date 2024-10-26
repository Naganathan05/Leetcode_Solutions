/*----------------------------------
  Time Complexity: O(n * k * k)
  Space Complexity: O(n * k) + O(n)
-------------------------------------*/

class Solution {
public:
    int Migrate(int n, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore, int day, int city, vector<vector<int>> &dp) {
        if(day == 0) return 0;
        if(dp[day][city] != -1) return dp[day][city];

        int stayPoints = stayScore[day-1][city] + Migrate(n, stayScore, travelScore, day - 1, city, dp);
        int travelPoints = 0;
        for(int dest = 0; dest < n; dest++) {
            int currPoints = travelScore[city][dest] + Migrate(n, stayScore, travelScore, day - 1, dest, dp);
            travelPoints = max(travelPoints, currPoints);
        }
        return dp[day][city] = max(stayPoints, travelPoints);
    }
    
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k + 1, vector<int> (n, 0));
        for(int day = 0; day < k; day++){
            for(int currCity = 0; currCity < n; currCity++){
                dp[day + 1][currCity] = max(dp[day + 1][currCity], dp[day][currCity] + stayScore[day][currCity]);
                for(int dest = 0; dest < n; dest++){
                    if(dest == currCity) continue;
                    dp[day + 1][dest] = max(dp[day + 1][dest], dp[day][currCity] + travelScore[currCity][dest]);
                }
            }
        }

        int maxPoints = 0;
        for(int city = 0; city < n; city++) maxPoints = max(maxPoints, dp[k][city]);
        return maxPoints;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-points-tourist-can-earn/
Author: M.R.Naganathan
*/
