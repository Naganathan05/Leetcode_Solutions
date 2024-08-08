/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLength = 1;
        vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), 2));
        unordered_map<int, int> mapping;
        for(int i = 0; i <= arr.size() - 1; i++) mapping[arr[i]] = i;
        for(int i = 0; i <= arr.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                int target = arr[i] - arr[prev];
                if(mapping.find(target) != mapping.end() && prev > mapping[target]){
                    dp[i][prev] = max(dp[i][prev], dp[prev][mapping[target]] + 1);
                }
                maxLength = max(maxLength, dp[i][prev]);
            }
        }
        if(maxLength == 2) return 0;
        return maxLength; 
    }
};

/*
Question Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
Author: M.R.Naganathan
*/
