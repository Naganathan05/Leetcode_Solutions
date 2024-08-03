/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------*/

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(4, false));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 3; ++k) {
                for (int j = i; j < n; ++j) {
                    if (isPalindrome[i][j] && dp[j + 1][k - 1]) {
                        dp[i][k] = true;
                        break;
                    }
                }
            }
        }
        return dp[0][3];
    }
};

/*
Question Link: https://leetcode.com/problems/palindrome-partitioning-iv/
Author: M.R.Naganathan
*/
