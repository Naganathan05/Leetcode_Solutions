/*---------------------------------------------------
Method: Tabulation
  Time Complexity: O(wordLen * wordLen * numWords)
  Space Complexity: O(wordLen)
-----------------------------------------------------*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numWords = strs.size();
        int wordLen = strs[0].length();
        int minRemovals = wordLen - 1;

        vector<int> dp(wordLen, 1); // Length of longest subsequence of increasing chars across words
        for(int i = 0; i < wordLen; i++) {
            for(int prev = 0; prev < i; prev++) {
                bool removalPossible = false;
                for(int wordInd = 0; wordInd < numWords; wordInd++) {
                    if(strs[wordInd][i] < strs[wordInd][prev]) {
                        removalPossible = true;
                        break;
                    }
                }
                if(removalPossible) continue;
                dp[i] = max(dp[i], dp[prev] + 1);
                minRemovals = min(minRemovals, wordLen - dp[i]);
            }
        }
        return minRemovals;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
Author: M.R.Naganathan
*/
