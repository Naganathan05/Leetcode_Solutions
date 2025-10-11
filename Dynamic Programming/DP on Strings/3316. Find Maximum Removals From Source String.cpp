/*---------------------------------------
Method: Memoization
  Time Complexity: O(n * m * logn)
  Space Complexity: O(n * m)
n -> Source Length, m -> Pattern Length
-----------------------------------------*/

class Solution {
public:
    // int matchPattern(string &source, string &pattern, int low, int high, int patternInd) {
    //     while(low < high && patternInd < pattern.length()) {
    //         if(source[low] == pattern[patternInd]) patternInd += 1;
    //         low += 1;
    //     }
    //     return patternInd;
    // }

    // int removeString(string &source, string &pattern, int patternInd, int targetInd, vector<int> &targetIndices, vector<vector<int>> &dp) {
    //     if(patternInd == pattern.length()) return (targetIndices.size() - targetInd);
    //     if(targetInd == targetIndices.size() - 1) {
    //         int res = -1e9;
    //         if(matchPattern(source, pattern, targetIndices.back() + 1, source.length(), patternInd) == pattern.length()) res = max(res, 1);
    //         if(matchPattern(source, pattern, targetIndices.back(), source.length(), patternInd) == pattern.length()) res = max(res, 0);
    //         return res;
    //     }

    //     if(dp[patternInd][targetInd] != -1) return dp[patternInd][targetInd];

    //     int nextTargetInd = targetIndices[targetInd + 1];

    //     int firstPatternInd = matchPattern(source, pattern, targetIndices[targetInd] + 1, nextTargetInd, patternInd);
    //     int removeTargetInd = 1 + removeString(source, pattern, firstPatternInd, targetInd + 1, targetIndices, dp);

    //     int secondPatternInd = matchPattern(source, pattern, targetIndices[targetInd], nextTargetInd, patternInd);
    //     int dontRemoveTargetInd = removeString(source, pattern, secondPatternInd, targetInd + 1, targetIndices, dp);

    //     return dp[patternInd][targetInd] = max(removeTargetInd, dontRemoveTargetInd);
    // }

    const int NEG_INF = -1000000000;
    int removeString(string &source, string &pattern, int sourceInd, int patternInd,
                     unordered_set<int> &targetSet, vector<int> &targetIndices, vector<vector<int>> &dp) {

        if (patternInd == pattern.length()) {
            auto it = lower_bound(targetIndices.begin(), targetIndices.end(), sourceInd);
            if (it == targetIndices.end()) return 0;
            int ind = it - targetIndices.begin();
            return targetIndices.size() - ind;
        }

        if (sourceInd == source.length()) return NEG_INF;

        if (dp[sourceInd][patternInd] != -1) return dp[sourceInd][patternInd];

        int maxRemovals = removeString(source, pattern, sourceInd + 1, patternInd, targetSet, targetIndices, dp);

        if (source[sourceInd] == pattern[patternInd]) {
            maxRemovals = max(maxRemovals, removeString(source, pattern, sourceInd + 1, patternInd + 1, targetSet, targetIndices, dp));
        }

        if (targetSet.count(sourceInd)) {
            maxRemovals = max(maxRemovals, 1 + removeString(source, pattern, sourceInd + 1, patternInd, targetSet, targetIndices, dp));
        }

        return dp[sourceInd][patternInd] = maxRemovals;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size();

        unordered_set<int> targetSet(targetIndices.begin(), targetIndices.end());
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int numRemovals = removeString(source, pattern, 0, 0, targetSet, targetIndices, dp);
        return max(0, numRemovals);
    }
};

/*
Question Link: https://leetcode.com/problems/find-maximum-removals-from-source-string/
Author: M.R.Naganathan
*/
