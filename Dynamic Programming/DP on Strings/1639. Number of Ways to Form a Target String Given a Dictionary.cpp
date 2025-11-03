/*--------------------------------------------------------------------------------
Method: Memoization
  Time Complexity: O(wordLen * targetStringLen)
  Space Complexity: O(wordLen * targetStringLen) + max(wordLen, targetStringLen)
----------------------------------------------------------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    long long formString(vector<unordered_map<char, int>> &freq, string &target, int wordInd, int targetInd, vector<vector<long long>> &dp) {
        if(targetInd == target.length()) return 1;
        if(wordInd == freq.size()) return 0;
        if(dp[wordInd][targetInd] != -1) return dp[wordInd][targetInd];

        long long noPick = formString(freq, target, wordInd + 1, targetInd, dp);

        char requiredChar = target[targetInd];
        if(freq[wordInd][requiredChar] == 0) return dp[wordInd][targetInd] = noPick % mod;

        long long Pick = (freq[wordInd][requiredChar] * formString(freq, target, wordInd + 1, targetInd + 1, dp)) % mod;
        return dp[wordInd][targetInd] = (noPick + Pick) % mod;
    }

    int numWays(vector<string>& words, string target) {
        int wordLen = words[0].length();
        vector<vector<long long>> dp(wordLen, vector<long long> (target.length(), -1));
        vector<unordered_map<char, int>> freq(wordLen);
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].length(); j++) freq[j][words[i][j]] += 1;
        }

        return (int) formString(freq, target, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
Author: M.R.Naganathan
*/
