/*--------------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------*/

class Solution {
public:
    int Record(int n, int numAbsent, int numLate, vector<vector<vector<int>>> &dp){
        if(n == 0) return 1;

        if(dp[n][numAbsent][numLate] != -1) return dp[n][numAbsent][numLate];

        int result = 0;
        result = (result + Record(n - 1, numAbsent, 0, dp) % 1000000007) % 1000000007;
        if(numAbsent == 0) result = (result + Record(n - 1, numAbsent + 1, 0, dp) % 1000000007) % 1000000007;
        if(numLate < 2) result = (result + Record(n - 1, numAbsent, numLate + 1, dp) % 1000000007) % 1000000007;
        return dp[n][numAbsent][numLate] = result;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));
        return Record(n, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/student-attendance-record-ii/description/
Author: M.R.Naganathan
*/
