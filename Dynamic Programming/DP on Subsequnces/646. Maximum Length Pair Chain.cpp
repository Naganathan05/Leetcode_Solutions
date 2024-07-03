/*-------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n ) + O(n)
--------------------------------------*/

class Solution {
public:
    int Chain(vector<vector<int>> &pairs, int i, int prevInd, vector<vector<int>> &dp){
        if(i == pairs.size()) return 0;
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];

        int Pick = 0, noPick = 0;
        if(prevInd == -1 || pairs[prevInd][1] < pairs[i][0]) Pick = 1 + Chain(pairs, i + 1, i, dp);
        noPick = Chain(pairs, i + 1, prevInd, dp);
        return dp[i][prevInd + 1] = max(Pick, noPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<vector<int>> dp(pairs.size(), vector<int> (pairs.size() + 1, -1));
        return Chain(pairs, 0, -1, dp);
    }
};

/*----------------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------------*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<vector<int>> dp(pairs.size() + 1, vector<int> (pairs.size() + 1, 0));
        for(int i = pairs.size() - 1; i >= 0; i--){
            for(int prevInd = pairs.size() - 1; prevInd >= -1; prevInd--){
                int noTake = dp[i + 1][prevInd + 1];
                int take = 0;
                if(prevInd == -1 || pairs[prevInd][1] < pairs[i][0]){
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prevInd + 1] = max(take, noTake); 
            }
        }
        return dp[0][0];
    }
};

/*-----------------------------------
Method: Space Optimzation  
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> curr(pairs.size() + 1, 0), prev(pairs.size() + 1, 0);
        for(int i = pairs.size() - 1; i >= 0; i--){
            prev = curr;
            for(int prevInd = pairs.size() - 1; prevInd >= -1; prevInd--){
                int noTake = prev[prevInd + 1];
                int take = 0;
                if(prevInd == -1 || pairs[prevInd][1] < pairs[i][0]){
                    take = 1 + prev[i + 1];
                }
                curr[prevInd + 1] = max(take, noTake); 
            }
        }
        return curr[0];
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
Author: M.R.Naganathan
*/
