/*-------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
----------------------------------*/

class Solution {
public:
    int Stocks(vector<int> &prices, int i, int numTrans, int option, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || numTrans == 2) return 0;

        if(dp[i][numTrans][option] != -1) return dp[i][numTrans][option];

        int currProfit;
        if(option == 0) currProfit = max(-prices[i] + Stocks(prices, i + 1, numTrans, 1, dp), Stocks(prices, i + 1, numTrans, 0, dp));
        else currProfit = max(prices[i] + Stocks(prices, i + 1, numTrans + 1, 0, dp), Stocks(prices, i + 1, numTrans, 1, dp));
        return dp[i][numTrans][option] = currProfit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (3, vector<int> (2, -1)));
        return Stocks(prices, 0, 0, 0, dp);
    }
};

/*--------------------------
Method: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>> (3, vector<int> (2, 0)));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int numTrans = 0; numTrans <= 1; numTrans++){
                for(int option = 0; option <= 1; option++){
                    int currProfit;
                    if(option == 0) currProfit = max(-prices[i] + dp[i + 1][numTrans][1], dp[i + 1][numTrans][0]);
                    else currProfit = max(prices[i] + dp[i + 1][numTrans + 1][0], dp[i + 1][numTrans][1]);
                    dp[i][numTrans][option] = currProfit;
                }
            }
        }
        return dp[0][0][0];
    }
};

/*----------------------------
Method: Space Optimization
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> prev(3, vector<int> (2, 0)), curr(3, vector<int> (2, 0));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            prev = curr;
            for(int numTrans = 0; numTrans <= 1; numTrans++){
                for(int option = 0; option <= 1; option++){
                    int currProfit;
                    if(option == 0) currProfit = max(-prices[i] + prev[numTrans][1], prev[numTrans][0]);
                    else currProfit = max(prices[i] + prev[numTrans + 1][0], prev[numTrans][1]);
                    curr[numTrans][option] = currProfit;
                }
            }
        }
        return curr[0][0];
    }
};

/*
Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
Author: M.R.Naganathan
*/
