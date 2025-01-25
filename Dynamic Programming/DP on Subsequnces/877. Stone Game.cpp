/*-----------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------*/

class Solution {
public:
    bool pickStone(vector<int> &piles, int low, int high, int turn, vector<vector<vector<int>>> &dp){
        if(low > high) return 0;
        if(dp[low][high][turn] != -1) return dp[low][high][turn];

        if(turn){
            int pickFront = piles[low] + pickStone(piles, low + 1, high, 0, dp);
            int pickBack = piles[high] + pickStone(piles, low, high - 1, 0, dp);
            return dp[low][high][turn] = max(pickFront, pickBack);
        }

        int pickFront = -piles[low] + pickStone(piles, low + 1, high, 1, dp);
        int pickBack = -piles[high] + pickStone(piles, low, high - 1, 1, dp);
        return dp[low][high][turn] = max(pickFront, pickBack);
    }

    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size(), vector<vector<int>> (piles.size(), vector<int> (2, -1)));
        int maxPoints = pickStone(piles, 0, piles.size() - 1, 1, dp);
        return maxPoints >= 0;
    }
};

/*
Question Link: https://leetcode.com/problems/stone-game/
Author: M.R.Naganathan
*/
