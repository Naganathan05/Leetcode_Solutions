/*----------------------------------
Method: Memoization => TLE :(
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------*/

class Solution {
public:
    int burstBalloons(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maximumCoins = 0;
        for(int k = i; k <= j; k++) {
            int currCoins = (nums[i - 1] * nums[k] * nums[j + 1]);
            currCoins += burstBalloons(nums, i, k - 1, dp);
            currCoins += burstBalloons(nums, k + 1, j, dp);
            maximumCoins = max(maximumCoins, currCoins);
        }
        return maximumCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return burstBalloons(nums, 1, n - 2, dp);
    }
};

/*-------------------------------
Method: Tabulation
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n)
---------------------------------*/

class Solution {
public:
    int burstBalloons(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maximumCoins = 0;
        for(int k = i; k <= j; k++) {
            int currCoins = (nums[i - 1] * nums[k] * nums[j + 1]);
            currCoins += burstBalloons(nums, i, k - 1, dp);
            currCoins += burstBalloons(nums, k + 1, j, dp);
            maximumCoins = max(maximumCoins, currCoins);
        }
        return maximumCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 2; i >= 1; i--) {
            for(int j = i; j <= n - 2; j++) {
                int maximumCoins = 0;
                for(int k = i; k <= j; k++) {
                    int currCoins = (nums[i - 1] * nums[k] * nums[j + 1]);
                    currCoins += dp[i][k - 1];
                    currCoins += dp[k + 1][j];
                    maximumCoins = max(maximumCoins, currCoins);
                }
                dp[i][j] = maximumCoins;
            }
        }
        return dp[1][n - 2];
    }
};

/*
Question Link: https://leetcode.com/problems/burst-balloons/
Author: M.R.Naganathan
*/
