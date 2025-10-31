/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * n * n * n)
  Space Complexity: O(n * n * n)
-------------------------------------*/

class Solution {
public:
    bool matchString(string &s1, string &s2, int i, int j, int k) {
        int ind = i;
        while(ind <= j && s1[ind] == s2[k]) {
            ind += 1;
            k += 1;
        }
        return (ind == j + 1);
    }

    bool scrambleString(string &s1, string &s2, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if(i > j) return (k == s2.length());
        if(dp[i][j][k] != -1) return dp[i][j][k];

        if(matchString(s1, s2, i, j, k)) return dp[i][j][k] = true;

        bool scramblePossible = false;
        for(int split = i; split < j; split++) {
            int leftSubstringLen = (split - i + 1);
            int rightSubstringLen = (j - split);

            bool firstOption = scrambleString(s1, s2, i, split, k, dp) && scrambleString(s1, s2, split + 1, j, k + leftSubstringLen, dp);
            bool secondOption = scrambleString(s1, s2, split + 1, j, k, dp) && scrambleString(s1, s2, i, split, k + rightSubstringLen, dp);
            if(firstOption || secondOption) return dp[i][j][k] = true;
        }
        return dp[i][j][k] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (m, -1)));
        return scrambleString(s1, s2, 0, n - 1, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/scramble-string/
Author: M.R.Naganathan
*/
