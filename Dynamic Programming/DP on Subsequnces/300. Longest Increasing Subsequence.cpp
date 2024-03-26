/*----------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------------*/

class Solution {
public:
    int recursion(vector<int> &nums, int i, int prevInd, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];

        if(prevInd == -1 || nums[prevInd] < nums[i]){
            return dp[i][prevInd + 1] = max(1 + recursion(nums, i + 1, i, dp), recursion(nums, i + 1, prevInd, dp));
        }
        return dp[i][prevInd + 1] = recursion(nums, i + 1, prevInd, dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        return recursion(nums, 0, -1, dp);
    }
};

/*-----------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
--------------------------------------------------------*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, 0));

        for(int i = nums.size() - 1; i >= 0; i--){
            for(int prevInd = nums.size() - 1; prevInd >= -1; prevInd--){
                int noTake = dp[i + 1][prevInd + 1];
                int take = 0;
                if(prevInd == -1 || nums[prevInd] < nums[i]){
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prevInd + 1] = max(take, noTake); 
            }
        }
        return dp[0][0];
    }
};

/*-----------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * n)
  Space Complexity: O(2*n)
-------------------------------------------------------*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> curr(nums.size() + 1, 0), prev(nums.size() + 1, 0);

        for(int i = nums.size() - 1; i >= 0; i--){
            prev = curr;
            for(int prevInd = nums.size() - 1; prevInd >= -1; prevInd--){
                int noTake = prev[prevInd + 1];
                int take = 0;
                if(prevInd == -1 || nums[prevInd] < nums[i]){
                    take = 1 + prev[i + 1];
                }
                curr[prevInd + 1] = max(take, noTake); 
            }
        }
        return curr[0];
    }
};

/*-----------------------------------------------------
Method 4: Trace Back LIS
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------------*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxi = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

/*-----------------------------------------------------------
Method 5: Binary Search
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------------------------------------*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i <= nums.size() - 1; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp, nums[i]);
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }

    int lower_bound(vector<int> &temp, int target){
        int st = 0, en = temp.size() - 1, mid;
        int ans;
        while(st <= en){
            mid = (st + en)/2;
            if(temp[mid] >= target){
                ans = mid;
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Author: M.R.Naganathan
*/
