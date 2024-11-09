/*-----------------------------------
  Time Complexity: O(n * n * k)
  Space Complexity: O(n * k) + O(n)
--------------------------------------*/

class Solution {
private:
    int mod = 1e9 + 7;
public:
    bool checkPrime(char c){
        return (c == '2' || c == '3' || c == '5' || c == '7');
    }

    int Partition(string &s, int i, int k, int minLen, vector<vector<int>> &dp){
        if(i == s.length()) return k == 0;
        if(!checkPrime(s[i])) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int totalCount = 0;
        for(int j = i + minLen - 1; j <= s.length() - 1; j++){
            if(checkPrime(s[j])) continue;
            if(s.length() - j + 1 < (k - 1) * minLen) break;
            totalCount = ((totalCount % mod) + (Partition(s, j + 1, k - 1, minLen, dp) % mod)) % mod;
        }
        return dp[i][k] = totalCount;
    }

    int beautifulPartitions(string s, int k, int minLength) {
        vector<vector<int>> dp(s.length(), vector<int> (k + 1, -1));
        return Partition(s, 0, k, minLength, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-beautiful-partitions/
Author: M.R.Naganathan
*/
