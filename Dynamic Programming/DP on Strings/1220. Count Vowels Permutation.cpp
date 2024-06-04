/*-----------------------------------------
Method: Memoization
  Time Complexity: O(n * 5)
  Space Complexity: O(n) + O(n)
-------------------------------------------*/

#include <vector>

class Solution {
    const int mod = 1e9 + 7;
public:
    int Vowel(int n, int lastVowel, vector<vector<int>> &dp){
        if (n == 0) return 1;
        
        if (lastVowel != -1 && dp[n][lastVowel] != -1) return dp[n][lastVowel];

        int totalWays = 0;
        if (lastVowel == 1) totalWays = Vowel(n - 1, 2, dp) % mod;
        if (lastVowel == 2) totalWays = (Vowel(n - 1, 1, dp) + Vowel(n - 1, 3, dp)) % mod;
        if (lastVowel == 3) totalWays = ((Vowel(n - 1, 1, dp) + Vowel(n - 1, 2, dp)) % mod + (Vowel(n - 1, 4, dp) + Vowel(n - 1, 5, dp)) % mod) % mod;
        if (lastVowel == 4) totalWays = (Vowel(n - 1, 3, dp) + Vowel(n - 1, 5, dp)) % mod;
        if (lastVowel == 5) totalWays = Vowel(n - 1, 1, dp) % mod;
        if (lastVowel == -1) totalWays = (((Vowel(n - 1, 1, dp) + Vowel(n - 1, 2, dp)) % mod + (Vowel(n - 1, 3, dp) + Vowel(n - 1, 4, dp)) % mod) % mod + Vowel(n - 1, 5, dp)) % mod;

        if (lastVowel != -1) return dp[n][lastVowel] = totalWays;
        return totalWays;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, -1));
        return Vowel(n, -1, dp) % mod;
    }
};

/*
Question Link: https://leetcode.com/problems/count-vowels-permutation/
Author: M.R.Naganathan
*/
