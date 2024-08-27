/*------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
---------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    int Texts(string &pressedKeys, int i, vector<int> &dp){
        if(i == pressedKeys.length()) return 1;
        if(dp[i] != -1) return dp[i];

        int maxKeyPress = 3;
        if(pressedKeys[i] == '7' || pressedKeys[i] == '9') maxKeyPress = 4;
        long long ind = i, currPress = 0, totalCount = 0;
        while(pressedKeys[ind] == pressedKeys[i] && maxKeyPress > currPress){
            ind += 1;
            currPress += 1;
            totalCount += (Texts(pressedKeys, ind, dp) % mod);
        }
        return dp[i] = totalCount % mod;
    }

    int countTexts(string pressedKeys) {
        vector<int> dp(pressedKeys.length(), -1);
        return Texts(pressedKeys, 0, dp);
    }
};

/*--------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int countTexts(string pressedKeys) {
        vector<int> dp(pressedKeys.length() + 1, 0);
        dp[pressedKeys.length()] = 1;
        
        for(int i = pressedKeys.length() - 1; i >= 0; i--){
            int maxKeyPress = 3;
            if(pressedKeys[i] == '7' || pressedKeys[i] == '9') maxKeyPress = 4;
            long long ind = i, currPress = 0, totalCount = 0;
            while(ind < pressedKeys.length() && pressedKeys[ind] == pressedKeys[i] && maxKeyPress > currPress){
                ind += 1;
                currPress += 1;
                totalCount += ((dp[ind]) % mod);
            }
            dp[i] = totalCount % mod;
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/count-number-of-texts/description/
Author: M.R.Naganathan
*/
