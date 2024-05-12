/*----------------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
------------------------------------------------*/

class Solution {
public:
    int Energy(vector<int>& energy, int i, int k, vector<int> &dp){
        if(i >= energy.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int Pick;
        Pick = energy[i] + Energy(energy, i + k, k, dp);
        return dp[i] = Pick;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(), -1);
        int maxEnergy = INT_MIN;
        for(int i = 0; i <= energy.size() - 1; i++) maxEnergy = max(maxEnergy, Energy(energy, i, k, dp));
        return maxEnergy;
    }
};

/*--------------------------------------------------
Method: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------------------*/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size() + k, 0);
        int maxEnergy = INT_MIN;

        for(int i = energy.size() - 1; i >= 0; i--){
            int Pick = energy[i] + dp[i + k];
            dp[i] = Pick;
        }
        for(int i = 0; i <= energy.size() - 1; i++) maxEnergy = max(maxEnergy, dp[i]);
        return maxEnergy;
    }
};

/*
Question Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/
Author: M.R.Naganathan
*/
