/*-------------------------------
Method: Memoization  
  Time Complexity: O(n * m * n)
  Space Complexity: O(n * m * n)
----------------------------------*/

class Solution {
public:
    int findForm(vector<vector<int>> &Counts, int i, int numZeroes, int numOnes, vector<vector<vector<int>>> &dp){
        if(i == Counts.size() || (numOnes == 0 && numZeroes == 0)) return 0;
        
        if(dp[i][numZeroes][numOnes] != -1) return dp[i][numZeroes][numOnes];

        int Pick = 0, noPick = 0;
        if(Counts[i][0] <= numZeroes && Counts[i][1] <= numOnes) Pick = 1 + findForm(Counts, i + 1, numZeroes - Counts[i][0], numOnes - Counts[i][1], dp);
        noPick = findForm(Counts, i + 1, numZeroes, numOnes, dp);
        return dp[i][numZeroes][numOnes] = max(Pick, noPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> Counts(strs.size(), vector<int> (2, 0));
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        for(int i = 0; i < strs.size(); i++){
            int numOnes = 0, numZeroes = 0;
            for(char c : strs[i]){
                if(c == '0') numZeroes += 1;
                if(c == '1') numOnes += 1;
            }
            Counts[i][0] = numZeroes;
            Counts[i][1] = numOnes;
        }
        return findForm(Counts, 0, m, n, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/ones-and-zeroes/
Author: M.R.Naganathan
*/
