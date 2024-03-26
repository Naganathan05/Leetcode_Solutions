/*-------------------------------------------
Method: Back Track LIS
  Time Complexity: O(n * n)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), hash;
        int maxi = -1, max_ele = INT_MIN;
        for(int i = 0; i <= nums.size() - 1; i++) hash.push_back(i);

        for(int i = 0; i <= nums.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(max_ele < dp[i]){
                max_ele = dp[i];
                maxi = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[maxi]);
        while(hash[maxi] != maxi){
            maxi = hash[maxi];
            temp.push_back(nums[maxi]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

/*
Question Link: https://leetcode.com/problems/largest-divisible-subset/
Author: M.R.Naganathan
*/
