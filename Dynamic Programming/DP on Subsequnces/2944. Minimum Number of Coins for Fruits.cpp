/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------*/

class Solution {
public:
    int Coins(vector<int> &prices, int i, int reward, vector<vector<int>> &dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][reward] != -1) return dp[i][reward];

        int freeReward = 1e9, buyFruit = 1e9;
        if(i <= reward) freeReward = Coins(prices, i + 1, reward, dp);
        int maxReward = max((2 * i) + 1, reward);
        if(maxReward >= prices.size()) maxReward = prices.size() - 1;
        buyFruit = prices[i] + Coins(prices, i + 1, maxReward, dp);
        return dp[i][reward] = min(freeReward, buyFruit);
    }

    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (prices.size(), -1));
        return prices[0] + Coins(prices, 1, 1, dp);
    }
};

/*---------------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------------*/

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int numFruits = prices.size();
        if(numFruits == 1) return prices[0];
        vector<vector<int>> dp(numFruits + 1, vector<int> (numFruits, 0));

        for (int i = numFruits - 1; i >= 1; i--) {
            for (int rewardUntil = numFruits - 1; rewardUntil >= 1; rewardUntil--) {
                int freeReward = 1e9, buyFruit = 1e9;
                if (i <= rewardUntil) freeReward = dp[i + 1][rewardUntil];
                int maxReward = max((2 * i) + 1, rewardUntil);
                if (maxReward >= numFruits) maxReward = numFruits - 1;
                buyFruit = prices[i] + dp[i + 1][maxReward];
                dp[i][rewardUntil] = min(freeReward, buyFruit);
            }
        }
        return prices[0] + dp[1][1];
    }
};

/*-------------------------------
Method: Space Optimization  
  Time Complexity: O(n * n)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int numFruits = prices.size();
        if(numFruits == 1) return prices[0];
        vector<vector<int>> dp(numFruits + 1, vector<int> (numFruits, 0));
        vector<int> curr(numFruits, 0), prev(numFruits, 0);

        for (int i = numFruits - 1; i >= 1; i--) {
            prev = curr;
            for (int rewardUntil = numFruits - 1; rewardUntil >= 1; rewardUntil--) {
                int freeReward = 1e9, buyFruit = 1e9;
                if (i <= rewardUntil) freeReward = prev[rewardUntil];
                int maxReward = max((2 * i) + 1, rewardUntil);
                if (maxReward >= numFruits) maxReward = numFruits - 1;
                buyFruit = prices[i] + prev[maxReward];
                curr[rewardUntil] = min(freeReward, buyFruit);
            }
        }
        return prices[0] + curr[1];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/
Author: M.R.Naganathan
*/
