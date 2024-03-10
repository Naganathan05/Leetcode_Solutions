/*-----------------------------------------------
Method: Space Optimization
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-------------------------------------------------*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        string text1 = s;
        for(int i = 0; i < (m/2) ; i++){
            swap(s[i], s[m - i - 1]);
        }
        string text2 = s;
        for(int i = 0; i <= m; i++) curr[i] = 0;

        for(int i = 1; i <= m; i++){
            prev = curr;
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        return curr[m];
    }
};

/*
Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/
Author: M.R.Naganathan
*/
