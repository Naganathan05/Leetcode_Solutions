/*----------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------*/

class Solution {
public:
    bool Cross(vector<int> &stones, unordered_map<int, int> &freq, int i, int prevJump, vector<vector<int>> &dp) {
        if (i == stones.size() - 1) return true;
        if (dp[i][prevJump] != -1) return dp[i][prevJump];
        
        bool result = false;
        int nextIndex = -1;
        if (prevJump > 0) {
            if (freq.find(stones[i] + prevJump) != freq.end()) nextIndex = freq[stones[i] + prevJump];
            if (nextIndex != -1) result |= (Cross(stones, freq, nextIndex, prevJump, dp));
        }
        nextIndex = -1;
        if (prevJump - 1 > 0) {
            if (freq.find(stones[i] + prevJump - 1) != freq.end()) nextIndex = freq[stones[i] + prevJump - 1];
            if (nextIndex != -1) result |= (Cross(stones, freq, nextIndex, prevJump - 1, dp));
        }
        nextIndex = -1;
        if (freq.find(stones[i] + prevJump + 1) != freq.end()) nextIndex = freq[stones[i] + prevJump + 1];
        if (nextIndex != -1) result |= (Cross(stones, freq, nextIndex, prevJump + 1, dp));
        
        return dp[i][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        unordered_map<int, int> freq;
        for (int i = 0; i <= stones.size() - 1; i++) freq[stones[i]] = i;
        return Cross(stones, freq, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/frog-jump/
Author: M.R.Naganathan
*/
