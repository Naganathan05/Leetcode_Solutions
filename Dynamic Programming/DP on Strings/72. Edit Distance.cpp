/*--------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * m)
  Space Complexity: (n * m) + O(max(n, m))
-----------------------------------------------*/

class Solution {
public:
    int distance(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = distance(word1, word2, i - 1, j - 1, dp);

        int del_cost = 1 + distance(word1, word2, i - 1, j, dp);
        int rep_cost = 1 + distance(word1, word2, i - 1, j - 1, dp);
        int ins_cost = 1 + distance(word1, word2, i, j - 1, dp);
        return dp[i][j] = min(del_cost, min(rep_cost, ins_cost));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), -1));
        return distance(word1, word2, word1.length() - 1, word2.length() - 1, dp);
    }
};

/*-------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
----------------------------------------------------*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, 0));

        for(int i = 0; i <= word2.length(); i++) dp[0][i] = i;
        for(int i = 0; i <= word1.length(); i++) dp[i][0] = i;

        for(int i = 1; i <= word1.length(); i++){
            for(int j = 1; j <= word2.length(); j++){
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    int del_cost = 1 + dp[i - 1][j];
                    int rep_cost = 1 + dp[i - 1][j - 1];
                    int ins_cost = 1 + dp[i][j - 1];
                    dp[i][j] = min(del_cost, min(rep_cost, ins_cost));
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

/*----------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * n)
  Space Complexity: O(2 * n)
------------------------------------------------------*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.length() + 1, 0), curr(word2.length() + 1, 0);

        for(int i = 0; i <= word2.length(); i++) curr[i] = i;

        for(int i = 1; i <= word1.length(); i++){
            prev = curr;
            for(int j = 1; j <= word2.length(); j++){
                if(word1[i - 1] == word2[j - 1]) curr[j] = prev[j - 1];
                else{
                    int del_cost = 1 + prev[j];
                    int rep_cost = 1 + prev[j - 1];
                    int ins_cost = 1 + curr[j - 1];
                    curr[j] = min(del_cost, min(rep_cost, ins_cost));
                }
            }
            curr[0] = i;
        }
        return curr[word2.length()];
    }
};

/*
Question Link: https://leetcode.com/problems/edit-distance/description/
Author: M.R.Naganathan
*/
