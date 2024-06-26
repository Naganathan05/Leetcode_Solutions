/*-----------------------------------
Method - Memoization  
  Time Complexity: O(n * sum)
  Space Complexity: O(n * sum) + O(n)
--------------------------------------*/

class Solution {
public:
    int dp[2001][4000];
    int TotalReward(vector<int> &nums, int i, int sum){
        if(i == nums.size()) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];

        int Pick = 0, noPick = 0;
        if(nums[i] > sum) Pick = nums[i] + TotalReward(nums, i + 1, sum + nums[i]);
        noPick = TotalReward(nums, i + 1, sum);
        return dp[i][sum] = max(Pick, noPick);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        unordered_set<int> s;
        memset(dp, -1, sizeof(dp));
        for(int i : rewardValues) s.insert(i);
        vector<int> nums;
        for(auto i = s.begin(); i != s.end(); i++) nums.push_back(*i);
        sort(nums.begin(), nums.end());
        return TotalReward(nums, 0, 0);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-total-reward-using-operations-i/
Author: M.R.Naganathan
*/
