/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    long long Replace(int n, unordered_map<int, int> &dp){
        if(n <= 1) return 0;
        if (n == INT_MAX) return 32;

        if(dp.find(n) != dp.end()) return dp[n];

        long long isEven = 1e9, isOdd = 1e9;
        if(n % 2) isOdd = min((1 + Replace(n - 1, dp)), (1 + Replace(n + 1, dp)));
        else isEven = 1 + Replace(n / 2, dp);
        return dp[n] = min(isEven, isOdd);
    }

    int integerReplacement(int n) {
        unordered_map<int, int> dp;
        return Replace(n, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/integer-replacement/
Author: M.R.Naganathan
*/
