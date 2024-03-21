/*----------------------------------------------
Method: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
-------------------------------------------------*/

class Solution {
public:
    int recursion(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -999) return dp[i][j];

        int Take = nums1[i] * nums2[j] + recursion(nums1, nums2, i - 1, j - 1, dp) ;
        int noTake = max(recursion(nums1, nums2, i - 1, j, dp), recursion(nums1, nums2, i, j - 1, dp));
        return dp[i][j] = max(Take, noTake);
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -999));
        int ans = recursion(nums1, nums2, nums1.size() - 1, nums2.size() - 1, dp);

        if(ans == 0){
           sort(nums1.begin(),nums1.end()) ;
           sort(nums2.begin(),nums2.end()) ;

           if(nums1[0] < 0)
              return nums1[nums1.size()-1]*nums2[0] ;
           else
              return nums1[0]*nums2[nums2.size()-1] ;
        }
        return ans ;
    }
};

/*
Question Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
Author: M.R.Naganathan
*/
