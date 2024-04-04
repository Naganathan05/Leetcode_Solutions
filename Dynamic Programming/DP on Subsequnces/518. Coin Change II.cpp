/*-------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * amount)
  Space Complexity: O(n * amount) + O(amount)
----------------------------------------------*/

class Solution {
public:
    int Coin(vector<int> &coins, int i, int amount, vector<vector<int>> &dp){
        if(!amount) return 1;
        if(i == 0){
            if(amount % coins[0] == 0 && amount >= coins[0]) return 1;
            return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int Pick = 0, noPick = 0;
        if(amount >= coins[i]) Pick = Coin(coins, i, amount - coins[i], dp);
        noPick = Coin(coins, i - 1, amount, dp);
        return dp[i][amount] = Pick + noPick;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return Coin(coins, coins.size() - 1, amount, dp);
    }
};

/*-------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * amount)
  Space Complexity: O(n * amount)
---------------------------------------------------*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        for(int i = 0; i <= coins.size() - 1; i++) dp[i][0] = 1;
        for(int i = 1; i <= amount; i++){
            if(i % coins[0] == 0 && i >= coins[0]) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i = 1; i <= coins.size() - 1; i++){
            for(int j = 1; j <= amount; j++){
                int Pick = 0, noPick = 0;
                if(j >= coins[i]) Pick = dp[i][j - coins[i]];
                noPick = dp[i - 1][j];
                dp[i][j] = Pick + noPick;
            }
        }
        return dp[coins.size() - 1][amount];
    }
};

/*-------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * amount)
  Space Complexity: O(amount)
---------------------------------------------------*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        curr[0] = 1;
        for(int i = 1; i <= amount; i++){
            if(i % coins[0] == 0 && i >= coins[0]) curr[i] = 1;
            else curr[i] = 0;
        }

        for(int i = 1; i <= coins.size() - 1; i++){
            prev = curr;
            for(int j = 1; j <= amount; j++){
                int Pick = 0, noPick = 0;
                if(j >= coins[i]) Pick = curr[j - coins[i]];
                noPick = prev[j];
                curr[j] = Pick + noPick;
            }
        }
        return curr[amount];
    }
};

/*
Question Link: https://leetcode.com/problems/coin-change-ii/description/
Author: M.R.Naganathan
*/
