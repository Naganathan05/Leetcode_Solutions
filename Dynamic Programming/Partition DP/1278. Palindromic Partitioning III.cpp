/*-------------------------------
  Time Complexity: O(n * n * k)
  Space Complexity: O(n * k)
----------------------------------*/

class Solution {
public:
    int Partition(string &s, int i, int k, vector<vector<int>> &dp) {
        if (i == s.length()) {
            if (k == 0) return 0;
            return 1e9;
        }
        if (k <= 0) return 1e9;

        if (dp[i][k] != -1) return dp[i][k];

        int minChange = 1e9;
        for (int j = i; j < s.length(); j++) {
            int currChange = getMinChanges(s, i, j);
            minChange = min(minChange, currChange + Partition(s, j + 1, k - 1, dp));
        }
        return dp[i][k] = minChange;
    }

    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(k + 1, -1));
        return Partition(s, 0, k, dp);
    }

    int getMinChanges(string &s, int i, int j) {
        int minChanges = 0;
        while (i < j) {
            minChanges += (s[i] != s[j]);
            i += 1;
            j -= 1;
        }
        return minChanges;
    }
};

/*
Question Link: https://leetcode.com/problems/palindrome-partitioning-iii/
Author: M.R.Naganathan
*/
