/*----------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-------------------------------*/

class Solution {
public:
    int MaxSub(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxLen = 0;
        if(nums1[i] == nums2[j]) maxLen = 1 + MaxSub(nums1, nums2, i + 1, j + 1, dp);
        return dp[i][j] = maxLen;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        int maxLen = 0;
        for(int i = 0; i <= nums1.size() - 1; i++){
            for(int j = 0; j <= nums2.size() - 1; j++){
                int currLen = MaxSub(nums1, nums2, i, j, dp);
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
Author: M.R.Naganathan
*/
