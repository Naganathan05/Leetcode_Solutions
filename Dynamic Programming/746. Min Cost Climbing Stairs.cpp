/*-----------------------------------------------
Approach 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------------*/

class Solution {
public:

    int recursiveFunction(vector<int> &cost, int ind, vector<int> &dp){

        if(ind < 0) return 0;
        if(ind == 0 || ind == 1) return cost[ind];

        if(dp[ind] != -1) return dp[ind];

        int oneStep = recursiveFunction(cost, ind - 1, dp);
        int twoStep = recursiveFunction(cost, ind - 2, dp);
        dp[ind] = cost[ind] + min(oneStep, twoStep);
        return dp[ind];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(recursiveFunction(cost, cost.size() - 1, dp), recursiveFunction(cost, cost.size() - 2, dp));
    }
};

/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------------------*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i <= cost.size() - 1; i++){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

/*---------------------------------------------------------
Method 2: Space Optimization
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------------------*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        int most_prev = cost[0];
        int prev = cost[1], curr;

        for(int i = 2; i <= cost.size() - 1; i++){
            curr = cost[i] + min(prev, most_prev);
            most_prev = prev;
            prev = curr;
        }
        return min(prev, most_prev);
    }
};

/*
Question Link: https://leetcode.com/problems/min-cost-climbing-stairs/
Author: M.R.Naganathan
*/
