/*-------------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * target)
  Space Complexity: O(n * target) + O(target)
---------------------------------------------------*/

class Solution {
public:
    int Coin(vector<int> &coins, int i, int amount, vector<vector<int>> &dp){
        if(i == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        if(amount == 0) return 0;
        if(amount < 0) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int Pick = INT_MAX, noPick;

        Pick = 1 + Coin(coins, i, amount - coins[i], dp);

        noPick = Coin(coins, i - 1, amount, dp);
        return dp[i][amount] = min(Pick, noPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        int coin = Coin(coins, coins.size() - 1, amount, dp);
        if(coin >= 1e9) return -1;
        return coin;
    }
};

/*--------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * target)
  Space Complexity: O(n * target)
-----------------------------------------------------*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, 0));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1; i <= coins.size() - 1; i++){
            for(int t = 0; t <= amount; t++){
                int Pick = INT_MAX, noPick;
                noPick = dp[i - 1][t];
                if(t >= coins[i]) Pick = 1 + dp[i][t - coins[i]];
                dp[i][t] = min(Pick, noPick);
            }
        }
        int coin = dp[coins.size() - 1][amount];
        if(coin >= 1e9) return -1;
        return coin;
    }
};

/*---------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * target)
  Space Complexity: O(target)
-----------------------------------------------------*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) curr[i] = i/coins[0];
            else curr[i] = 1e9;
        }

        for(int i = 1; i <= coins.size() - 1; i++){
            prev = curr;
            for(int t = 0; t <= amount; t++){
                int Pick = INT_MAX, noPick;
                noPick = prev[t];
                if(t >= coins[i]) Pick = 1 + curr[t - coins[i]];
                curr[t] = min(Pick, noPick);
            }
        }
        int coin = curr[amount];
        if(coin >= 1e9) return -1;
        return coin;
    }
};

/*
Question Link: https://leetcode.com/problems/coin-change/description/
Author: M.R.Naganathan
*/
