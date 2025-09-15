/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------*/

class Solution {
public:
    /*
        Index 0 -> Last 1 Even
        Index 1 -> Last 2 Even
        Index 2 -> Last 1 Odd
        Index 3 -> Last 2 Odd
    */
    long long mod = 1000000007;
    int countStableSubsequences(vector<int>& nums) {
        vector<long long> sequenceCounts(4, 0);
        for(int i : nums) {
            if(i % 2 == 0) {
                long long newCount1 = (sequenceCounts[0] + (sequenceCounts[2] + sequenceCounts[3] + 1)) % mod;
                long long newCount2 = (sequenceCounts[1] + sequenceCounts[0]) % mod;
                sequenceCounts[0] = newCount1;
                sequenceCounts[1] = newCount2;
            }
            else {
                long long newCount1 = (sequenceCounts[2] + (sequenceCounts[0] + sequenceCounts[1] + 1)) % mod;
                long long newCount2 = (sequenceCounts[3] + sequenceCounts[2]) % mod;
                sequenceCounts[2] = newCount1;
                sequenceCounts[3] = newCount2;
            }
        }

        long long numStableSequences = (sequenceCounts[0] + sequenceCounts[1] + sequenceCounts[2] + sequenceCounts[3]) % mod;
        return (int) numStableSequences;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-stable-subsequences/
Author: M.R.Naganathan
*/
