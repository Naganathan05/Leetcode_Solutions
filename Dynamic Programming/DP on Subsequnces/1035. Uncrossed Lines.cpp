/*--------------------------------------------
Method: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(max(m, n))
----------------------------------------------*/

class Solution {
public:
    int Cross(vector<int> &nums1, vector<int> nums2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int Pick = 0, noPick = 0;
        if(nums1[i] == nums2[j]) Pick = 1 + Cross(nums1, nums2, i - 1, j - 1, dp);
        noPick = max(Cross(nums1, nums2, i - 1, j, dp), Cross(nums1, nums2, i, j - 1, dp));
        return dp[i][j] = max(Pick, noPick);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        return Cross(nums1, nums2, nums1.size() - 1, nums2.size() - 1, dp);
    }
};

/*-----------------------------------
Method: Tabulation
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
--------------------------------------*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int> (nums2.size() + 1, 0));
        
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                int Pick = 0, noPick = 0;
                if(nums1[i - 1] == nums2[j - 1]) Pick = 1 + dp[i - 1][j - 1];
                noPick = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(Pick, noPick);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};

/*---------------------------------
Method: Space Optimzation
  Time Complexity: O(m * n)
  Space Complexity: O(n)
----------------------------------*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> curr(nums2.size() + 1, 0), prev(nums2.size() + 1, 0);
        
        for(int i = 1; i <= nums1.size(); i++){
            prev = curr;
            for(int j = 1; j <= nums2.size(); j++){
                int Pick = 0, noPick = 0;
                if(nums1[i - 1] == nums2[j - 1]) Pick = 1 + prev[j - 1];
                noPick = max(prev[j], curr[j - 1]);
                curr[j] = max(Pick, noPick);
            }
        }
        return curr[nums2.size()];
    }
};

/*
Question Link: https://leetcode.com/problems/uncrossed-lines/description/
Author: M.R.Naganathan
*/
