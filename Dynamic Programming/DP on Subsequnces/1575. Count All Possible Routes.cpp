/*---------------------------------------
Method: Memoization
  Time Complexity: O(n * fuel)
  Space Complexity: O(n * fuel) + O(n)
-----------------------------------------*/

class Solution {
    int mod = 1e9 + 7;
public:
    int Route(vector<int> &locations, int i, int finish, int fuel, vector<vector<int>> &dp){
        if (fuel < 0) return 0;
        
        if (dp[i][fuel] != -1) return dp[i][fuel];

        int totalWays = (i == finish) ? 1 : 0;

        for (int j = 0; j < locations.size(); j++){
            if (i != j){
                int fuelRequired = abs(locations[i] - locations[j]);
                if (fuel >= fuelRequired) {
                    totalWays = (totalWays + Route(locations, j, finish, fuel - fuelRequired, dp)) % mod;
                }
            }
        }
        return dp[i][fuel] = totalWays; 
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel + 1, -1));
        return Route(locations, start, finish, fuel, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/count-all-possible-routes/
Author: M.R.Naganathan
*/
