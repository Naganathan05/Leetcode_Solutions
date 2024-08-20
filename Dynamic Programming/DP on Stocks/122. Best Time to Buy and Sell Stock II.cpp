/*--------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
-----------------------------------*/

class Solution {
public:
    int Stocks(vector<int> &prices, int i, int option, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;

        if(dp[i][option] != -1) return dp[i][option];

        int currProfit;
        if(option == 0) currProfit = max(-prices[i] + Stocks(prices, i + 1, 1, dp), Stocks(prices, i + 1, 0, dp));
        else currProfit = max(prices[i] + Stocks(prices, i + 1, 0, dp), Stocks(prices, i + 1, 1, dp));
        return dp[i][option] = currProfit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return Stocks(prices, 0, 0, dp);
    }
};

/*--------------------------
Method: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, 0));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int option = 0; option <= 1; option++){
                int currProfit;
                if(option == 0) currProfit = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
                else currProfit = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
                dp[i][option] = currProfit;
            }
        }
        return dp[0][0];
    }
};

/*----------------------------
Method: Space Optimization
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(2, 0), curr(2, 0);
        
        for(int i = prices.size() - 1; i >= 0; i--){
            prev = curr;
            for(int option = 0; option <= 1; option++){
                int currProfit;
                if(option == 0) currProfit = max(-prices[i] + prev[1], prev[0]);
                else currProfit = max(prices[i] + prev[0], prev[1]);
                curr[option] = currProfit;
            }
        }
        return curr[0];
    }
};

/*
Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
Author: M.R.Naganathan
*/
