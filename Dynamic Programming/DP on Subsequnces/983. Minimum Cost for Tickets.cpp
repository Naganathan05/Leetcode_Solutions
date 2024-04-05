/*-----------------------------------------
Method 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
--------------------------------------------*/

class Solution {
public:
    int Cost(vector<int> &days, vector<int> &cost, int i, vector<int> &dp){
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int one_cost = INT_MAX, seven_cost = INT_MAX, thirty_cost = INT_MAX;
        one_cost = cost[0] + Cost(days, cost, i + 1, dp);
        int j = i;
        while(j < days.size() && days[j] <= days[i] + 6){
            j += 1;
        }
        seven_cost = cost[1] + Cost(days, cost, j, dp);
        j = i;
        while(j < days.size() && days[j] <= days[i] + 29){
            j += 1;
        }
        thirty_cost = cost[2] + Cost(days, cost, j, dp);
        return dp[i] = min(one_cost, min(seven_cost, thirty_cost));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return Cost(days, costs, 0, dp);
    }
};

/*------------------------------------
Method 2: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, 0);
        dp[days.size()] = 0;

        for(int i = days.size() - 1; i >= 0; i--){
            int one_cost = INT_MAX, seven_cost = INT_MAX, thirty_cost = INT_MAX;
            one_cost = costs[0] + dp[i + 1];
            int j = i;
            while(j < days.size() && days[j] <= days[i] + 6){
                j += 1;
            }
            seven_cost = costs[1] + dp[j];
            j = i;
            while(j < days.size() && days[j] <= days[i] + 29){
                j += 1;
            }
            thirty_cost = costs[2] + dp[j];
            dp[i] = min(one_cost, min(seven_cost, thirty_cost));
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/
Author: M.R.Naganathan
*/
